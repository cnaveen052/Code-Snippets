#include<iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int cycle=0;
    vector<int> v;
    vector<vector<int>> g;
    
    void dfs(int x){
        if(v[x]==1) {cycle=1; return;}
        if(v[x]==2) return;
        v[x]=1;
        for(auto i:g[x]) { if(!cycle) dfs(i);}
        v[x]=2;
    }
    
    bool canFinish(int n, vector<vector<int>>& p) {
        v.resize(n); g.resize(n);
        for(auto i:p) g[i[0]].push_back(i[1]);
        for(int i=0;i<n;i++) { if(!cycle) dfs(i);}
        return !cycle;
    }
};