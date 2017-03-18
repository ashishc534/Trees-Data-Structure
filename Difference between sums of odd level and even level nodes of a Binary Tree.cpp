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

int sum(node *root)
{
	if(!root)
	return 0;
	
	int oddSum=0,evenSum=0;
	
	int level=1;
	
	queue<node *>q;
	
	q.push(root);
	q.push(NULL);
	
	while(!q.empty())
	{
		int count=q.size();
		
		while(count--)
		{
			temp = q.front();
			q.pop();
			
			if(temp==NULL)
			{
		
				if(!q.empty())
				q.push(NULL);
				
				level++;
			}
			
			else
			{
				cout<<temp->data<<" ";
				
			if(level % 2 == 0)
			evenSum+=temp->data;
			
			else if(level % 2!=0)
			oddSum+=temp->data;
		
			if(temp->left)
			q.push(temp->left);
			
			if(temp->right)
			q.push(temp->right);
			}
		}
		cout<<endl;
	}
	return(oddSum-evenSum);
}
int main()
{
	node *root=NULL;
	
	root=newNode(5);
	root->left=newNode(2);
	root->right=newNode(6);
	root->left->left=newNode(1);
	root->left->right=newNode(4);
	root->left->right->left=newNode(3);
	root->right->right=newNode(8);
	root->right->right->right=newNode(9);
	root->right->right->left=newNode(7);
	
	cout<<"\nThe sum Between Odd And Even Level Nodes is : "<<sum(root)<<endl;
	getchar();
	
	return 0;	
}
