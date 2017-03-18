// C++ program to find the largest subtree
// having identical left and right subtree
#include <bits/stdc++.h>
using namespace std;

/* A binary tree node has data, pointer to left
child and a pointer to right child */
struct Node
{
	int data;
	Node* left, * right;
};

/* Helper function that allocates a new node with
the given data and NULL left and right pointers. */
Node* newNode(int data)
{
	Node* node = new Node;
	node->data = data;
	node->left = node->right = NULL;
	return (node);
}

// Sets maxSize to size of largest subtree with
// identical left and right. maxSize is set with
// size of the maximum sized subtree. It returns
// size of subtree rooted with current node. This
// size is used to keep track of maximum size.
int largestSubtreeUtil(Node* root, string& str,
					int& maxSize, Node*& maxNode)
{
	if (root == NULL)
		return 0;

	// string to store structure of left and
	// right subtrees
	string left = "", right = "";

	// traverse left subtree and finds its size
	int ls = largestSubtreeUtil(root->left, left,
							maxSize, maxNode);

	// traverse right subtree and finds its size
	int rs = largestSubtreeUtil(root->right, right,
							maxSize, maxNode);

	// if left and right subtrees are similar
	// update maximum subtree if needed (Note that
	// left subtree may have a bigger value than
	// right and vice versa)
	int size = ls + rs + 1;
	if (left.compare(right) == 0)
	{
	if (size > maxSize)
	{
			maxSize = size;
			maxNode = root;
	}
	}

	// append left subtree data
	str.append("|").append(left).append("|");

	// append current node data
	str.append("|").append(to_string(root->data)).append("|");

	// append right subtree data
	str.append("|").append(right).append("|");

	return size;
}

// function to find the largest subtree
// having identical left and right subtree
int largestSubtree(Node* node, Node*& maxNode)
{
	int maxSize = 0;
	string str = "";
	largestSubtreeUtil(node, str, maxSize, maxNode);

	return maxSize;
}

/* Driver program to test above functions*/
int main()
{
	
	Node* root = newNode(50);
	root->left = newNode(10);
	root->right = newNode(60);
	root->left->left = newNode(5);
	root->left->right = newNode(20);
	root->right->left = newNode(70);
	root->right->left->left = newNode(65);
	root->right->left->right = newNode(80);
	root->right->right = newNode(70);
	root->right->right->left = newNode(65);
	root->right->right->right = newNode(80);

	Node *maxNode = NULL;
	int maxSize = largestSubtree(root, maxNode);

	cout << "Largest Subtree is rooted at node "
		<< maxNode->data << "\nand its size is "
		<< maxSize;

	return 0;
}

