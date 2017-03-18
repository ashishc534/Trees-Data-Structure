#include<bits/stdc++.h>
using namespace std;

struct node{
	int data;
	node *parent;
	node *left;
	node *right;
}**root,*temp;

node *newNode(int data)
{
	temp = new node;
	temp->data=data;
	temp->left=temp->right=temp->parent=NULL;
	
	return temp;
}

node *insert(node *root , int data)
{
	if(!root)
	return newNode(data);
	
	if(data < (root)->data)
	{
		(root)->left=insert((root)->left,data);
		(root)->left->parent = (root);
	}
		
	else if(data > (root)->data)
	{
		(root)->right=insert((root)->right,data);
		(root)->right->parent = (root);
	}
	
	return root;
}
void print(node *n)
{
	if(!n)
	return;
	
	cout<<n->data<<" ";
	print(n->left);
	print(n->right);
}

node *LCA(node *n1 , node *n2)
{
	if(n1==NULL)
	return n2;
	
	else if(n2==NULL)
	return n1;
	
	else if(n1==NULL && n2==NULL)
	return NULL;
	
	map<node *,bool>ancestors;
	
	while(n1!=NULL)
	{
		ancestors[n1]=true;
		n1=n1->parent;
	}
	
	while(n2!=NULL)
	{
		if(ancestors.find(n2)!=ancestors.end())
		{
			return n2;
		}
		n2=n2->parent;
	}
	return NULL;
}
int main()
{
	node *root=NULL;
	
	root = insert(root, 20);
  	root = insert(root, 8);
  	root = insert(root, 22);
  	root = insert(root, 4);
  	root = insert(root, 12);
  	root = insert(root, 10);
  	root = insert(root, 14);
  	
	print(root);
	node *n1 = root->left->right->left;
    node *n2 = root->left;
    node *lca = LCA(n1, n2);
    
    cout<<"\n\nLCA of "<<n1->data<<" and "<<n2->data<<" is "<<lca->data;
   
}
