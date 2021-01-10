//https://leetcode.com/problems/create-sorted-array-through-instructions/

/*
Least significant bit of i is i&-i
get is prefix sum till i
bit array has 1 based indexing
bit array stores count of occurence of a num at the num-index
*/

class Solution {
public:
    vector<int> bit;
    int mod=1e9+7, n=100001;
    
    void add(int i){
        for(;i<=n;i+=i&-i) bit[i]++;
    }
    
    int get(int i){
        int sum=0;
        for(;i>0;i-=i&-i) sum+=bit[i];
        return sum;
    }
    
    int createSortedArray(vector<int>& a) {
        int N=a.size();
        bit.resize(n);
        int ans=0;
        for(int i=0;i<N;i++){
            ans=(ans+min(get(a[i]-1), i-get(a[i])))%mod;
            add(a[i]);
        }
        return ans;
    }
};
