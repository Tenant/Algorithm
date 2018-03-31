/*
Google Code Jam, Practice Session 2018, Problem A. Number Guessing
Retrieved from https://codejam.withgoogle.com/2018/challenges/0000000000000130/dashboard#!
Finished, By Gao Shuqi, on 2018-03-31.
*/

#include <iostream>
#include<string>
#include<string.h>
using namespace std;

int A, B, N, bottom, top, mid;

int getResponse() {
	string str, correct = "CORRECT", smaller = "TOO_SMALL", bigger = "TOO_BIG", wrong = "WRONG_ANSWER";
	cin >> str;
	if (str == correct) return 0;
	else if (str == smaller) return -1;
	else if (str == bigger) return 1;
	else return -2;
}

int main() {
	int T;
	cin>>T;
	for (int ii = 1; ii <= T; ii++) {
		cin>>A>>B;
		cin>>N;
		int k = 0;
		bottom = A + 1;
		top = B;
		int tmp=0;
		while (++k <= N) {
			if (bottom >= top) cout<<bottom<<endl;
			mid = (top + bottom) / 2;
			cout << mid << endl;
			tmp = getResponse();
			if (tmp == 0) break;
			if (tmp == 1) { top = mid - 1; continue; }
			if (tmp == -1) { bottom = mid + 1; continue; } 
			if (tmp == -2) break;
		}
		if (tmp != 0) break;
	}
	return 0;
}