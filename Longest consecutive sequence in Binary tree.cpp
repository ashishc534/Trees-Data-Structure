#include<bits/stdc++.h>
using namespace std;

struct node{
	int data;
	node *left;
	node *right;
}**root,*temp;

node *newNode(int data)
{
	temp= new node;
	temp->data=data;
	temp->left=temp->right=NULL;
	
	return temp;
}
int longestUtil(node *root,int currLength,int expected,int &res)
{
	if(!root)
	return 0;
	
	if(root->data==expected)
	currLength++;
	
	else
	currLength=1;
	
	res=max(currLength,res);
	
	longestUtil(root->left,currLength,root->data + 1,res);
	longestUtil(root->right,currLength,root->data + 1,res);
	
}
int longestConsecutive(node *root)
{
	if(!root)
	return 0;
	
	int res=0;
	
	int currLength=0;
	
	longestUtil(root,currLength,root->data,res);
	
	return res;
}
int main()
 {
	node *root = newNode(6);
    root->right = newNode(9);
    root->right->left = newNode(7);
    root->right->right = newNode(10);
    root->right->right->right = newNode(11);
 
    cout<<longestConsecutive(root)<<endl;
    return 0;
}
