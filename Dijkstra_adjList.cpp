#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
#include <bits/stdc++.h>
using namespace std;


class Compare{
    public:
    bool operator()(pair<int, int> a, pair<int, int> b){
        return (a.second<b.second);
    }
};

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int t, nodes, edges, u, v, w, s;
    cin>>t;
    for(int l=0;l<t;l++){
        cin>>nodes>>edges;
        vector<int> distance(nodes+1, -1);
        vector<vector<pair<int, int> > > adj(nodes+1);
        for(int i=0;i<edges;i++){
            cin>>u>>v>>w;
            adj[u].push_back(make_pair(v, w));
            adj[v].push_back(make_pair(u, w));
        }
        priority_queue<pair<int, int>, vector<pair<int, int> >, Compare> q;
        cin>>s;
        distance[s]=0;
        q.push(make_pair(s, 0));
        
        int temp;
        while(!q.empty()){
            u = q.top().first;
            //temp = q.front().second;
            q.pop();
            for(int i=0;i<adj[u].size();i++){
                v = get<0>(adj[u][i]);
                int d = distance[u] + get<1>(adj[u][i]);
                if(distance[v]==-1){
                    distance[v] = d;
                    q.push(make_pair(v, d));
                }else if(d<distance[v]){
                    distance[v] = d;
                    q.push(make_pair(v, d));
                }
            }
        }
        
        for(int i=1;i<=nodes;i++){
            if(i==s){
                //do nothing
            }else{
                cout<<distance[i]<<" ";
            }
        }
        cout<<endl;
    }
    return 0;
}
