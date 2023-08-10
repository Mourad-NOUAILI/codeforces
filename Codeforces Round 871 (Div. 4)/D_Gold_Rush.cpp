#include<bits/stdc++.h>

typedef long long ll;

bool solve(ll n, ll m, std::unordered_map<ll,bool>& memo){
    if (n==m) return true;
    if (memo.find(n) != memo.end()) return memo[n];
    if (n < m || n % 3 != 0) return false;
    ll y = n/3;
    ll x = n-y;
    memo[x] = solve(x,m,memo);
    memo[y] = solve(y,m,memo);
    return memo[x] || memo[y];
}

int main(){
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);

    int t;
    std::cin>>t;

    while(t--){
        ll n,m;
        std::cin>>n>>m;
        std::unordered_map<ll,bool> memo;
        bool check = solve(n,m,memo);
        check?std::cout<<"YES\n":std::cout<<"NO\n";
    }

    return 0;
}