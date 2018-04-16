/*
Google Code Jam, Round 1B 2017. Problem B. Stable Neigh-bors
Retrieved from https://code.google.com/codejam/contest/8294486/dashboard#s=p1
¹éÄÉ·¨
Completed, By Gao Shuqi, on 2018-03-23.
*/

#include <iostream>
#include <stdio.h>
#include <string.h>
#define N_MAX 1000
using namespace std;

int N, R,O,Y,G,B,V, poc;
char ans[N_MAX];
int visited[N_MAX];
char map[] = { 'R', 'O', 'Y', 'G', 'B', 'V' };

void place(int r, int b, int y, int n) {
	int poc = 0;
	while (r!=0) {
		if (visited[poc]) poc = (poc + 1) % n;
		ans[poc] = 'R';
		visited[poc] = true;
		poc = (poc + 2) % n;
		r--;
	}
	while (b != 0) {
		if (visited[poc]) poc = (poc + 1) % n;
		ans[poc] = 'B';
		visited[poc] = true;
		poc = (poc + 2) % n;
		b--;
	}
	while (y != 0) {
		if (visited[poc]) poc = (poc + 1) % n;
		ans[poc] = 'Y';
		visited[poc] = true;
		poc = (poc + 2) % n;
		y--;
	}
}

int main() {
	//freopen("B-small-practice.in", "r", stdin);
	//freopen("B-small-practice.out", "w", stdout);
	int T;
	scanf("%d", &T);
	for (int ii = 1; ii <= T; ii++) {
		scanf("%d%d%d%d%d%d%d", &N, &R, &O, &Y, &G, &B, &V);
		memset(visited, 0, sizeof(visited));
		bool flag=true;
		if ((N + 1) / 2 < R || (N + 1) / 2 < Y || (N + 1) / 2 < B) flag = false;
		else if ((((O + B) == N) && B != O) || (((O + N) < N) && B <= O && O!=0)) flag = false;
		else if ((((G + R) == N) && G != R) || (((G + R) < N) && R <= G && G!=0)) flag = false;
		else if ((((V + Y) == N) && V != Y) || (((V + Y) < N) && Y <= V && V!=0)) flag = false;
		else if ((O + B) == N) {
			for (int i = 0; i < N - 1; i += 2) { ans[i] = 'O'; ans[i + 1] = 'B'; }
			O = 0;
		}
		else if ((G + R) == N) {
			for (int i = 0; i < N - 1; i += 2) { ans[i] = 'G'; ans[i + 1] = 'R'; }
			G = 0;
		}
		else if ((V + Y) == N) {
			for (int i = 0; i < N - 1; i += 2) { ans[i] = 'V'; ans[i + 1] = 'Y'; }
			V = 0;
		}
		else {
			R = R - G;
			B = B - O;
			Y = Y - V;
			N = R + B + Y;
			place(R, B, Y, N);
		}
		if (!flag) printf("Case #%d: IMPOSSIBLE\n", ii);
		else {
			printf("Case #%d: ", ii);
			for (int i = 0; i < N; i++) {
				if (ans[i] == 'R' && G != 0) {
					for (int k = 0; k < G; k++) printf("RG");
					G = 0;
				}
				if (ans[i] == 'B' && O != 0) {
					for (int k = 0; k < G; k++) printf("BO");
					O = 0;
				}
				if (ans[i] == 'Y' && V != 0) {
					for (int k = 0; k < V; k++) printf("YV");
					V = 0;
				}
				printf("%c", ans[i]);
			}
			printf("\n");
		}
	}
	//fclose(stdin);
	//fclose(stdout);
	return 0;
}