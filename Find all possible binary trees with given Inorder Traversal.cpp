#include <bits/stdc++.h>
using namespace std;
  
struct node
{
    int key;
    struct node *left, *right;
};
  
struct node *newNode(int item)
{
    struct node *temp = new node;
    temp->key = item;
    temp->left = temp->right = NULL;
    return temp;
}
  
void preorder(node *root)
{
    if (root != NULL)
    {
        printf("%d ", root->key);
        preorder(root->left);
        preorder(root->right);
    }
}
  
vector<node *> getTrees(int arr[], int start, int end)
{
    vector<node *> trees;
  
    if (start > end)
    {
        trees.push_back(NULL);
        return trees;
    }
  
    for (int i = start; i <= end; i++)
    {
        vector<node *> ltrees = getTrees(arr, start, i-1);
  
        vector<node *> rtrees = getTrees(arr, i+1, end);
  
        for (int j = 0; j < ltrees.size(); j++)
        {
            for (int k = 0; k < rtrees.size(); k++)
            {
                node * node = newNode(arr[i]);
  
                node->left = ltrees[j];
  
                node->right = rtrees[k];
  
                trees.push_back(node);
            }
        }
    }
    return trees;
}
  
int main()
{
    int in[] = {4, 5, 7};
    int n = sizeof(in) / sizeof(in[0]);
  
    vector<node *> trees = getTrees(in, 0, n-1);
  
    cout << "Preorder traversals of different "
         << "possible Binary Trees are \n";
    for (int i = 0; i < trees.size(); i++)
    {
        preorder(trees[i]);
        cout<<endl;
    }
    return 0;
}
