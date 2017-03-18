#include<bits/stdc++.h>
using namespace std;

struct node{
	int data;
	node *l;
	node *r;
}**root,*temp;

node *newNode(int data)
{
	temp= new node;
	temp->data=data;
	temp->l=temp->r=NULL;
	
	return temp;
}

int getSumOfGrandChildren( node *root);
int maxSumUtil(node *root , map<struct node*,int>& mp);
int maxSum(node *root);

int getSumOfGrandChildren(node *root , map<struct node* , int>& mp)
{
	int sum=0;
	
	if(root->l)
	{
		sum+=maxSumUtil(root->l->l,mp) + maxSumUtil(root->l->r, mp);
	}
	if(root->r)
	{
		sum+=maxSumUtil(root->r->l ,mp) + maxSumUtil(root->r->r, mp);
	}
	return sum;
}
int maxSumUtil(node *root, map<struct node*,int>& mp)
{
	if(root==NULL)
	return 0;
	
	if(mp.find(root)!=mp.end())
	return mp[root];
	
	int inclusive = root->data + getSumOfGrandChildren(root , mp);
	
	int exclusive = maxSumUtil(root->l,mp) + maxSumUtil(root->r , mp);
	
	mp[root]=max(inclusive , exclusive);
	
	return mp[root]; 
}
int maxSum(node *root)
{
	if(!root)
	return 0;
	
	map<struct node*,int> mp;
	return maxSumUtil(root,mp);
}
int main()
{    node* root = newNode(1);
    root->l = newNode(2);
    root->r = newNode(3);
    root->r->l = newNode(4);
    root->r->r = newNode(5);
    root->l->l = newNode(1);
 
    cout << maxSum(root) << endl;
    return 0;
}
