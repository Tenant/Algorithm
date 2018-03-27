/*
Tongji Open Judge, 网络赛 2017, Problem C. 硬币翻转
Retrieved from http://acm.tongji.edu.cn/problem.php?cid=1001&pid=2
Finished, By Gao Shuqi, on 2018-03-26.
*/

#include <iostream>
#include <queue>
using namespace std;
long long Min(long a, long b) { return (a < b) ? a : b; }

struct E{
	long long num;
	int dist;
};

int main() {
	long long N, M, K;
	scanf("%lld%lld%lld", &N, &M, &K);
	int cnt;
	if (K == 1) cnt = Min(N, M);
	else if (M%K == 0 && N%K != 0) cnt = M / K;
	else if (M%K != 0 && N%K == 0) cnt = N / K;
	else if (M%K == 0 && N%K == 0) cnt = Min(M, N) / K;
	else {//Breadth First Search
		long long Total = N + M;
		queue<E> q;
		while (!q.empty()) q.pop();
		E tmp;
		tmp.num = N;
		tmp.dist = 0;
		q.push(tmp);
		while (q.front().num != 0 && q.front().num != Total) {
			long long tmp_n = q.front().num;
			int tmp_d = q.front().dist;
			q.pop();
			for (int i = 0; i <= K; i++) {
				tmp.num = tmp_n + i - (K - i);
				tmp.dist = tmp_d + 1;
				q.push(tmp);
			}
		}
		cnt = q.front().dist;
	}
	
	printf("%d\n", cnt);
	//getchar();
	//getchar();
	return 0;
}