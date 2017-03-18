#include<bits/stdc++.h>
using namespace std;

void filldepth(int arr[],int i,int depth[])
{
	if(depth[i])
	return;
	
	if(arr[i]==-1)
	{
	depth[i]=1;
	return;
	}
	
	if(depth[arr[i]]==0)
	filldepth(arr,arr[i],depth);
	
	depth[i]=depth[arr[i]]+1;
}
int height(int arr[],int n)
{
	int depth[n];
	for(int i=0;i<n;i++)
	depth[i]=0;
	
	for(int i=0;i<n;i++)
	filldepth(arr,i,depth);
	
	int maxValue=INT_MIN;
	
	for(int i=0;i<n;i++)
	maxValue=max(maxValue,depth[i]);
	
	return maxValue;	
	
}
int main()
{
	int arr[]={1,5,5,2,2,-1,3};
	int n=sizeof(arr)/sizeof(arr[0]);
	
	cout<<"height is : "<<height(arr,n);
	
	return 0;		
}
