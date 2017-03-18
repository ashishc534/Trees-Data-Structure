#include <bits/stdc++.h>
using namespace std;
 
struct node
{
    node *left, *right, *parent;
    int data;
};
 
node *newNode(int item)
{
    node *temp = new node;
    temp->data = item;
    temp->parent = temp->left = temp->right = NULL;
    return temp;
}
 
node *insert(node *root, int key)
{
    if (root == NULL) return newNode(key);
 
    if (key < root->data)
    {
        root->left  = insert(root->left, key);
        root->left->parent = root;
    }
    else if (key > root->data)
    {
        root->right = insert(root->right, key);
        root->right->parent = root;
    }
 
    return root;
}
 
void inorder(node *root)
{
	bool leftDone = false;
	
	while(root)
	{
		if(!leftDone)
		{
			while(root->left)
			root=root->left;
		}
			leftDone = true;
			
			cout<<root->data<<" ";
		
		if(root->right)
		{
			leftDone = false;
			root=root->right;
		}
		else if(root->parent)
		{
			while(root->parent && root==root->parent->right)
			root = root->parent;
			
			if(!root->parent)
			break;
			
			root=root->parent;
		}
		else break;
	}
}
int main()
{
    node * root = NULL;
 
    root = insert(root, 24);
    root = insert(root, 27);
    root = insert(root, 29);
    root = insert(root, 34);
    root = insert(root, 14);
    root = insert(root, 4);
    root = insert(root, 10);
    root = insert(root, 22);
    root = insert(root, 13);
    root = insert(root, 3);
    root = insert(root, 2);
    root = insert(root, 6);
 
    cout<<"Inorder traversal is \n";
    inorder(root);
 
    return 0;
}
