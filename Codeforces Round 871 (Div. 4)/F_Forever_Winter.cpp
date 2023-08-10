#include<bits/stdc++.h>

#define FAST std::ios_base::sync_with_stdio(false);std::cin.tie(NULL);std::cout.tie(NULL)

void solve(int n, int m){
    std::unordered_map<int,int> counts;
    for(int i = 1 ; i <= n ; ++i) counts[i]=0;

    for(int i = 1 ; i <= m ; ++i){
        int u,v;
        std::cin>>u>>v;
        counts[u]++;
        counts[v]++;
    }

    std::unordered_map<int,int> counts1;
    for(int i = 1 ; i <= n ; ++i){
        counts1[counts[i]]++;
    }

    std::vector<int> v;
    for(auto p: counts1) v.push_back(p.second);
        
    sort(v.begin(),v.end());

    if (v.size() == 3) std::cout << v[1] << " " << v[2]/v[1] << '\n';
    else std::cout << v[0]-1 <<" " <<v[1]/(v[0]-1) << '\n';
}

int main(){
    FAST;

    int t;
    std::cin>>t;
    while(t--){
        int n,m;
        std::cin>>n>>m;
        solve(n,m);
    }

    return 0;
}