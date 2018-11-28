#include<stdio.h>

void merge(int a[],int p,int q,int r){
	int i,j,k,m=q-p+1,n=r-q,L[25],R[25];
	for(i=1;i<=m;i++)
		L[i]=a[i+p-1];
	for(i=1;i<=n;i++)
		R[i]=a[i+q];
	L[m+1]=9999;
	R[n+1]=9999;
	
	i=1,j=1;
	
	for(k=p;k<=r;k++){
		if(L[i]<=R[j])
		{
		a[k]=L[i];
		i++;
		}
	else
		{
		a[k]=R[j];
		j++;
		}
	}
}

void mergesort(int a[],int p,int r){
	int q;
	if(p<r){
		q=(p+r)/2;
		mergesort(a,p,q);
		mergesort(a,q+1,r);
		merge(a,p,q,r);
	}
}

void main()
{
int i,a[50],n;
printf("enter the limit ");
scanf("%d",&n);
for(i=1;i<=n;i++)
	scanf("%d",&a[i]);
mergesort(a,1,n);
for(i=1;i<=n;i++)
	printf("%d ",a[i]);
}
