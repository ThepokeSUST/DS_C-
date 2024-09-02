#include<iostream>
#include<queue>
using namespace std;

class node{

   public:
       int data;
       node* left;
       node* right;

       node(int val){

         this->data= val;
         this->left= NULL;
         this->right=NULL;

       }

};

node* build_tree(){


   int ele;
   cin>>ele;
   if(ele==-1) return NULL;

   node* newnode= new node(ele);
   newnode->left= build_tree();
   newnode->right= build_tree();

return newnode;
}

void display(node* root){
    if(root==NULL) return;

    display(root->left);
    cout<<root->data<<" ";
    display(root->right);
}


int main(){
   node* root = build_tree();
    display(root);
}
