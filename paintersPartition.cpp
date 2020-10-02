#include<iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

//https://leetcode.com/problems/capacity-to-ship-packages-within-d-days/submissions/

class Solution {
public:
    vector<int> a;
    int n;
    
    int go(int m){
        int day=1, sum=0;
        for(int i=0;i<n;i++){
            sum+=a[i];
            if(sum>m){ day++; sum=a[i];}
        }
        return day;
    }
    
    int shipWithinDays(vector<int>& A, int D) {
        a=A; n=a.size();
        int lo=*max_element(a.begin(),a.end()), hi=accumulate(a.begin(),a.end(),0);
        while(lo<hi){
            int mid=lo+(hi-lo)/2;
            if(go(mid)<=D) hi=mid;
            else lo=mid+1;
        }
        return lo;
    }
};
