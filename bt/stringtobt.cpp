/* C++ program to construct a binary tree from
the given string */
#include <bits/stdc++.h>
using namespace std;

/* A binary tree node has data, pointer to left
child and a pointer to right child */
struct Node {
	int data;
	Node *left, *right;
};
/* Helper function that allocates a new node */
Node* newNode(int data)
{
	Node* node = (Node*)malloc(sizeof(Node));
	node->data = data;
	node->left = node->right = NULL;
	return (node);
}

/* This function is here just to test */
void preOrder(Node* node)
{
	if (node == NULL)
		return;
	preOrder(node->left);
	printf("%d ", node->data);
	preOrder(node->right);
}

// function to return the index of close parenthesis

// function to construct tree from string
Node* treeFromString(string str)
{
	// Base case
    stack<Node *> stack;
    for(char i:str)
    {
        if(i>='0' and i<='9')
        {
            stack.push(newNode(i-'0'));
        }
        else if(i==')')
        {
            Node *temp=stack.top();
            stack.pop();
            if(stack.top()->left==NULL)
            {
                stack.top()->left=temp;
            }
            else
            {
                stack.top()->right=temp;
            }

        }
    }

    return stack.top();
}
string StringFromTree(Node *root)
{
	// Base case
    string temp="",temp1;
    if(root==NULL)
    {
        return "";
    }
    if(root->left==NULL and root->right==NULL)
    {
        temp=root->data+'0';

        return temp;
    }
    if(root->left!=NULL)
    {
        temp='('+StringFromTree(root->left)+')';
    }
    if(root->right!=NULL)
    {
        temp=temp+'('+StringFromTree(root->right)+')';
    }
    temp1= root->data+'0';
    return (temp1+temp);
}

// Driver Code
int main()
{
	string str = "4(6(5)(7))";
	Node* root = treeFromString(str);
    cout<<StringFromTree(root);
	// preOrder(root);
}
