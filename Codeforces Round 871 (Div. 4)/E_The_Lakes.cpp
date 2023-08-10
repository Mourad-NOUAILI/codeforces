#include<bits/stdc++.h>

#define FAST std::ios_base::sync_with_stdio(false);std::cin.tie(NULL);std::cout.tie(NULL)

typedef std::map<std::pair<int,int>,bool> my_map;

std::vector<std::pair<int,int>> moves={
        {-1,0}, //up
        {1,0}, //down
        {0,-1}, //left
        {0,1}, //right
};


int dfs( std::vector<std::vector<int>>& lake,int row,int col,int n, int m,my_map& visited){
    if (row>n-1 || row<0 || col>m-1 || col<0) return 0;
    if(visited[{row,col}]) return 0;
    visited[{row,col}]=true;
    if (lake[row][col]==0) return 0;
    int ans=lake[row][col];
    for(int i=0 ; i<4 ; ++i){
        int x=row+moves[i].first;
        int y=col+moves[i].second;
        ans+=dfs(lake,x,y,n,m,visited);
    }
    return ans;
}

int solve (std::vector<std::vector<int>>& lake,int n,int m,my_map& visited){
    int ans=0;
    for(int i=0 ; i<n ; ++i){
        for(int j=0 ; j<m ; ++j){
            if (visited[{i,j}] || lake[i][j]==0) continue;
            ans=std::max(ans,dfs(lake,i,j,n,m,visited));
        }
    }
    return ans;
}

int main(){
    FAST;

    int t;
    std::cin>>t;
    while(t--){
        int n,m;
        std::cin>>n>>m;

        std::vector<std::vector<int>> lake(n,std::vector<int>(m));
        my_map visited;
        for(int i = 0 ; i<n ; ++i){
            for(int j=0 ; j <m ; ++j){
                visited[{i,j}] = false;
                std::cin>>lake[i][j];
            }
        }

        std::cout<<solve(lake,n,m,visited) << '\n';
    }
    return 0;
}