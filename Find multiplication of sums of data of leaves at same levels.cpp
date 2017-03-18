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

int LeavesMultiplication(node *root)
{
	static int multi=1;
	
	queue<node *>q;
	q.push(root);
	
	while(!q.empty())
	{
			int levelSum=0;
			bool leafFound=false;
		
		int count=q.size();
		while(count--)
		{
			node *p=q.front();
			q.pop();
			
			
			if(!p->left && !p->right)
			{
				leafFound = true;
				levelSum+=p->data;
			}
			
			if(p->left)
			q.push(p->left);
			if(p->right)
			q.push(p->right);
		}
		
		if(leafFound)
		multi*=levelSum;
	}
	return multi;
}
int main()
{
	node *root = NULL;
	root=newNode(2);
	root->left=newNode(7);
	root->left->left=newNode(8);
	root->left->right=newNode(6);
	root->left->right->left=newNode(1);
	root->left->right->right=newNode(11);
	root->right=newNode(5);
	root->right->right=newNode(9);
	root->right->right->right=newNode(10);
	root->right->right->left=newNode(4);
	
	cout<<LeavesMultiplication(root);
	
	return 0;	
}
