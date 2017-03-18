#include<bits/stdc++.h>
using namespace std;

struct expTree{
	char data;
	expTree *left, *right;
}**root,*temp;

expTree *newNode(char data)
{
	temp = new expTree;
	temp->data=data;
	temp->left=temp->right=NULL;
	
	return temp;
} 

bool isoperand(char a)
{
	return (a >= 'a' && a <= 'z');	
} 
expTree *construct(char postfix[])
{
	stack<expTree*>s;
	expTree *root,*t1,*t2;
	
	for(int i=0;i<strlen(postfix);i++)
	{
		if(isoperand(postfix[i]))
		{
			root=newNode(postfix[i]);
			s.push(root);
			
		}
		else
		{
			root=newNode(postfix[i]);
			t1=s.top();
			s.pop();
			t2=s.top();
			s.pop();
			
			root->left=t2;
			root->right=t1;
			
			s.push(root);
		}
	}
	root=s.top();
	s.pop();
	
	return root;
}
void inorder(expTree *root)
{
	if(!root)
	return;
	
	
	inorder(root->left);
	cout<<root->data<<" ";
	inorder(root->right);
}
int main()
{
	char postfix[]="ab+ef*g*-";
	expTree *root=construct(postfix);
	inorder(root);
	
	return 0;	
}
