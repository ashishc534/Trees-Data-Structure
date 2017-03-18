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

node *Fliptree(node *root)
{
	if(!root)
	return NULL;
	
	if(!root->left && !root->right)
	return root;
	
	node *flippedRoot=Fliptree(root->left);
	
	root->left->left=root->right;
	root->left->right=root;
	root->left=root->right=NULL;
	
	return flippedRoot;
}

void LevelOrder(node *root)
{
	if(!root)
	return;
	
	queue<node *>q;
	q.push(root);
	
	while(!q.empty())
	{
		int count=q.size();
		while(count--)
		{
			node *p=q.front();
			q.pop();
			
			cout<<p->data<<" ";
			
			if(p->left)
			q.push(p->left);
			
			if(p->right)
			q.push(p->right);
		}
		cout<<endl;
	}
}
int  main()
{
	node *root=NULL;
	root=newNode(1);
	root->left=newNode(2);
	root->right=newNode(3);
	root->left->left=newNode(4);
	root->left->right=newNode(5);
	root->right->left=newNode(6);
	root->right->right=newNode(7);
	
	LevelOrder(root);
	
	node *temp = Fliptree(root);
	cout<<endl<<endl;
	LevelOrder(temp);
	
	return 0;
}
