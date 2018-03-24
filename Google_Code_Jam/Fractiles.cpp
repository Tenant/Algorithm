/*
Google Code Jam, Qualification Round 2016, Problem D. Fractiles
Retrieved from https://code.google.com/codejam/contest/6254486/dashboard#s=p3
By Gao Shuqi, on 2018-03-24.
*/

#include <iostream>
#include <stdio.h>
#include <math.h>
using namespace std;

int main() {

	freopen("D-small-practice.in", "r", stdin);
	freopen("D-small-practice.out", "w", stdout);
	int T;
	scanf("%d", &T);
	for (int ii = 1; ii <= T; ii++) {
		int K, C, S;
		scanf("%d %d %d", &K, &C, &S);
		if (C == 1) {
			if (S >= K) {
				printf("Case #%d:", ii);
				for (int i = 1; i <= K; i++) printf(" %d", i);
				printf("\n");
				continue;
			}
			else {
				printf("Case #%d: IMPOSSIBLE\n", ii);
				continue;
			}
		}
		else {
			if (S*C<K) {
				printf("Case #%d: IMPOSSIBLE\n", ii);
				continue;
			}
			printf("Case #%d:", ii);
			long long pos = 1;
			for (int i = 1; i <= C; i++) pos = pos + (i - 1)*pow(K, C - i);
			for (int i = 0; i <(K+C)/C; i++) {
				long long tmp = pos+i*pow(K, C-1)+i;
				if (tmp>pow(K, C)) tmp = pow(K, C);
				printf(" %lld", tmp);
			}
			printf("\n");
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}