#include<bits/stdc++.h>
#include<tr1/unordered_set>
using namespace std::tr1;
using namespace std;

struct Node
{
	int data;
	struct Node* left, *right;
};

struct Node* newnode(int data)
{
	struct Node* node = new Node;
	node->data = data;
	node->left = node->right = NULL;
	return (node);
}
bool pathsumutil(Node *n,unordered_set<int> &mp , int root_data)
{
    if(!n)
    return false;
    
    int rem=root_data - n->data;
    
    if(mp.find(rem)!=mp.end())
    return true;
    
    mp.insert(n->data);
    
    bool res=pathsumutil(n->left,mp,root_data) || pathsumutil(n->right,mp,root_data);
    
	mp.erase(n->data);
	
	return res;    
}
bool isPathSum(Node *root)
{
    unordered_set<int>mp;
    return pathsumutil(root->left,mp,root->data)||pathsumutil(root->right,mp,root->data);
}
// Driver program to run the case
int main()
{
	struct Node *root = newnode(8);
	root->left = newnode(5);
	root->right = newnode(4);
	root->left->left = newnode(9);
	root->left->right = newnode(7);
	root->left->right->left = newnode(1);
	root->left->right->right = newnode(12);
	root->left->right->right->right = newnode(2);
	root->right->right = newnode(11);
	root->right->right->left = newnode(3);
	isPathSum(root)? cout << "Yes" : cout << "No";
	return 0;
}

