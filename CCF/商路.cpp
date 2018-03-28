/*
CCF 201712-5, 商路
Retrieved from http://118.190.20.162/view.page?gpid=T64
Finished, by Gao Shuqi, on 2018-03-28
*/

# include <iostream>
#include <stdio.h>
#include <queue>
using namespace std;

struct City{
	long long v;
	long long f;
};
struct Tree{
	City data;
	int parent;
	int dist;
}tree[100001];
queue<int> child[100001];
long long value[100001];
bool visited[100001];
int N, pos;

long long cal(int d) {
	if (visited[d]) return value[d];
	if (child[d].empty()) { value[d] = 0; visited[d] = true; return 0; }
	int length = child[d].size();
	long long maxium = 0xffffffff;
	for (int i = 1; i <= length; i++) {
		int p = child[d].front();
		child[d].pop();
		int dist_base = 0;

		long long tmp = tree[d].data.v - (tree[d].data.f - tree[p].dist)*((tree[d].data.f - tree[p].dist));
		tmp %= 1000000000000000000;
		tmp += cal(p);
		tmp %= 1000000000000000000;
		if (tmp > maxium) maxium = tmp;
	}
	value[d] = maxium;
	visited[d] = true;
	return maxium;
}

int main(){
	int T;
	scanf("%d", &T);
	for (int ii = 1; ii <= T; ii++) {
		pos = 0;
		scanf("%d", &N);
		for (int i = 1; i <= N; i++) {
			visited[i] = false;
			while (!child[i].empty()) child[i].pop();
		}
		for (int i = 1;i <= N; i++) {
			Tree tmp;
			scanf("%d%d%lld%lld", &tmp.parent, &tmp.dist, &tmp.data.v, &tmp.data.f);
			tree[++pos] = tmp;
			child[tmp.parent].push(i);
		}
		long long ans=0;
		for (int i = 1; i <= N; i++) {
			if (child[i].empty()) continue;
			ans += cal(i);
			ans %= 1000000000000000000;
		}
		printf("%lld\n", ans);
	}
	return 0;
}