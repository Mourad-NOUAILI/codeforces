#include<bits/stdc++.h>


int solve(std::string s){
    std::string ts = "codeforces";
    int cnt=0;
    for(int i = 0 ; i < 10 ; ++i){
        if (s[i] != ts[i]) cnt++;
    }
    return cnt;
}

int main(){
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);

    int t;
    std::cin>>t;
    while(t--){
        std::string s;
        std::cin>>s;
        std::cout << solve(s) << '\n';
    }

    return 0;
}