#include<bits/stdc++.h>
using namespace std;

class bst{
    public:
    int data;
    bst *left;
    bst *right;

    bst(int data)
    {
        this->data=data;
        left=NULL;
        right=NULL;
    }
};

class linkList{
    public:
    bst *head;
    bst *tail;
};


class LL{
    public:
    bst *head;
    bst *tail;
};


LL convertToLL(bst *root)
{
    LL temp,left,right;
    if(root==NULL)
    {
        temp.head=temp.tail=NULL;
        return temp;
    }
    if(root->left==NULL && root->right==NULL)
    {
        temp.head=temp.tail=root;
        return temp;
    }
    else if(root->left==NULL and root->right!=NULL){
        right=convertToLL(root->right);
        temp.head=root;
        temp.tail=right.tail;
        root->right=right.head;
        return temp;
    }
    else if(root->right==NULL and root->left!=NULL)
    {
        left=convertToLL(root->left);
        temp.head=left.head;
        left.tail->right=root;
        temp.tail=root;
        return temp;
    }
    else{
        LL  rightLL=convertToLL(root->right);
        LL leftLL=convertToLL(root->left);
        leftLL.tail->right=root;
        root->right=rightLL.head;
        temp.tail=rightLL.tail;
        temp.head=leftLL.head;
        return temp;
    }

}

bool search(bst *head,int key)
{
    if(head==NULL)
    return false;

    if(key==head->data)
    {
        return true;
    }
    else if(key<head->data)
    {
        return search(head->left,key);
    }
    else{

        return search(head->right,key);
    }

}


bst * build(vector <int> a,int i,int j)
{
    int mid=0;
    if(i>j)
    {
        return NULL;
    }
    else
    {
        mid=(i+j)/2;
        bst *temp=new bst(a[mid]);
        temp->left=build(a,i,mid-1);
        temp->right=build(a,mid+1,j);
        return temp;
    }
}


pair <int,int> maxSubset(bst *head)
{
    if(head==NULL)
    {
        return {0,0};
    }
    pair<int,int> a,b;
    int inc,exc;
    a=maxSubset(head->left);
    b=maxSubset(head->right);
    inc=head->data+a.second+b.second;
    exc=max(a.first,a.second)+ max(b.first,b.second);
    return {inc,exc};
}

bst * preOrder()
{
    int a;
    cin >> a;
    if(a==-1)
    {
        return NULL;
    } 
    bst *temp=new bst(a);
    
    temp->left=preOrder();
    temp->right=preOrder();
    return temp;
}

bst * levelOrder()
{
    queue <bst *> store;
    int a,b;
    cin >> a;
    if(a==-1)
    return NULL;
    bst *head=new bst(a);
    store.push(head);
    store.push(NULL);

    while(!store.empty())
    {
        bst *temp1=store.front();
        cin >> a >>b;
        if(a!=-1)
        {
            temp1->left=new bst(a);
            store.push(temp1->left);

        }
        if(b!=-1)
        {
            temp1->right=new bst(b);
            store.push(temp1->right);
        }
        store.pop();
    }
        

    return head;

}


int closest(bst *head,int target)
{
    int value=-1,diff;
    int closestDiff=INT_MAX;
    while(head!=NULL)
    {
        diff=abs(head->data-target);
        if(diff==0)
        return head->data;

        if(abs(head->data-target)<closestDiff)
        {
            closestDiff=abs(head->data-target);
            value=head->data;
        }
        if(head->data<target)
        {
            head=head->right;
        }
        else{
            head=head->left;
        }

    }
    return value;
}


void inorder(bst *head)
{
    if(head==NULL)
    return;
    inorder(head->left);
    cout << head->data << ",";
    inorder(head->right);
}

linkList  treeToList(bst *head)
{
    linkList ll;
    if(head==NULL)
    {
        ll.head=ll.tail=NULL;
     
    }
    else if(head->right!=NULL && head->left!=NULL)
    {
        linkList lr,le;
        lr=treeToList(head->right);
        le=treeToList(head->left);
        le.tail->right=head;
        head->right=lr.head;
        ll.head=le.head;
        ll.tail=lr.tail;
    }
    else if(head->left!=NULL)
    {
        linkList le;
        le=treeToList(head->left);
        le.tail->right=head;
        ll.tail=head;
        ll.head=le.head;
    }
    else if(head->right!=NULL)
    {
        linkList lr;
        lr=treeToList(head->right);
        head->right=lr.head;
        ll.tail=lr.tail;
        ll.head=head;
    }
    else{
         ll.head=ll.tail=head;
    }
    return ll;
}

linkList  treeToDoublyList(bst *head)
{
    linkList ll;
    if(head==NULL)
    {
        ll.head=ll.tail=NULL;
     
    }
    else if(head->right!=NULL && head->left!=NULL)
    {
        linkList lr,le;
        lr=treeToList(head->right);
        le=treeToList(head->left);
        le.tail->right=head;
        head->left=le.tail;
        head->right=lr.head;
        lr.head->left=head;
        ll.head=le.head;
        ll.tail=lr.tail;
    }
    else if(head->left!=NULL)
    {
        linkList le;
        le=treeToList(head->left);
        le.tail->right=head;
        head->left=le.tail;
        ll.tail=head;
        ll.head=le.head;
    }
    else if(head->right!=NULL)
    {
        cout << head->right->right->data;
        linkList lr;
        lr=treeToList(head->right);
        head->right=lr.head;
        lr.head->left=head;
        ll.tail=lr.tail;
        ll.head=head;
    }
    else{
         ll.head=ll.tail=head;
    }
    return ll;
}


void insert(bst * &head,int data)
{
    bst *temp=new bst(data);
    if(head==NULL)
    {
        head=temp;
        return;
    }
    bst *head1=head;
    bst *prev=head;
    while(head1!=NULL)
    {
        prev=head1;
        if(data < head1->data)
        {
            head1=head1->left;
        }
        else{
            head1=head1->right;
        }
    }

      if(data<prev->data)
        {
            prev->left=temp;
        }
        else{
            prev->right=temp;
        }
}


int inorderSuc(bst *head,int data,int suc)
{
    if(head==NULL)
    {
        return -1;
    }
    if(data==head->data)
    {
        if(head->right!=NULL)
        {
            bst *temp=head->right;
            while(temp->left!=NULL)
            {
                temp=temp->left;
            }
            return temp->data;
        }
        else{
            return suc;
        }
    }
    else if(data<head->data)
    {
        return inorderSuc(head->left,data,head->data);
     
    }
    else{
        return inorderSuc(head->right,data,suc);

    }

}




int main()
{
    vector <int> arr={12,90,1,5,7,8,9,89};
    // bst *head=build(arr,0,arr.size()-1);
    // cout << closest(head,5);
     bst *head=NULL;
     for(int i=0;i<arr.size();i++)
     {
         insert(head,arr[i]);
     }
    inorder(head);
    cout << endl;
    bst* start=convertToLL(head).head; //not working
    while(start!=NULL)
    {
        cout << start->data << " ,";
        start=start->right;
    }
    // cout << inorderSuc(head,11,-1);
    // cout << inorderSuc(head,12,-1);
    // cout << inorderSuc(head,91,-1);
    // cout << inorderSuc(head,1,-1);
    // cout << inorderSuc(head,5,-1);
    // cout << inorderSuc(head,6,-1);
    // cout << inorderSuc(head,7,-1);
    // cout << inorderSuc(head,8,-1);
    // cout << inorderSuc(head,9,-1);
    return 0;
}