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

void printPath(int arr[],int index)
{
	for(int i=0;i<index;i++)
	{
	cout<<arr[i];
	
	if(i!=index-1)
	cout<<"->";
	}
	cout<<endl;
}
void _roottoLeafPath(node *root,int pathArray[100],int pathIndex)
{
	if(!root)
	return;
	
	pathArray[pathIndex++]=root->data;
	
	if(!root->left && !root->right)
	{
		printPath(pathArray,pathIndex);
	}
	_roottoLeafPath(root->left,pathArray,pathIndex);
	_roottoLeafPath(root->right,pathArray,pathIndex);
}
void rootToLeafPath(node *root)
{
	int pathArray[100];
	int pathIndex=0;
	
	_roottoLeafPath(root,pathArray,pathIndex);
}
int main()
{
	node *root=newNode(10);
	root->left=newNode(8);
	root->right=newNode(2);
	root->left->left=newNode(3);
	root->left->right=newNode(5);
	root->right->left=newNode(2);
	
	rootToLeafPath(root);
	
	return 0;
}
