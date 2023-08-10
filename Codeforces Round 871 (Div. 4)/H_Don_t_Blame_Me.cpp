/*
 *   Problem: https://codeforces.com/contest/1829/problem/H
 */

#include<bits/stdc++.h>

#define FAST std::ios_base::sync_with_stdio(false);std::cin.tie(NULL);std::cout.tie(NULL)

const int MOD = 1e9+7;

int solve(int*& A,int n,int k){
    std::vector<std::vector<int>> dp(n+1,std::vector<int>(64,0));
    for(int i=0;i<=63;++i){
        if(__builtin_popcount(i)==k) dp[0][i]=1;
    }

    for(int i=1;i<=n;++i){
        for(int j=0;j<=63;++j){
            dp[i][j] = (dp[i-1][j&A[i]] + dp[i-1][j]) % MOD;
            //std::cout << i <<","<<j<<"="<<dp[i][j] << '\n';
        }
    }

    return k!=6?dp[n][63]:--dp[n][63];
}


int main(){
    FAST;
    int t;
    std::cin>>t;
    while(t--){
        int n;
        int k;
        std::cin>>n>>k;

        int* A = new int[n+1];
        A[0]=0;
        for(int i=1 ; i<=n ; ++i) std::cin>>A[i];
        std::cout<<solve(A,n,k)<<'\n';
        delete[] A;
    }

    return 0;
}