/*
	CCF 201712-1, 最小差值
	Retrieved from http://118.190.20.162/view.page?gpid=T68
	Finished, by Gao Shuqi, on 2018-03-28
*/

#include <iostream>
#include <algorithm>
#include <math.h>
using namespace std;

int main() {
	int N;
	int data[1000];
	scanf("%d", &N);
	for (int i = 0; i < N; i++) scanf("%d", &data[i]);
	sort(data, data + N);
	int minium = 0x7fffffff;
	for (int i = 1; i < N; i++) {
		int tmp = abs(data[i - 1] - data[i]);
		if (tmp < minium) minium = tmp;
	}
	cout << minium << endl;
	return 0;
}