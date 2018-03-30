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

struct Node{
	int name;
	int dist;
};
queue<int> child[100001];
long long value[100001];
bool visited[100001];
int N, pos;

long long cal(int d) {
	if (visited[d]) return value[d];
	if (child[d].empty()) { value[d] = 0; visited[d] = true; return 0; }
	int length = child[d].size();
	queue<Node> posterior;
	while (!posterior.empty()) posterior.pop();
	for (int i = 0; i < length; i++) {
		int tmp_d = child[d].front();
		child[d].pop();
		child[d].push(tmp_d);
		Node tmp_N;;
		tmp_N.name = tmp_d;
		tmp_N.dist = tree[tmp_d].dist;
		posterior.push(tmp_N);
	}
	long long maxium = 0;
	while (!posterior.empty()) {
		Node tmp = posterior.front();
		posterior.pop();
		if (!child[tmp.name].empty()) {
			int length = child[tmp.name].size();
			for (int i = 0; i < length; i++) {
				int tmp_d = child[tmp.name].front();
				child[tmp.name].pop();
				child[tmp.name].push(tmp_d);
				Node tmp_N;;
				tmp_N.name = tmp_d;
				tmp_N.dist = tree[tmp_d].dist+tmp.dist;
				posterior.push(tmp_N);
			}
		}
		long long tmp_ans = tree[d].data.v - (tree[d].data.f - tmp.dist)*((tree[d].data.f - tmp.dist));
		tmp_ans %= 1000000000000000000;
		tmp_ans += cal(tmp.name);
		tmp_ans %= 1000000000000000000;
		if (tmp_ans > maxium) maxium = tmp_ans;
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