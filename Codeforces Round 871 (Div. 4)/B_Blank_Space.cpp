#include<bits/stdc++.h>


int solve(short*& A,int n){
    int l=0;
    int mx=-1;
    for(int i = 0 ; i < n ; ++i){
        if (A[i]==0) l++;
        else l=0;
        mx = std::max(mx, l);
    }
    return mx;
}

int main(){
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);

    int t;
    std::cin>>t;
    while(t--){
        int n;
        std::cin>>n;
        short* A= new short[n];
        for(int i = 0 ; i < n ; ++i) std::cin>>A[i];
        std::cout << solve(A,n) << '\n';
        delete[] A;
    }

    return 0;
}