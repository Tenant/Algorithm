/*
Google Code Jam, Qualification Round 2016, Problem B. Revenge of the Pancakes
Retrieved from https://code.google.com/codejam/contest/6254486/dashboard#s=p1
By Gao Shuqi, on 2018-03-23.
*/

#include <iostream>
#include <stdio.h>
using namespace std;

char str[101];
int N;
int num_plus, cnt ;

char inverse(char c) { return (c == '+' )? '-' : '+'; }

void flip(int d) { 
	char tmp[101];
	for (int i = 0; i < d; i++) tmp[i] = inverse(str[d - 1 - i]);
	for (int i = 0; i < d; i++) str[i] = tmp[i];
}

int findBlank() {
	int tmp = N - 1;
	for (; tmp>=0 && str[tmp] == '+' ; tmp--);
	return tmp;
}

int main() {

	freopen("B-small-practice.in", "r", stdin);
	freopen("B-small-practice.out", "w", stdout);
	int T;
	scanf("%d\n", &T);
	for (int ii = 1; ii <= T; ii++) {
		scanf("%s\n", str);
		N = strlen(str);
		num_plus = 0;
		cnt = 0;
		for (int i = 0; i<N; i++) {
			if (str[i] == '+') num_plus++;
		}
		if (num_plus == 0) {
			printf("Case #%d: %d\n", ii, 1);
			continue;
		}
		if (2*num_plus<N) { flip(N); cnt++; }
		int pos = findBlank();
		while (pos > 0) {
			if (str[0] == '+') { str[0] = '-'; cnt++; }
			flip(pos + 1);
			cnt++;
			pos = findBlank();
		}
		if (pos == 0) cnt++;
		printf("Case #%d: %d\n", ii, cnt);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}