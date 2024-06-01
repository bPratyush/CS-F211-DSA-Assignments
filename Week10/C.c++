#include <iostream>
#include <vector>
using namespace std;

void addAdjacency(vector<vector<int>>&adj,int a,int b){
    adj[a].push_back(b);
    adj[b].push_back(a);
}

int sumOfDepths(vector<vector<int>>&adj,int current,int prev,int depth){
    depth++;
    if(adj[current].size()==1)return depth;
    int sum=0;
    for(auto n:adj[current]){
        if(n!=prev){
            sum+=sumOfDepths(adj,n,current,depth);
        }   
    }
    return sum+depth;
}

void dfs(vector<vector<int>>&adj,int current,int prev,int &sum){
    sum+=sumOfDepths(adj,current,prev,-1);
    for(auto n:adj[current]){
        if(n!=prev)dfs(adj,n,current,sum);
    }
}

int main(){
    int n;cin>>n;
    vector<vector<int>>adjList;
    for(int i=0;i<n;i++){
        int a,b;cin>>a>>b;
        addAdjacency(adjList,--a,--b);
    }
    int sum=0;
    dfs(adjList,0,-1,sum);
    cout<<sum<<"\n";
    return 0;
}