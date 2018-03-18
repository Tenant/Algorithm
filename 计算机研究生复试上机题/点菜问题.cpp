/*
计算机研究生复试上机题，北京大学
Retrieved from 
Solved by Gao Shuqi, on 2018-03-16
*/

#include <iostream>
using namespace std;

struct Dish{
	int value;
	int cost;
}dish[101];

int Max(int a, int b) { return (a > b) ? a : b; }

int main() {
	int V, N;
	int dp[101][1001];
	while (scanf("%d%d", &V, &N) != EOF) {
		for (int i = 1; i <= N; i++)
			cin >> dish[i].cost >> dish[i].value;
		for (int i = 0; i <= V; i++) dp[0][i] = 0;
		for (int i = 1; i <= N; i++) {
			for (int j = V; j >= dish[i].cost; j--) {
				dp[i][j] = Max(dp[i - 1][j], dp[i - 1][j - dish[i].cost] + dish[i].value);
			}
			for (int j = dish[i].cost - 1; j >= 0; j--) {
				dp[i][j] = dp[i - 1][j];
			}
		}
		cout << dp[N][V] << endl;
	}
	return 0;
}