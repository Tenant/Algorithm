#include <iostream>
#include <cstring>

#define N_MAX 100001
using namespace std;



bool visited[N_MAX];
int cost[N_MAX];

/* Dynamic Processing */
int catchCows_dp(int person, int cow){
    memset(visited,0,sizeof(visited));
    memset(cost,-1,sizeof(cost));

    cost[person] = 0;
    visited[person] = true;

    bool finished=false;
    while(!finished)
    {
        finished=true;
        for(int idx=0; idx<N_MAX; idx++){
            if(!visited[idx]) {finished=false;continue;}
            if(idx!=0 ) {if(cost[idx-1]==-1 || cost[idx-1]>cost[idx]+1) cost[idx-1]=cost[idx]+1;visited[idx-1]=true;}
            if(idx!=N_MAX ) {if(cost[idx+1]==-1 || cost[idx+1]>cost[idx]+1) cost[idx+1]=cost[idx]+1;visited[idx+1]=true;}
            if(idx * 2 <= N_MAX ) {if(cost[idx*2] == -1 || cost[idx*2]>cost[idx]+1) cost[idx * 2] = cost[idx] + 1; visited[idx * 2] = true;}
        }
    }

    printf("%d\n", cost[cow]);
}

/* Breadth-First e */

int main(){
    int N, K;
    cin>>N>>K;
    catchCows_dp(N,K);
}
