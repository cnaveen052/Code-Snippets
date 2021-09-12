#include<iostream>
#include <vector>
#include <queue>
using namespace std;

/*
https://leetcode.com/problems/path-with-maximum-probability
*/

class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& P, int s, int t) {
        vector<vector<pair<int, double>>> g(n);
        vector<int> seen(n);
        vector<double> d(n, 0); d[s]=1;
        for(int i=0;i<edges.size();i++){
            int x=edges[i][0], y=edges[i][1];
            g[x].push_back({y, P[i]});
            g[y].push_back({x, P[i]});
        }
        priority_queue<pair<double, int>> q;
        q.push({d[s], s});
        while(q.size()){
            auto [dis, x] = q.top(); q.pop();
            if(seen[x]) continue;
            seen[x]=1;
            for(auto i:g[x]){
                auto y=i.first;
                auto w=i.second;
                if(d[y]<dis*w){
                    d[y]=dis*w;
                    q.push({d[y], y});
                }
            }
        }
        return d[t];
    }
};
