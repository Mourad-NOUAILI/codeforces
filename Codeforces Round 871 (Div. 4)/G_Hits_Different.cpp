#include<bits/stdc++.h>

#define FAST std::ios_base::sync_with_stdio(false);std::cin.tie(NULL);std::cout.tie(NULL)
#define NB_ROWS 2023

typedef unsigned long long ull;
typedef std::vector<std::vector<ull>> vvull;

vvull pre(NB_ROWS+1,std::vector<ull>(NB_ROWS+1,0));

std::unordered_map<ull,ull> answers;

void build_prefix(){
    ull v=0;
    for(ull i=1 ; i<=NB_ROWS ; ++i){
        for(ull j=1; j<=NB_ROWS ; ++j){
            ull diag=i+j-1;
            ull x=diag*(diag+1)/2-v;
            pre[i][j]=pre[i-1][j]+pre[i][j-1]-pre[i-1][j-1]+x*x;
            answers[x]=pre[i][j];
        }
        v++;
    }
}

int main(){
    FAST;

    build_prefix();

    int t;
    std::cin>>t;
    while(t--){
        ull n;
        std::cin>>n;
        std::cout << answers[n] << '\n';
    }

    return 0;
}