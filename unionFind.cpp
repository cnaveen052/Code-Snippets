#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
using namespace std;

//https://leetcode.com/problems/largest-component-size-by-common-factor
//https://leetcode.com/problems/minimize-malware-spread/

class Solution {
public:
    vector<int> parent, rank;
    
    void Union(int x, int y){
        int xroot=find(x), yroot=find(y);
        if(xroot!=yroot){
            if(rank[xroot]<rank[yroot]) swap(xroot,yroot);
            parent[yroot]=xroot;
            if(rank[xroot]==rank[yroot]) rank[xroot]++;
        }
    }
    
    int find(int x){
        if(parent[x]!=x) parent[x]=find(parent[x]);
        return parent[x];
    }
    
    int largestComponentSize(vector<int>& a) {
        int n=a.size();
        int mx=*max_element(a.begin(),a.end());
        parent.resize(mx+1); rank.resize(mx+1);
        for(int i=0;i<parent.size();i++) parent[i]=i;
        for(auto i:a){
            for(int k=2;k*k<=i;k++){
                if(i%k==0){
                    Union(i,k); Union(i,i/k);
                }
            }
        }
        int ans=0;
        unordered_map<int,int> mp;
        for(auto i:a){
            ans=max(ans,++mp[find(i)]);
        }
        return ans;
    }
};
