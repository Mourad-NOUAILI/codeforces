#include<bits/stdc++.h>

#define FAST std::ios_base::sync_with_stdio(false);std::cin.tie(NULL);std::cout.tie(NULL)
#define NB_ROWS 2023
#define NB_NODES (NB_ROWS*(NB_ROWS+1))/2

typedef unsigned long long ull;

std::vector<ull>* graph=nullptr;
ull* memo=nullptr;

void build_graph(){
    std::vector<ull> prev;
    prev.push_back(1);
    ull v=2;
    for(ull i = 2 ; i <= NB_ROWS ; ++i){
        std::vector<ull>cur;
        for(ull j = 1 ; j <= i; ++j){
            cur.push_back(v);
            v++;
        }

        for(ull i=0 ; i<cur.size()-1 ; ++i){
            graph[cur[i]].push_back(prev[i]);
            graph[cur[i+1]].push_back(prev[i]);
        }
        prev = cur;
    }
}

ull dfs(ull node,std::unordered_map<ull,bool>& visited){
    if (memo[node] != 0) return memo[node];
    std::stack<ull> s;
    s.push(node);
    ull ans=0;
    while(!s.empty()){
        ull cur=s.top();
        s.pop();
        ans+=cur*cur;
        visited[cur]=true;

        std::vector<ull> nodes=graph[cur];
        for(auto u: nodes){
            if (!visited[u]){
                s.push(u);
            }
        }
    }
    return memo[node]=ans;
}

ull solve(ull node){
    if (memo[node] != 0) return memo[node];
    std::unordered_map<ull,bool> visited;
    for(ull i=1;i<=node;++i) visited[i]=false;
    return memo[node]=dfs(node,visited);
}


int main(){
    FAST;

    graph=new std::vector<ull>[NB_NODES+1];
    build_graph();

    memo= new ull[NB_NODES+1];
    for(int i = 1 ; i<=NB_NODES ; ++i) memo[i]=0;
    
    int t;
    std::cin>>t;
    while(t--){
        ull n;
        std::cin>>n;
        std::cout << solve(n) << '\n';
    }

    delete[] graph;

    return 0;
}