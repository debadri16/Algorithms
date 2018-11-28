#include<stdio.h>



void max_heapify(int a[],int i,int n){
	
	int largest=i,l=2*i,r=2*i+1,m;
	
	if(l<=n && a[l]>a[largest])
		largest = l;
	if(r<=n && a[r]>a[largest])
		largest = r;
	if(largest != i){
		m=a[largest];
		a[largest] = a[i];
		a[i] = m;
		max_heapify(a,largest,n);
	}
	
}

void build_heap(int a[],int n){
	int i;
	for(i=n/2;i>=1;i--)
		max_heapify(a,i,n);
}

void heapsort(int a[],int n){
	int m,i;
	for(i=n;i>=2;i--){
		m=a[1];
		a[1]=a[i];
		a[i]=m;
		n--;
		max_heapify(a,1,n);
	}
}

main(){
	int i,n,a[50];
	printf("enter the limit ");
	scanf("%d",&n);
	printf("enter the array\n");
	for(i=1;i<=n;i++)
		scanf("%d",&a[i]);
	build_heap(a,n);
	heapsort(a,n);
	for(i=1;i<=n;i++)
		{
		printf("%d ",a[i]);
		}
}
