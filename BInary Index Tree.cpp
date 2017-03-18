#include<bits/stdc++.h>
using namespace std;

void update(int Btree[],int n,int index,int val)
{
	index=index+1;
	
	while(index<=n)
	{
		Btree[index]+=val;
		index+=index & (-index);
	}
}
int *ConstructBtree(int arr[],int n)
{
	int *Btree=new int[n+1];
	
	for(int i=1;i<=n;i++)
	Btree[i]=0;
	
	for(int i=0;i<n;i++)
	update(Btree,n,i,arr[i]);
	
	for(int i=1;i<=n;i++)
	cout<<Btree[i]<<" ";
	return Btree;
}

int getSum(int BItree[],int index)
{
	int sum=0;
	
	index=index+1;
	
	while(index > 0)
	{
		sum+=BItree[index];
		index-=index & (-index);
	}
	return sum;
}
int main()
{
	int arr[]={2,1,1,3,2,3,4,5,6,7,8,9};
	int n=sizeof(arr)/sizeof(arr[0]);
	
	int *BItree=ConstructBtree(arr,n);
	
	cout<<"\nSum in arr[0...5] is : "<<getSum(BItree,5);
	
	update(BItree,n,3,6);
	
	cout<<"\nSum in arr[0...5] after updation is : "<<getSum(BItree,5);
	
	return 0;
}
