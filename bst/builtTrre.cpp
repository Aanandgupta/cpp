//built bstree from preorder traversal of bst

#include<bits/stdc++.h>
using namespace std;

class Node
{
    public:
    int data;
    Node *left;
    Node *right;

    Node(int data)
    {
        this->data=data;
        left=right=NULL;
    }
};

Node * build(vector <int> arr,int &i,int maximum=INT_MAX,int minimum=INT_MIN)
{
    if(i==arr.size())
    {
        return NULL;
    }
    int t=arr[i];
    if(t>maximum || t<minimum)
    {
        return NULL;
    }
    Node *temp=new Node(arr[i++]);
    temp->left=build(arr,i,t,minimum);
    temp->right=build(arr,i,maximum,t);
    return temp;
}

void inorder(Node *head)
{
    if(head==NULL)
    return;
    cout << head->data << ",";
    inorder(head->left);
    inorder(head->right);
}

int main()
{
    int i=0;
    vector <int> arr{10,5,1,7,40,50};
    Node *root=build(arr,i);
    inorder(root);
    return 0;
}