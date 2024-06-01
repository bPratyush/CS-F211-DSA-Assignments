#include <unordered_map>
#include <set>
#include <iostream>
#include <cmath>
using namespace std;

void dfs(int node, unordered_map<int,set<int>> &adjList, unordered_map<int,bool> &visited, int *numberOfelements){
    visited[node] = true;
    *numberOfelements += 1;
    for(auto adj:adjList[node]){
        if(!visited[adj]){
            dfs(adj,adjList,visited,numberOfelements);
        }
    }
}

int main()
{
    int n;
    cin >> n;
    unordered_map<int,set<int>> adjList;
    unordered_map<int,bool> visited;
    for(int i=0; i<n-1;i++){
        int a,b;
        cin >> a >> b;
        adjList[a].insert(b);
        adjList[b].insert(a);
        visited[a] = false;
        visited[b] = false;
    }
    unordered_map<int,bool> visitedCopy = visited;
    for(int i=1; i<=n; i++){
        visited[i] = true;
        int numberOfelements = 0;
        int maxNumber = 0;
        for(auto adj : adjList){
            if(!visited[adj.first]) dfs(adj.first,adjList,visited,&numberOfelements);
            if(numberOfelements > maxNumber) maxNumber = numberOfelements;
            numberOfelements = 0;
        }
        if(maxNumber <= floor(n/2)){
            cout << i << " ";
            break;
        }
        visited = visitedCopy;
    }
}