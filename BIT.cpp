#include <iostream>
#include <algorithm>
#include <numeric>
#include <math.h>
#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <map>
#include <set>
#include <queue>
using namespace std;
#define print(x) for(auto& i:x) cout<<i<<" "; cout<<'\n';
#define scan(x) for(auto& i:x) cin>>i;
#define FAST ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define d1(a) cout<<a<<endl;
#define d2(a,b) cout<<a<<" "<<b<<endl
#define d3(a,b,c) cout<<a<<" "<<b<<" "<<c<<endl
#define d4(a,b,c,d) cout<<a<<" "<<b<<" "<<c<<" "<<d<<endl
#define d5(a,b,c,d,e) cout<<a<<" "<<b<<" "<<c<<" "<<d<<" "<<e<<endl
#define int long long int
int mod=1e9+7;

//https://codeforces.com/contest/1354/problem/D

/*
Least significant bit of i is i&-i
query is prefix sum till i
bit array has 1 based indexing
bit array stores count of occurence of a num at the num-index
*/

int n,q;
vector<int> bit;

void update(int i, int val){
	for(;i<=n;i+=i&-i) bit[i]+=val;
}

int query(int i){
	int sum=0;
	for(;i>0;i-=i&-i) sum+=bit[i];
	return sum;
}

int find(int x){
	int l=1, r=n+1;
	while(l<r){
		int m=(r-l)/2 +l;
		if(query(m)>=x) r=m;
		else l=m+1;
	}
	return l;
}

void solve(){
	cin>>n>>q;
	bit.resize(n+1);
	vector<int> a(n); scan(a);
	vector<int> b(q); scan(b);
	for(auto i:a) update(i, 1);
	for(auto i:b){
		if(i>0) update(i, 1);
		else update(find(-i), -1);
	}
	if(query(n)==0) cout<<0<<endl;
	else cout<<find(1)<<endl;
}

#undef int
int main() {
	freopen("test.txt", "r", stdin);
	FAST; int T=1;
	//cin>>T;
	while(T--) solve();
	return 0;
}