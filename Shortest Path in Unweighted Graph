#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int q, nodes, edges, u, v, s;
    cin>>q;
    for(int l=0;l<q;l++){
        cin>>nodes>>edges;
        vector<vector<int> > adj(nodes+1);
        vector<int> distance(nodes+1, -1);
        for(int i=0;i<edges;i++){
            cin>>u>>v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        cin>>s;
        queue<int> q;
        q.push(s);
        distance[s] = 0;
        
        while(!q.empty()){
            v = q.front();
            q.pop();
            for(int i=0;i<adj[v].size();i++){
                if(distance[adj[v][i]]==-1){
                    distance[adj[v][i]] = distance[v] + 1;
                    q.push(adj[v][i]);
                }
            }
        }
        
        for(int i=1;i<=nodes;i++){
            if(i==s){
                //
            }else{
                if(distance[i]!=-1){
                    distance[i] *= 6; 
                }
                cout<<distance[i]<<" ";
            }
        }
        cout<<endl;
        
        
    }
    return 0;
}
