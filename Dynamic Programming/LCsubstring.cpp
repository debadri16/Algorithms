#include<bits/stdc++.h>

using namespace std;

int LCsubstr(string s1,string s2){
	vector< vector<int> > dp(s1.size()+1);
	int max=0;
	for(int i=0;i<=s1.size();i++){
		dp[i]=vector<int> (s2.size()+1,0);
	}
	for(int i=1;i<=s1.size();i++){
		for(int j=1;j<=s2.size();j++){
			if(s1[i-1]==s2[j-1]){
				dp[i][j]=dp[i-1][j-1]+1;
				if(dp[i][j]>max)
					max=dp[i][j];
			}
		}
	}
//	for(int i=0;i<=s1.size();i++){
//		for(int j=0;j<=s2.size();j++)
//			cout<<dp[i][j];
//		cout<<endl;
//	}
	return(max);
	
}

int main(){
	string s1,s2;
	cout<<"Enter both strings\n";
	cin>>s1>>s2;
	int l=LCsubstr(s1,s2);
	cout<<"Length of longest common substring "<<l;
}
