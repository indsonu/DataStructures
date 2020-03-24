/*
  Created By: Sonu Sharma
  25/3/20 - 2:03AM
*/
// This problem can also be done using BFS and backtrackinng m coloring algorithm
// Or if the graph contains and any odd cycle then it is not a bipartite graph
// This will work for all types of graph

#include<bits/stdc++.h>
using namespace std;
const int MAX=1e5+1;
vector<int>adj[MAX];
bool BipartiteHelper(vector<int>&coloring,int src,int democolor=1){
    coloring[src]=democolor;
    bool ans=true;
    for(auto child:adj[src]){
        if(coloring[child]==-1){
            ans=ans&BipartiteHelper(coloring,child,1-democolor);  
        }
        else if(coloring[child]!=1-democolor){
            return false;
        }
        if(!ans)return false;
    }
    return true;
}
bool isBipartite(int n){
    vector<int>coloring(1+n,-1);
    bool ans;
    for(auto i=1;i<=n;i++){
        if(coloring[i]==-1){
            ans=BipartiteHelper(coloring,i);
            if(!ans)return false;
        }        
    }
    return ans;
}
int main(){
    int n,m;cin>>n>>m;
    for(auto i=0;i<m;i++){
        int a,b;cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    isBipartite(n)?cout<<"YES":cout<<"NO";
    return 0;
}
