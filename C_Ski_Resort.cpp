#include<bits/stdc++.h>
 
typedef double ll;
 

ll solve (std::vector<ll>& A, ll k, ll q){
    ll ans=0;
    A.push_back(q+1);
    ll l=0;
    for (auto ai: A){
        if (ai <= q) l++;
        else {
            if (l >= k) ans += (l-k+2)*(l-k+1)/(2*1ll);
            l=0;
        } 
    }
 
    return ans;
}
 
int main(){
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);
 
    ll t;
    std::cin>>t;
 
    while(t--){
        ll n,k;
        ll q;
        std::cin>>n>>k>>q;
        std::vector<ll> A;
        for(ll i = 1 ; i <= n ; ++i) {
            ll x;
            std::cin>>x;
            A.push_back(x);
        }
        std::cout << std::fixed;
        std::cout << std::setprecision(0);
        std::cout << solve(A,k,q) << '\n';
    }
 
    return 0;
}