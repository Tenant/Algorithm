#include <iostream>
#include <vector>
#include <string.h>
#define N_MAX 10
using namespace std;

struct Dot{
	int end;
};

vector<Dot> dot[N_MAX + 1];
int color[N_MAX + 1],depth, cnt, ans;
int n, m;
bool visited[N_MAX + 1];

void cal(int d) {
	for (int i = 1; i <= 4; i++) {
		bool accessible = true;
		for (int j = 0; j <= dot[d].size(); j++) {
			if (color[dot[d][j].end] == i) { accessible = false; break; }
		}
		if (!accessible) continue;
		color[d] = i;
		depth++;
		if (depth == n) { cnt++; continue; }
		for (int j = 0; j <= dot[d].size(); j++) {
			if (color[dot[d][j].end] != 0) continue;
			visited[dot[d][j].end] = true;
			cal(dot[d][j].end);

		}
	}
	depth--;
}

int main() {
	scanf("%d%d", &n, &m);
	for (int i = 0; i < m; i++) {
		int a, b;
		scanf("%d%d", &a, &b);
		Dot tmp;
		tmp.end = a;
		dot[b].push_back(tmp);
		tmp.end = b;
		dot[a].push_back(tmp);
	}
	ans = 1;
	for (int i = 1; i <= n; i++) {
		if (visited[i]) continue;
		visited[i] = true;
		cnt = 0;
		depth = 0;
		cal(i);
		ans *= cnt;
	}
	printf("%d\n", ans);
	return 0;
}