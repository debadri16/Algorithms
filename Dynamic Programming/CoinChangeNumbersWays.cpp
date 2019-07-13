#include<bits/stdc++.h>

using namespace std;

int ways(vector<int> a,int n){
	vector< vector<int> > dp(a.size());
	for(int i=0;i<a.size();i++){
		dp[i]=vector<int> (n+1,0);
		dp[i][0]=1;
	}
	for(int j=1;j<=n;j++){
		if(j%a[0]==0)
			dp[0][j]=1;
	}
	for(int i=1;i<a.size();i++){
		for(int j=1;j<=n;j++){
			if(j<a[i])
				dp[i][j]=dp[i-1][j];
			else
				dp[i][j]=dp[i][j-a[i]] + dp[i-1][j];
		}
	}
//	for(int i=0;i<a.size();i++){
//		for(int j=0;j<=n;j++)
//			cout<<dp[i][j];
//		cout<<endl;
//	}
	return(dp[a.size()-1][n]);
	
}

int main(){
	int n,sum;
	vector<int> a;
	cout<<"Enter number of coins\n";
	cin>>n;
	cout<<"Enter the coins\n";
	for(int i=0;i<n;i++){
		int x;
		cin>>x;
		a.push_back(x);
	}
	cout<<"Enter value to obtain\n";
	cin>>sum;
	int l=ways(a,sum);
	cout<<l<<" number of ways to get the total";
}
