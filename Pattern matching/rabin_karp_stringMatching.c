#include<stdio.h>
#include<string.h>
#include<math.h>

#define d 256
#define q 101		//a prime num

void search(char pat[],char txt[]){
	int m = strlen(pat);
	int n = strlen(txt);
	int i,j,p=0,t=0,h=1;
	
	h=(int)pow(d,(m-1))%q;
	
	//hash val of pat and first win of txt
	for(i=0;i<m;i++){
		p=(d*p + pat[i])%q;
		t=(d*t + pat[i])%q;
	}
	
	for(i=0;i<=n-m;i++){
		
		if(p==t){
			for(j=0;j<m;j++)
				if(txt[i+j] != pat[j])
					break;
			if(j==m)
				printf("Pattern found at index- %d\n",i);
		}
		
		//has for nxt win
		if(i < n-m){
			
			t = (d*(t-txt[i]*h)+txt[i+m])%q;
			
			if(t<0)
				t+=q;
			
		}
		
	}
}

int main() 
{ 
    char txt[] = "AABAACAADAABAAABAA"; 
    char pat[] = "AABA"; 
    search(pat, txt); 
    return 0; 
} 
