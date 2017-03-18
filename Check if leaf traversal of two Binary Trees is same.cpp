#include<bits/stdc++.h>
using namespace std;

struct node{
	int data;
	node *left;
	node *right;
}**root , *temp;

node *newNode(int data)
{
	temp = new node;
	temp->data=data;
	temp->left=temp->right=NULL;
	
	return temp;
}

bool isleaf(node *a)
{
	return (!a->left && !a->right);
}
bool isSame(node *root1 , node *root2)
{
	stack<node *>s1,s2;
	s1.push(root1);
	s2.push(root2);
	
	while(!s1.empty() || !s2.empty())
	{
		if(s1.empty() || s2.empty())
		return false;
		
		node *temp1=s1.top();
		s1.pop();
		while(temp1 && !isleaf(temp1))
		{
			if(temp1->right)
			s1.push(temp1->right);
			if(temp1->left)
			s1.push(temp1->left);
			temp1=s1.top();
			s1.pop();	
		}
		
		node *temp2=s2.top();
		s2.pop();
		while(temp2 && !isleaf(temp2))
		{
			if(temp2->right)
			s2.push(temp2->right);
			
			if(temp2->left)
			s2.push(temp2->left);
			
			temp2=s2.top();
			s2.pop();
		}
		
		if(!temp || !temp2)
		return false;
		
		
		if(temp1 && temp2)
		{
			if(temp1->data != temp2->data)
			return false;
		}
	}
	return true;
}
int main()
{
	node *root1=NULL;
	
	root1=newNode(1);
	root1->left=newNode(2);
	root1->right=newNode(3);
	root1->left->left=newNode(4);
	root1->right->left=newNode(6);
	root1->right->right=newNode(7);
	
	node *root2=NULL;
	root2=newNode(0);
	root2->left=newNode(5);
	root2->right=newNode(8);
	root2->left->right=newNode(4);
	root2->right->left=newNode(6);
	root2->right->right=newNode(7);
	
	isSame(root1,root2) ? cout<<"YES" : cout<<"NO";
	
	return 0;
}
