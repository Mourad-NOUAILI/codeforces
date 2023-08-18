#include<bits/stdc++.h>
 
#define FAST std::ios_base::sync_with_stdio(false);std::cin.tie(NULL);std::cout.tie(NULL)
#define limit 64
const int MOD = 1e9+7;
 
int solve(int*& A,int n,int k){
    int ans=0;
    int m = 1 << n;
    for (int i = 1 ; i < m ; ++i) {
        int cnt=0;
        int s=0;
        for (int j = 0 ; j < n ; ++j) {
            if ( (i & (1 << j)) != 0 ) {
                //std::cout<<A[j] <<",",
                (cnt==0)?s=A[j]:s&=A[j];
                cnt++;
            }
        }
        //std::cout<< "=" << s <<'\n';
        if(__builtin_popcount(s)==k) ans++;
    }
    return ans;
}
 
 
int main(){
    FAST;
    int t;
    std::cin>>t;
    while(t--){
        int n;
        int k;
        std::cin>>n>>k;
 
        int* A = new int[n];
        for(int i=0 ; i<n ; ++i) std::cin>>A[i];
        std::cout<<solve(A,n,k)<<'\n';
        delete[] A;
    }
 
    return 0;
}