#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <bits/stdc++.h>
using namespace std;

int find(vector<int> &parent, int i){
    if(parent[i]==-1){
        return i;
    }
    return find(parent, parent[i]);
}

void Union(vector<int> &parent, int x, int y){
    parent[x] = y;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int nodes, edges, u, v, w, s;
    cin>>nodes>>edges;
    int countEdges = 0;
    int mst = 0;
    vector<int> parent(nodes+1, -1);
    multimap<int, pair<int, int> > ht;
    for(int i=0;i<edges;i++){
        cin>>u>>v>>w;
        ht.insert({w, make_pair(u, v)});
    }
    cin>>s;
    map<int, pair<int, int> >::iterator it;
    for(it = ht.begin(); it!=ht.end();it++){
        if(countEdges==nodes-1){
            break;
        }
        w = it->first;
        u = it->second.first;
        v = it->second.second;
        /*cout<<"w is "<<w<<endl;
        cout<<"u is "<<u<<endl;
        cout<<"v is "<<v<<endl;*/
        int x = find(parent, u);
        int y = find(parent, v);/*
        cout<<"x is "<<x<<endl;
        cout<<"y is "<<y<<endl;*/
        if(x!=y){
            //cout<<"unioned"<<endl;
            countEdges++;
            mst += w;
            Union(parent, x, y);
        }
    }
    cout<<mst<<endl;
    return 0;
}
