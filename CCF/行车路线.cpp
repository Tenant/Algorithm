/*
CCF 201712-4, 行车路线
Retrieved from http://118.190.20.162/view.page?gpid=T65
Finished, by Gao Shuqi, on 2018-03-30
*/

#include<stdio.h>
#include <vector>
using namespace std;
struct Edge{
	int end;
	int type;
	int dist;
};
vector<Edge> edge[501];
int dist[501];
bool determined[501];
int t0[501], d0[501];
int N, M;

int main() {
	scanf("%d%d", &N, &M);
	for (int i = 1; i <= N; i++) {
		if (!edge[i].empty()) edge[i].clear();
	}
	memset(dist, -1, sizeof(dist));
	memset(determined, 0, sizeof(determined));
	memset(t0, 0, sizeof(t0));
	memset(d0, 0, sizeof(d0));
	for (int i = 0; i < M; i++) {
		int t, a, b, c;
		scanf("%d%d%d%d", &t, &a, &b, &c);
		Edge tmp;
		tmp.type = t;
		tmp.dist = c;
		tmp.end = b;
		edge[a].push_back(tmp);
		tmp.end = a;
		edge[b].push_back(tmp);
	}
	int frontier = 1;
	dist[1] = 0;
	determined[1] = true;
	for (int i = 1; i < N; i++) {
		for (int j = 0; j < edge[frontier].size(); j++) {
			int b = edge[frontier][j].end;
			int c = edge[frontier][j].dist;
			int t = edge[frontier][j].type;
			if (determined[b]) continue;
			if (t0[frontier] == 0 && (dist[b] == -1 || (dist[b]>dist[frontier] + (1 - t)*c + t*c*c))) {
				dist[b] = dist[frontier] + (1 - t)*c + t*c*c;
				t0[b] = t;
				d0[b] = c*t;
			}
			if (t0[frontier] == 1 && (dist[b] == -1 || (dist[b] > (1-t)*dist[frontier] + (1 - t)*c + t*(dist[frontier] - d0[frontier] * d0[frontier] + (d0[frontier] + c)*(d0[frontier] + c))))) {
				dist[b] = (1-t)*dist[frontier] + (1 - t)*c + t*(dist[frontier] - d0[frontier] * d0[frontier] + (d0[frontier] + c)*(d0[frontier] + c));
				t0[b] = t;
				if (t == 1) d0[b] = d0[frontier] + c;
			}
		}
	int minium = 0x7fffffff, pos = 0;
	for (int j = 1; j <= N; j++) {
		if (determined[j] || dist[j] == -1) continue;
		if (dist[j] < minium) { pos = j; minium = dist[j]; }
	}
	frontier = pos;
	determined[pos] = true;
}
	printf("%d\n", dist[N]);
	return 0;
}