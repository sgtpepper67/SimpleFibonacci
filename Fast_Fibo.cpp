#include <bits/stdc++.h>
using namespace std;
#define m 1000000007 
//long long n;

vector<vector<long long>> matmult(vector<vector<long long>> a,vector<vector<long long>> b){
	vector<vector<long long>> ans((a[0].size()),vector<long long>(b.size()));
	for(int i=0;i<a[0].size();i++){
		for(int j=0;j<b.size();j++){
			for(int k=0;k<2;k++){
				ans[i][j]+=((a[i][k]%m)*(b[k][j]%m))%m;
			}
		}
	}
	
	return ans;
}

vector<vector<long long>> powe (vector<vector<long long>> a,long long n){
	if(n==1){
		return a;
	}
	if(n==0){	
		vector<vector<long long>> p(1,vector<long long>(1));
		vector<long long> q;
		q.push_back(1);
		p.push_back(q);
		return p;
	}
	if(n%2==0){
		vector<vector<long long>> r;
		r=powe(a,n/2);
		return matmult(r,r);
	}
	if(n%2==1){
		return matmult(a,powe(a,n-1));
	}
} 


void fibo(long long n){
	vector<vector<long long>> T(2,vector<long long>(2));
	for(int i=0;i<2;i++){
		for(int j=0;j<2;j++){
			T[i][j]=1;
			if(i==0 and j==0)
				T[i][j]=0;
		}
	}
	
	vector<vector<long long>> mat = powe(T,n-1);
	vector<vector<long long>> F(2,vector<long long>(2));
	F[0][0]=1;
	F[1][0]=1;
	vector<vector<long long>> ans = matmult(mat,F);
	cout<<ans[0][0]%m<<endl;
}

int main()
{	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	#ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#endif
	int t;cin>>t;
	while(t--){
	long long n;
	cin>>n;
	fibo(n);
	}
}