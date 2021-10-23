/*
https://codeforces.com/edu/course/2/lesson/4/1/practice/contest/273169/problem/A
*/

#include <bits/stdc++.h>
using namespace std;
#define FAST ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define print(...) for(auto& i:__VA_ARGS__) cout<<i<<" "; cout<<'\n';
#define read(...) for(auto& i:__VA_ARGS__) cin>>i;
#define int long long
const int mod=1e9+7;
 
int N,m,n,in;
vector<int> t;
 
void build(){
    for(int i=n-1; i>0; i--) t[i] = t[2*i] + t[2*i+1];
}
 
void modify(int i, int v){
    t[i]=v; i/=2;
    for(; i>0; i/=2) t[i] = t[2*i] + t[2*i+1];
}
 
int query(int cur, int curl, int curr, int l, int r){
    if(r<curl or l>curr) return 0;
    if(l<=curl and r>=curr) return t[cur];
    int mid = (curl+curr)/2;
    return query(2*cur, curl, mid, l, r) + query(2*cur+1, mid+1, curr, l, r);
}
 
void solve(){
    cin>>in>>m;
    n=1;
    while(n<in) n*=2;
    N=2*n;
    t.resize(N);
    for(int i=0; i<in; i++){
        int x; cin>>x;
        t[i+n] = x;
    }
    build();
    while(m--){
        int q; cin>>q;
        if(q==1){
            int i,v; cin>>i>>v;
            modify(i+n, v);
        }
        else{
            int l,r; cin>>l>>r;
            cout<<query(1, n, 2*n-1, l+n, r+n-1)<<endl;
        }
    }
}
 
#undef int
int main() {
    FAST; int T=1;
    //cin>>T;
    while(T--) solve();
    return 0;
}
