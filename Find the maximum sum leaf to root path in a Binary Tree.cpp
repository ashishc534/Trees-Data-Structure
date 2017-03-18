#include<bits/stdc++.h>
using namespace std;

struct node{
	int data;
	node *left;
	node *right;
}**root,*temp;

node *newNode(int data)
{
	temp = new node;
	temp->data=data;
	temp->left=temp->right=NULL;
	
	return temp;
}

bool printPath(node *root,node *target)
{
	if(!root)
	return false;
	
	if(root==target ||printPath(root->left,target) || printPath(root->right,target))
	{
		cout<<root->data<<" ";
		return true;
	}
	return false;
}
void getTargetLeaf(node *root,int CurrSum,int &maxSum,node *&targetLeaf)
{
	if(!root)
	return;
	
	CurrSum+=root->data;
	
	if(!root->left && !root->right)
	{
		if(CurrSum > maxSum)
		{
			maxSum=CurrSum;
			targetLeaf=root;
		}
	}
	getTargetLeaf(root->left,CurrSum,maxSum,targetLeaf);
	getTargetLeaf(root->right,CurrSum,maxSum,targetLeaf);
}
int maxSumPath(node *root)
{
	int maxSum=0,Currsum=0;
	node *targetLeaf=NULL;
	
	getTargetLeaf(root,Currsum,maxSum,targetLeaf);
	
	printPath(root,targetLeaf);
	
	return maxSum;
}
int main()
{
    node *root = NULL;
 
    root = newNode(10);
    root->left = newNode(-2);
    root->right = newNode(7);
    root->left->left = newNode(8);
    root->left->right = newNode(-4);
 
    cout<<"Following are the nodes on the maximum sum path \n";
    
	int sum = maxSumPath(root);
    
	cout<<"\nSum of the nodes is "<<sum;
 
    getchar();
    return 0;
}
