#include<stdio.h>

int partition(int a[],int p,int r){
	int i=p-1,j,m,x=a[r];
	for(j=p;j<r;j++){
		if(a[j]<x){
			i++;
			m=a[j];
			a[j]=a[i];
			a[i]=m;
		}
	}
	m=a[i+1];
	a[i+1]=x;
	a[r]=m;
	return(i+1);
}

void quicksort(int a[],int p,int r){
	int q;
	if(p<r){
		q=partition(a,p,r);
		quicksort(a,p,q-1);
		quicksort(a,q+1,r);
	}
}

main(){
	int a[50],n,p,r,i;
	printf("enter the limit ");
	scanf("%d",&n);
	printf("enter the array\n");
	for(i=1;i<=n;i++)
		scanf("%d",&a[i]);
	quicksort(a,1,n);
	for(i=1;i<=n;i++)
		printf("%d ",a[i]);
}
