/*
https://leetcode.com/problems/russian-doll-envelopes/

LIS using multiset and lower_bound
*/

class Solution {
public:    
    int maxEnvelopes(vector<vector<int>>& a) {
        sort(a.begin(),a.end(),[](vector<int> a, vector<int> b){
            if(a[0]==b[0]) return a[1]>b[1];
            return a[0]<b[0];
        });
        multiset<int> s;
        multiset<int>::iterator it;
        for(int i=0;i<a.size();i++){
            s.insert(a[i][1]);
            it=s.lower_bound(a[i][1]);
            it++;
            if(it!=s.end()) s.erase(it);
        }
        return s.size();
    }
};
