#include<bits/stdc++.h>
using namespace std;

struct node{
	int data;
	node *left;
	node *right;
}**root,*temp;

node* newNode(int data)
{
    temp = new node;
    temp->data = data;
    temp->left = temp->right = NULL;
    return temp;
}

void _diagonalPrint(node *root,int slope,map<int,vector<int> >&mp)
{
	if(!root)
	return;
	
	mp[slope].push_back(root->data);
	
	_diagonalPrint(root->left,slope+1,mp);
	
	_diagonalPrint(root->right,slope,mp);
}
void diagonalPrint(node *root)
{
	if(!root)
	return;
	
	map<int,vector<int> >mp;
	
	_diagonalPrint(root,0,mp);
	
	cout<<"\nDiagonal Traversal of Tree is : ";
	map<int,vector<int> >::iterator it,irr;
	for(it=mp.begin();it!=mp.end();it++)
	{
		for(it->second.begin();it->second.end();it)
		cout<<*irr<<" ";
		
		cout<<endl;
	}
		
} 
int main()
{
    node* root = newNode(8);
    root->left = newNode(3);
    root->right = newNode(10);
    root->left->left = newNode(1);
    root->left->right = newNode(6);
    root->right->right = newNode(14);
    root->right->right->left = newNode(13);
    root->left->right->left = newNode(4);
    root->left->right->right = newNode(7);
    
    diagonalPrint(root);
    
    return 0;
}
