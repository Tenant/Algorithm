/*
挑战编程 程序设计竞赛训练手册，8.4 八皇后问题
回溯法
Finished, By Gao Shuqi, on 2018-04-02
*/

#include <stdio.h>
#include <string.h>
#define N_MAX 100
using namespace std;
int N; /*N<=M_MAX*/
long long cnt;
bool occupied[N_MAX+1][N_MAX+1], col[N_MAX+1], row[N_MAX+1], diag[3];

void visit(int d) {
	for (int i = 1; i <= N; i++) {
		if (row[i]) continue;
		for (int j = 1; j <= N; j++) {
			if (occupied[i][j] || col[j]) continue;
			if (row[i]) break;
			if (i == j && diag[1]) continue;
			if (i + j == N + 1 && diag[2]) continue;
			occupied[i][j] = col[j] = row[i] = true;
			if (i == j) diag[1] = true;
			if (i + j == N + 1) diag[2] = true;
			if (d == N) cnt++;
			else visit(d+1);
			occupied[i][j] = col[j] = row[i] = false;
			if (i == j) diag[1] = false;
			if (i + j == N + 1) diag[2] = false;
		}
	}
}

int main() {
	int T;
	scanf("%d", &T);
	for (int ii = 1; ii <= T; ii++) {
		memset(occupied, 0, sizeof(occupied));
		memset(col, 0, sizeof(col));
		memset(row, 0, sizeof(row));
		memset(diag, 0, sizeof(diag));
		scanf("%d", &N);
		cnt = 0;
		visit(1);
		printf("Case #%d: %lld\n", ii, cnt);
	}
	return 0;
}