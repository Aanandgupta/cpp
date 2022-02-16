#include <bits/stdc++.h>
using namespace std;


// Tree Node
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
};

pair<int,int> diam(struct Node* root)
{
    pair<int,int> l,r;
    if(root==NULL)
    {
        return {0,0};
    }
    l=diam(root->left);
    r=diam(root->right);
    int h=max(l.second,r.second)+1;
    int d=max(max(l.first,r.first),(l.second+r.second+1));
    
    return make_pair(d,h);
    
}

int diameter(struct Node* root) {
    // code here
    diam(root);

    return 0;    
}