#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <bits/stdc++.h>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int nodes, edges, q, u, v, w;
    cin>>nodes>>edges;
    vector<vector<int> > graph(nodes, vector<int> (nodes, 10000));
    for(int i=0;i<edges;i++){
        cin>>u>>v>>w;
        graph[u-1][v-1] = w;
    }
    
    for(int k=0;k<nodes;k++){
        for(int i=0;i<nodes;i++){
            for(int j=0;j<nodes;j++){
                if(graph[i][k]+graph[k][j]<graph[i][j]){
                    graph[i][j] = graph[i][k]+graph[k][j];
                }
            }
        }
    }
    cin>>q;
    for(int i=0;i<q;i++){
        cin>>u>>v;
        if(u==v){
            cout<<0<<endl;
        }else if(graph[u-1][v-1]==10000){
            cout<<-1<<endl;
        }else{
            cout<<graph[u-1][v-1]<<endl;
        }
    }
    return 0;
}
