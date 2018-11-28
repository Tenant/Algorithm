//
// Created by Sukie on 11/18/2018.
//
#include <iostream>
#include <algorithm>
#include <cmath>
#define N_MAX 1000

using namespace std;

class Point2d{
public:
	int x;
	int y;
};

bool compare_X(Point2d a, Point2d b){
	return a.x < b.x;
}

bool compare_Y(Point2d a, Point2d b){
	return a.y < b.y;
}

Point2d points[N_MAX];


double closest_pair(Point2d* data, int length){
	if (length == 1) return -1;
	if (length == 2) {
		if (data[0].y>data[1].y){
			Point2d temp_point;
			temp_point = data[0];
			data[0] = data[1];
			data[1] = temp_point;
		}
		return sqrt((data[0].x - data[1].x)*(data[0].x - data[1].x) + (data[0].y - data[1].y)*(data[0].y - data[1].y));
	}
	double sigma1 = closest_pair(data, length / 2);
	double sigma2 = closest_pair(data + length / 2, length - length / 2);
	double sigma;
	if (sigma1 == -1) sigma = sigma2;
	else if (sigma2 == -1) sigma = sigma1;
	else sigma = (sigma1>sigma2) ? sigma2 : sigma1;
	double L = (data[length / 2 - 1].x + data[length / 2].x) / 2.;
	Point2d localpoints[N_MAX];
	int local_cnt = 0;
	int i=0, j=length/2;
	for (; i < length / 2 && j < length;){
		if (data[i].y <= data[j].y) localpoints[local_cnt++] = data[i++];
		else localpoints[local_cnt++] = data[j++];
	}
	if (i<length/2)
	for (; i < length / 2;)
		localpoints[local_cnt++] = data[i++];
	else
	for (; j < length;)
		localpoints[local_cnt++] = data[j++];
	data = localpoints;
	for (int idx = 0; idx<length; idx++){
		if (abs(localpoints[idx].x - L)>=sigma) continue;
		for (int p = idx + 1; p < idx + 7 && p < length; p++){
			double temp_dist = sqrt((data[idx].x - data[p].x)*(data[idx].x - data[p].x) + (data[idx].y - data[p].y)*(data[idx].y - data[p].y));
			if (temp_dist < sigma) sigma = temp_dist;
		}
	}
	return sigma;

}


int main(){
	int T;
	scanf("%d", &T);
	while (T--){
		int N;
		scanf("%d", &N);
		for (int idx = 0; idx<N; idx++) scanf("%d%d", &points[idx].x, &points[idx].y);
		sort(points, points + N, compare_X);
		double answer = closest_pair(points, N);
		printf("%.6f\n", answer);
	}
	return 0;
}
