#include<bits/stdc++.h>
using namespace std;

int noOfBt(int arr[],int n)
{
	int maxValue=INT_MIN,minValue=INT_MAX;
	
	for(int i=0;i<n;i++)
	{
		maxValue=max(maxValue,arr[i]);
		minValue=min(minValue,arr[i]);
	}
	
	int mark[maxValue + 2];
	int value[maxValue + 2];
	memset(mark,0,sizeof(mark));
	memset(value,0,sizeof(value));
	
	for(int i=0;i<n;i++)
	{
		mark[arr[i]]=1;
		value[arr[i]]=1;
	}
	
	int ans=0;
	for(int i=minValue;i<=maxValue;i++)
	{
		if(mark[i])
		{
			for(int j=i+i;j<=maxValue && j/i<=i;j+=i)
			{
				if(!mark[j])
				continue;
				
				value[j]=value[j] + (value[i]*value[j/i]);
				
				if(i!=j/i)
				value[j]=value[j] + (value[i]*value[j/i]);
			}
		}
		ans+=value[i];
		
	}
	return ans;
}
int main()
{
	int arr[]={1,2,3};
	int n=sizeof(arr)/sizeof(arr[0]);
	
	cout<<noOfBt(arr,n);
	return 0;
}
