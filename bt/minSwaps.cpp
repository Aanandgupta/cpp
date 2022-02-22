#include<bits/stdc++.h>
using namespace std;

 
// Data structure to store a binary tree node
struct Node
{
    int data;
    Node *left, *right;
 
    Node(int data)
    {
        this->data = data;
        this->left = this->right = nullptr;
    }
};
 
// Iterative function to perform inorder traversal on the tree
void inorderIterative(Node* root,vector <int> &arr)
{
    // create an empty stack
    stack<Node*> stack;
 
    // start from the root node (set current node to the root node)
    Node* curr = root;
 
    // if the current node is null and the stack is also empty, we are done
    while (!stack.empty() || curr != nullptr)
    {
        // if the current node exists, push it into the stack (defer it)
        // and move to its left child
        if (curr != nullptr)
        {
            stack.push(curr);
            curr = curr->left;
        }
        else {
            // otherwise, if the current node is null, pop an element from the stack,
            // print it, and finally set the current node to its right child
            curr = stack.top();
            stack.pop();
            arr.push_back(curr->data);
            curr = curr->right;
        }
    }
}

void preIterative(Node* root)
{
    // create an empty stack
    stack<Node*> stack;
 
    // start from the root node (set current node to the root node)
    Node* curr = root;
 
    // if the current node is null and the stack is also empty, we are done
    while (!stack.empty() || curr != nullptr)
    {
        // if the current node exists, push it into the stack (defer it)
        // and move to its left child
        cout << curr->data << " ";
        curr = stack.top();
        stack.pop();

        if(curr->right!=NULL)
        {
            stack.push(curr->right);
        }
        if(curr->left!=NULL)
        {
            stack.push(curr->left);
        }
    }
}
int main()
{
    /* Construct the following tree
               1
             /   \
            /     \
           2       3
          /      /   \
         /      /     \
        4      5       6
              / \
             /   \
            7     8
    */
 
    Node* root = new Node(5);
    root->left = new Node(6);
    root->right = new Node(7);
    root->left->left = new Node(8);
    root->left->right = new Node(9);
    root->right->left = new Node(10);
    root->right->right = new Node(11);

    vector <int> arr;
    inorderIterative(root,arr);
    vector <bool> visited(arr.size(),false);
    pair <int,int> arr1[arr.size()];
    for(int i=0;i<arr.size();i++)
    {
        arr1[i]={arr[i],i};
    }
    sort(arr1,arr1+6);
    int swaps=0;
    int cycle=0;
    int i=0;
    for(int i=0;i<arr.size();i++)
    {
        cycle=0;
        if(!visited[i] and arr1[i].second!=i)
        {
            int j=i;
            while(!visited[j])
            {
               
                visited[j]=true;
                j=arr1[j].second;
                cycle++;
            }
            swaps+=cycle-1;
        }

    }

    cout<<swaps;
    return 0;
}