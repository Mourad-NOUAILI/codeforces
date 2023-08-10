#include<bits/stdc++.h>

typedef long long ll;
typedef std::unordered_map<std::string,ll> sll;

int main(){
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);

    int t;
    std::cin>>t;
    while(t--){
        ll n;
        std::cin>>n;

        ll INF = 1e10;
        sll mins = {{"01",INF},{"10",INF},{"11",INF}};

        for(int i = 0 ; i < n ; ++i) {
            ll m;
            std::string s;
            std::cin>>m>>s;
            if (s!="00") mins[s] = std::min(mins[s],m);
        }
        
        ll ans = std::min(mins["01"]+mins["10"],mins["11"]);
        ans>=INF?std::cout<<"-1\n":std::cout<<ans<<'\n';
    }

    return 0;
}