#include<bits/stdc++.h>
using namespace std;

struct node{
	int data;
	int hd;
	node *left;
	node *right;
}**root,*temp;

node *newNode(int data)
{
	temp = new node;
	temp->data=data;
	temp->left=temp->right=NULL;
	temp->hd=INT_MAX;
	return temp;
}
void bottomView(node *root)
{
	if(!root)
	return;
	
	int hd=0;
	map<int,int>m;
	
	queue<node*>q;
	
	root->hd=hd;
	q.push(root);
	
	while(!q.empty())
	{
		temp = q.front();
		q.pop();
		
		hd=temp->hd;
		m[hd]=temp->data;
		
		if(temp->left)
		{
			temp->left->hd=hd-1;
			q.push(temp->left);
		}
		if(temp->right)
		{
			temp->right->hd=hd+1;
			q.push(temp->right);
		}
	}
	
	map<int,int>::iterator it;
	for(it=m.begin();it!=m.end();++it)
	cout<<it->second<<" ";
}
int main()
{
    node *root = newNode(20);
    root->left = newNode(8);
    root->right = newNode(22);
    root->left->left = newNode(5);
    root->left->right = newNode(3);
    root->right->left = newNode(4);
    root->right->right = newNode(25);
    root->left->right->left = newNode(10);
    root->left->right->right = newNode(14);
    cout << "Bottom view of the given binary tree :\n";
    bottomView(root);
    return 0;
}
