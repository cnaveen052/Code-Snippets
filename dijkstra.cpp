#include<iostream>
#include <vector>
#include <queue>
using namespace std;

typedef pair<int, int> ii;

class Solution {
public:
    int minDistaceFromSToT(int n, vector<vector<int>>& edges, vector<int>& dist, int s, int t) {
        vector<vector<ii>> g(n);
        vector<int> d(n);
        for(int k=0; k<edges.size(); k++){
            const auto& e = edges[k];
            int x = e[0], y = e[1];
            int z = dist[k];
            g[x].push_back({y, z});
            g[y].push_back({x, z});
        }
        priority_queue<ii, vector<ii>, greater<ii>> q;
        fill(d.begin(), d.end(), INT_MAX);
        d[s] = 0;
        q.push({d[s], s});
        while (!q.empty()) {
            auto [dd, u]=q.top(); q.pop();
            if (dd != d[u]) continue;
            for (auto& [v, w] : g[u]) {
                if (d[v] > d[u] + w) {
                    d[v] = d[u] + w;
                    q.push({d[v], v});
                }
            }
        }
        return d[t];
    }
};