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

bool areIdentical(node *root1,node *root2)
{
	if(!root1 || !root2)
	return false;
	
	if(!root1 && !root2)
	return true;
	
	queue<node *>q1,q2;
	
	q1.push(root1);
	q2.push(root2);
	
	while(!q1.empty() && !q2.empty())
	{
		node *p = q1.front();
		node *q = q2.front();
		
		q1.pop();
		q2.pop();
		
		if(p->data !=q->data)
		return false;
		
		if(p->left && q->left)
		{
			q1.push(p->left);
			q2.push(q->left);
		}
		else if(p->left || q->left)
		return false;
		
		if(p->right && q->right)
		{
			q1.push(p->right);
			q2.push(q->right);
		}
		else if(p->right || q->right)
		return false;
	}
	return true;
}
int main()
{
    node *root1 = newNode(1);
    root1->left = newNode(2);
    root1->right = newNode(3);
    root1->left->left = newNode(4);
    root1->left->right = newNode(5);
 
    node *root2 = newNode(1);
    root2->left = newNode(2);
    root2->right = newNode(3);
    root2->left->left = newNode(4);
    root2->left->right = newNode(5);
 
    areIdentical(root1, root2)? cout << "Yes" : cout << "No";
    return 0;
}
