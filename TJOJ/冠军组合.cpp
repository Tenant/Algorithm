/*
Tongji Open Judge, 网络赛 2017, Problem E. 冠军组合
Retrieved from http://acm.tongji.edu.cn/problem.php?cid=1001&pid=4
Finished, By Gao Shuqi, on 2018-03-26.
*/

#include <iostream>
#include <math.h>
using namespace std;
int N, c, d,cnt=0;
int T[3000], S[3000];

int main() {
	scanf("%d%d%d", &N, &c, &d);
	for (int i = 1; i <= N; i++) scanf("%d%d", &T[i], &S[i]);
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (j == i) continue;
			if ((T[i] - c)*(S[j] - d) <= (T[j] - c)*(S[i] - d)) continue;
			for (int k = 1; k <= N; k++) {
				if (k == i || k == j) continue;
				if ((T[j] - c)*(S[k] - d) <= (T[k] - c)*(S[j] - d)) continue;
				if ((T[k] - c)*(S[i] - d) <= (T[i] - c)*(S[k] - d)) continue;
				cnt++;
			}
		}
	}
	cnt /= 3;
	printf("%d\n", cnt);
	//getchar();
	//getchar();
	return 0;
}
