/*
Google Code Jam, Round 1A 2017, Problem A. Alphabet Cake
Retrieved from https://code.google.com/codejam/contest/5304486/dashboard
Completed, By Gao Shuqi, on 2018-04-06
*/

#include <iostream>
#include <stdio.h>
#define N_MAX 25
using namespace std;

char map[N_MAX + 1][N_MAX + 1];
bool visited[N_MAX + 1][N_MAX + 1];
int R, C;

void deal(int x, int y) {
	int left = y-1;
	for (; left >= 1 && map[x][left] == '?' && !visited[x][left]; left--);
	left++;
	int top = x-1;
	for (; top >= 1 && map[top][0] == '0'; top--);
	top++;
	int right = y+1;
	bool tm = true;
	while (tm && right<=C) {
		bool tm1 = true;
		for (int i = top; right<C && i <= x; i++) {
			if (visited[i][right] || map[i][right] != '?') { tm1 = false; break;}
		}
		if (tm1) right++;
		else tm = false;
	}
	if(!tm) right--;
	tm = true;
	for (int i = x + 1; i <= R; i++) {
		if (map[i][0] != '0') { tm = false; break; }
	}
	int bottom = tm ? C : x;
	for (int i = top; i <= bottom; i++) {
		for (int j = left; j <= right; j++) {
			map[i][j] = map[x][y];
			visited[i][j] = true;
		}
	}
	
}

int main() {
	//freopen("A-small-practice.in", "r", stdin);
	//freopen("A-small-practice.out", "w", stdout);
	int T;
	scanf("%d", &T);
	for (int ii = 1; ii <= T; ii++) {
		scanf("%d%d", &R, &C);
		getchar();
		for (int i = 1; i <= R; i++) {
			char str[N_MAX + 1];
			gets(str);
			int tmp = 0;
			for (int j = 1; j <= C; j++) {
				map[i][j] = str[j - 1];
				if (str[j - 1] != '?') tmp++;
			}
			map[i][0] = '0' + tmp;
		}
		memset(visited, 0, sizeof(visited));
		for (int i = 1; i <= R; i++) {
			for (int j = 1; j <= C; j++) {
				if (map[i][j] != '?') deal(i, j);
			}
		}

		printf("Case #%d:\n", ii);
		for (int i = 1; i <= R; i++) {
			for (int j = 1; j <= C; j++)
				printf("%c", map[i][j]);
			printf("\n");
		}
	}
	//fclose(stdin);
	//fclose(stdout);
	return 0;
}