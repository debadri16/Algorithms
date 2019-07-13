#include<bits/stdc++.h>

using namespace std;

int LCsubsqc(string s1,string s2){
	vector< vector<int> > dp(s1.size()+1);
	for(int i=0;i<=s1.size();i++){
		dp[i]=vector<int> (s2.size()+1,0);
	}
	for(int i=1;i<=s1.size();i++){
		for(int j=1;j<=s2.size();j++){
			if(s1[i-1]==s2[j-1])
				dp[i][j]=dp[i-1][j-1]+1;
			else
				dp[i][j]=max(dp[i-1][j], dp[i][j-1]);
		}
	}
//	for(int i=0;i<=s1.size();i++){
//		for(int j=0;j<=s2.size();j++)
//			cout<<dp[i][j];
//		cout<<endl;
//	}
	return(dp[s1.size()][s2.size()]);
	
}

int main(){
	string s1,s2;
	cout<<"Enter both strings\n";
	cin>>s1>>s2;
	int l=LCsubsqc(s1,s2);
	cout<<"Length of longest common subsequence "<<l;
}
