#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <bits/stdc++.h>
using namespace std;

class Compare{
  public:
    bool operator()(pair<int, int> a, pair<int, int> b){
        return (a.second>b.second);
    }
};


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    ios_base::sync_with_stdio(false);
    int nodes, edges, u, v, w, s;
    cin>>nodes>>edges;
    vector<vector<pair<int, int> > > adj(nodes+1);
    vector<int> visited(nodes+1, 0);
    vector<int> distance(nodes+1, INT_MAX);
    for(int i=0;i<edges;i++){
        cin>>u>>v>>w;
        adj[u].push_back(make_pair(v, w));
        adj[v].push_back(make_pair(u, w));
    }
    cin>>s;
    priority_queue<pair<int, int>, vector<pair<int, int> >, Compare> q;
    distance[s]=0;
    q.push(make_pair(s, 0));
    
    while(!q.empty()){
        u = q.top().first;
        visited[u]=true;
        //cout<<"u is "<<u<<endl;
        q.pop();
        for(int i=0;i<adj[u].size();i++){
            v = adj[u][i].first;
            int d = adj[u][i].second;
            if(visited[v]==false && distance[v] > d){
                //cout<<"doosra"<<endl;
                distance[v] = adj[u][i].second;
                //cout<<"distance at "<<v<<" "<<distance[v]<<endl;
                q.push(make_pair(v, d));
            }
        }
    }
    int sum =0;
    for(int i=1;i<=nodes;i++){
        sum += distance[i];
    }
    cout<<sum<<endl;
    
    return 0;
}
