#include <bits/stdc++.h>
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


int height(bst *head)
{
    if(head==NULL)
    {
        return -1;
    }

    return max(height(head->left),height(head->right))+1; 
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
        if(data<head1->data)
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


void printBfs(bst *head)
{
    queue <bst *> h1;

    if(head==NULL)
        return ;
    h1.push(head);

    while(!h1.empty())
    {
        bst *temp=h1.front();
        cout << temp->data << " ";
        if(temp->left!=NULL)
        h1.push(temp->left);
        if(temp->right!=NULL)
        h1.push(temp->right);
        h1.pop();
    }
    return ;
}

void print(bst *head)
{
    if(head==NULL)
    {
        return ;
    }
    print(head->left);
    cout << head->data << " ";
    print(head->right);
    return ;
}

bool check(bst *head)
{
    if(head==NULL)
    {
        return true;
    }
    bool ans=true;
    if(head->left!=NULL)
    {
        ans&=(head->left->data < head->data); 
        ans&=check(head->left);
    }
    if(head->right!=NULL)
    {
        ans&=(head->right->data >= head->data); 
        ans&=check(head->right);
    }
    return ans;
}

int maxValue(bst *head)
{
    while(head->right!=NULL)
    {
        head=head->right;
    }
    return head->data;
}
int minValue(bst *head)
{
    while(head->left!=NULL)
    {
        head=head->left;
    }
    return head->data;
}

pair <int,int> diameter(bst *head)
{
    pair <int,int> d={0,0},h={0,0};
    int a=0,b=0;
    if(head==NULL)
    return {-1,-1};
        d=diameter(head->right);
        // d.second=height(head->right)+1;
   
        h=diameter(head->left);
        // h.second=height(head->left)+1;
        // cout << b << b1 <<"  kn ";
       
            a=h.second+1;
        
            b=d.second+1;

    return {max(h.first,max(d.first,a+b)),max(h.second,d.second)+1};
}

bst* remove(bst *head,int data)
{
    if(head==NULL)
    return NULL;
    if(head->data==data)
    {
        if(head->left ==NULL && head->right==NULL)
        {
            delete head;
            return NULL;
        }
        else if(head->right == NULL)
        {
            bst *temp=head->left;
            delete head;
            return temp; 

        }
        else if(head->left == NULL)
        {
            bst *temp=head->right;
            delete head;
            return temp; 

        }
        else{
            int maximum=maxValue(head->left);
            head->data=maximum;
            head->left=remove(head->left,maximum);
        }


    }
    else if(data<head->data)
    {

        head->left=remove(head->left,data);
    }
    else{
           
        head->right=remove(head->right,data);
    }

    return head;
}

void inorderSucc(bst *head,int data)
{
    int suc=-1;
    if(head==NULL)
    {
        cout << "not found";
        return ;
    }
    while(head!=NULL && head->data!=data)
    {
        if(data < head->data)
        {
            suc=head->data;
            head=head->left;
        }
        else{
            head=head->right;
        }
    }
    if(head==NULL)
    {
    cout << "not found";
    return ;
    }
    if(head->right!=NULL)
    {
        cout << minValue(head->right);
    }
    else{
        if(suc==-1)
        cout<<"Not Found";
        else
        cout << suc;
    }

}


int replaceSum(bst *head)
{
    int a=0,b=0,c=0;
    if(head==NULL)
    {
        return 0;
    }
    

     a=replaceSum(head->left);
     b=replaceSum(head->right);
     c=head->data;
     if(head->right!=NULL || head->left!=NULL)
     {
        head->data=a+b;
     }



     return a+b+c;

}


pair <int,bool> heightBalanced(bst *head)
{
    pair<int,bool> a,b;
    if(head==NULL)
    {
        return {-1,true};
    }
    a=heightBalanced(head->left);
    if(a.second==false)
    {
        return {0,false};
    }
    b=heightBalanced(head->right);
    if(b.second==false)
    {
        return {0,false};
    }

    if(abs(a.first-b.first)<=1)
    {
        return {max(a.first,b.first)+1,true};
    }
    return {0,false};
}

pair <int,int> maxSubsetSum(bst *head)
{
    if(head==NULL)
    {
        return {0,0};
    }
    
    pair <int,int> a,b;
    a=maxSubsetSum(head->right);
    b=maxSubsetSum(head->left);
    int inc=head->data+a.second+b.second;
    
    int exc=max(a.first,a.second)+max(b.first,b.second);


    return {inc,exc};
}

void printAtKlevel(bst *head,int k)
{
    if(head==NULL)
    {
        return ;
    }
    queue <bst *> store;
    bst *temp;
    int i=0;
    store.push(head);
    store.push(NULL);
    temp=head;
    while(!store.empty())
    {
        while(!store.empty() and store.front()!=NULL)
        {
            temp=store.front();
            store.pop();
            if(i==k)
            {
                cout << temp->data << " ";
            }
            if(temp->left!=NULL)
            {
                store.push(temp->left);
            }
            if(temp->right!=NULL)
            {
                store.push(temp->right);
            }
        }
        if(i==k)
        {
            return ;
        }
        if(!store.empty())
        {
            store.pop();
            store.push(NULL);
        }
        i++;

    }
    return ;

}

void printAtKLevelRec(bst *head,int k)
{
    if(head==NULL)
    {
        return ;
    }
    if(k==0)
    {
        cout << head->data << " ";
        return ;
    }

    printAtKLevelRec(head->left,k-1);
    printAtKLevelRec(head->right,k-1);
    return ;
}

int printAtDisKFromT(bst *head,int t,int k)
{
    if(head==NULL)
    {
        return -1;
    }
    if(head->data==t)
    {
        printAtKLevelRec(head,k);
        return 0;
    }

    int distanceLeft=printAtDisKFromT(head->left,t,k);
    int distanceRight=printAtDisKFromT(head->right,t,k);
    if(distanceLeft==-1 && distanceRight==-1)
    {
        return -1;
    }
    else if(distanceRight!=-1)
    {
        if(distanceRight+1<k)
        {
        printAtKLevelRec(head->left,k-(distanceRight+1)-1);
            return distanceRight+1;
        }
        else if(distanceRight+1==k)
        {
        cout << head->data;
        }
        return -1;
    }
    else{ 
        if(distanceLeft+1<k)
        {
        printAtKLevelRec(head->right,k-(distanceLeft+1)-1);
            return distanceLeft+1;
        }
        else if(distanceLeft+1==k)
        {
        cout << head->data;
        }
        return -1;
    }
}

void verticalPrint(bst *head,int k,map <int,vector<int>> &a)
{
    if(head==NULL)
    {
        return ;
    }
    a[k].push_back(head->data);
    verticalPrint(head->left,k-1,a);
    verticalPrint(head->right,k+1,a);
    return ;

}

int main()
{
    // map <int,vector<int>> a;
    pair <int,int> a;
    pair <int,bool> b;
    bst *head=NULL;
    insert(head,15);
    insert(head,10);
    insert(head,8);
    insert(head,6);
    insert(head,12);
    insert(head,11);
    // insert(head,20);
    // insert(head,17);
    // insert(head,16);
    // insert(head,25);
    // insert(head,27);
    // insert(head,30);
    // insert(head,31);
    
    // head=remove(head,2);
    // print(head);
    // inorderSucc(head,10);
    // cout << endl;
    // inorderSucc(head,8);
    // cout << endl;
    // inorderSucc(head,6);
    // cout << endl;
    // inorderSucc(head,15);
    a= diameter(head);
    // replaceSum(head);
    // print(head);
    // b=heightBalanced(head);
    // cout << b.second;
    cout << a.first;
    // a=maxSubsetSum(head);
    // printAtKlevel(head,2);
    cout << endl;
    // printAtKLevelRec(head,2);
    // cout << max(a.first,a.second);
    // printAtDisKFromT(head,15,2);
    // verticalPrint(head,0,a);
    // for(auto i:a)
    // {
    //     int key=i.first;
    //     for(int j:a[key])
    //     {
    //         cout << j ;
    //     }
    //     cout << endl;
    // }
    return 0;
}