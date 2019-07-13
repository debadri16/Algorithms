#include<bits/stdc++.h>

using namespace std;

int LPsubsqc(string s1){
	vector< vector<int> > dp(s1.size());
	for(int i=0;i<s1.size();i++){
		dp[i]=vector<int> (s1.size(),0);
		dp[i][i]=1;
	}
	for(int k=1;k<s1.size();k++){
		for(int i=0;(i+k)<s1.size();i++){
			int j=i+k;
			if(s1[i]==s1[j])
				dp[i][j]=dp[i+1][j-1]+2;
			else
				dp[i][j]=max(dp[i][j-1], dp[i+1][j]);
		}
	}
//	for(int i=0;i<s1.size();i++){
//		for(int j=0;j<s1.size();j++)
//			cout<<dp[i][j];
//		cout<<endl;
//	}
	return(dp[0][s1.size()-1]);
	
}

int main(){
	string s1;
	cout<<"Enter the string\n";
	cin>>s1;
	int l=LPsubsqc(s1);
	cout<<"Length of longest palindromic subsequence "<<l;
}
