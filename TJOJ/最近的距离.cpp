/*
Tongji Open Judge, ÍøÂçÈü 2017, Problem B. ×î½üµÄ¾àÀë
Retrieved from http://acm.tongji.edu.cn/contest.php?cid=1002
Finished, By Gao Shuqi, on 2018-03-26.
*/

#include <iostream>
#include <math.h>
using namespace std;

double x1, y01, dx1, dy1, x2, y2, dx2, dy2;
double getDistant(double t) {
	double X01 = x1 + t*dx1;
	double Y01 = y01 + t*dy1;
	double X02 = x2 + t*dx2;
	double Y02 = y2 + t*dy2;
	return sqrt((X01 - X02)*(X01 - X02) + (Y01 - Y02)*(Y01 - Y02));
}

int getSlope(double t) {
	double tmp = getDistant(t + 1e-10) - getDistant(t);
	if (tmp > 0) return 1;
	else if (tmp == 0) return 0;
	else return -1;
}

int main() {
	cin >> x1 >> y01 >> dx1 >> dy1 >> x2 >> y2 >> dx2 >> dy2;
	double low = 0.0, mid = 10.0, high = 20.0;
	double d_low = getDistant(low);
	double d_mid = getDistant(mid);
	double d_high = getDistant(high);
	int s_low = getSlope(low);
	int s_mid = getSlope(mid);
	int s_high = getSlope(high);
	while (abs(d_high - d_low ) >= 1e-10) {
		if (s_low=-1 && s_mid==-1 && s_high==1) {
			low = mid;
			mid = (high + low) / 2;
		}
		else if (s_low = -1 && s_mid == -1 && s_high == -1) {
			low = mid;
			mid = high;
			high = low + high;
		}
		else if (s_low = -1 && s_mid == -1 && s_high == -1) {
			low = mid;
			mid = high;
			high = low + high;
		}
		else if (s_low = -1 && s_mid == 1 && s_high == 1) {
			high = mid;
			mid = (high + low) / 2;
		}
		else if (s_low = 1 && s_mid == 1 && s_high == 1) {
			high=mid;
			mid =low;
			low = low - (high - mid);
		}
		else {
			if (s_low == 0) {mid = low; break;}
			if (s_high == 0) { mid = high; break; }
			if (s_mid == 0) { break; }
		}
		 d_low = getDistant(low);
		d_mid = getDistant(mid);
		d_high = getDistant(high);
		s_low = getSlope(low);
		s_mid = getSlope(mid);
		s_high = getSlope(high);
	}

	printf("%.9f", getDistant(mid));
	return 0;
}
