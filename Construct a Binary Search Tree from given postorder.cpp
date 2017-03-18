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

node *_BuildTree(int post[],int *index,int min,int max,int size)
{
	int data = post[*index];
	
	if(*index < 0)
	return NULL;
	
	node *root = NULL;
	
	if(data > min && data < max)
	{
		root=newNode(data);
		(*index)--;
		
		if(*index > 0)
		{
			root->right=_BuildTree(post,index,data,INT_MAX,size);
			
			root->left=_BuildTree(post,index,INT_MIN,data,size);
		}
	}
	return root;
}

void PostOrder(node *root)
{
	if(!root)
	return;
	
	PostOrder(root->left);
	PostOrder(root->right);
	cout<<root->data<<" ";
}
node *BuildTree(int post[],int n)
{
	int index=n-1;
	
	return _BuildTree(post,&index,INT_MIN,INT_MAX,n);
}
int main()
{
	int post[]={1,7,5,50,40,10};
	int n=sizeof(post)/sizeof(post[0]);
	node *root = BuildTree(post,n);
	
	PostOrder(root);
	
	return 0;
}
