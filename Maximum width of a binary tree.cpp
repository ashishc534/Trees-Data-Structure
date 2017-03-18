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

int maxWidth(node *root)
{
	if(!root)
	return 0;
	
	int res=0;
	
	queue<node *>q;
	q.push(root);
	
	while(!q.empty())
	{
		int count=q.size();
		res=max(count,res);
		
		while(count--)
		{
			temp = q.front();
			q.pop();
			
			if(temp->left)
			q.push(temp->left);
			
			if(temp->right)
			q.push(temp->right);
		}
	}
	return res;
}
int main()
{
    node *root 		  = newNode(1);
    root->left        = newNode(2);
    root->right       = newNode(3);
    root->left->left  = newNode(4);
    root->left->right = newNode(5);
    root->right->right = newNode(8);
    root->right->right->left  = newNode(6);
    root->right->right->right  = newNode(7);
 
    cout << "Maximum width is "<< maxWidth(root) << endl;
    return 0;
}
 
