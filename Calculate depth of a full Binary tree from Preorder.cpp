#include<bits/stdc++.h>
using namespace std;

int _findDepth(char tree[],int n,int index)
{
	if(index >=n || tree[index]=='l')
	return 0;
	
	index++;
	int left=_findDepth(tree,n,index);
	
	index++;
	int right=_findDepth(tree,n,index);
	
	return(max(left,right) + 1);
}
int findDepth(char tree[],int n)
{
	int index=0;
	_findDepth(tree,n,index);
}
int main()
{
	char tree[]="nlnll";
	int n=strlen(tree);
	cout<<findDepth(tree,n)<<endl;
	
	return 0;
}
