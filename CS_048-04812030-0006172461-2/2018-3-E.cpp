//
// Created by Dell on 11/18/2018.
//
#include <iostream>
#define N_MAX 100000
using namespace std;

int stock_purchage(int *data, int length){
    int profit = 0;
    int dp_low[N_MAX], dp_high[N_MAX];
    dp_low[0]=data[0];
    dp_high[0]=data[0];
    for(int idx=1;idx<N;idx++){

    }


    return profit;
}

int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        int N;
        scanf("%d",&N);
        int prices[N_MAX];
        for(int idx=0;idx<N;idx++) scanf("%d",&prices[idx]);
        int answer=stock_purchage(prices,N);
        printf("%d\n",answer);
    }
    return 0;
}
