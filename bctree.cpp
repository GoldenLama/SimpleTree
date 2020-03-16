#include <iostream>  
#include "pzhelp"  
#include <cstdio>  
#include <algorithm>  
using namespace std;  
  
int max  (int k, int x)  {  
  if(k>x) return k;  
  else return x; }  
  
struct node {  
  int info;  
  node *left,*right; };  
typedef node *tree;  
  
class bstree {  
  public :  
    bstree ();  
    int height (tree t);  
    node* insert (tree t, int data);  
    node* get(int x);  
    int search (tree t, int x, int counter);  
    int min (tree t);  
    int maxi (tree t);  
    void inorder (tree t);  
    void preorder (tree t);  
    void postorder (tree t);  
  private :  
node *head; };  
  
bstree::bstree (){   
  head=nullptr;}  
  
  int bstree::height (tree t) {  
  if (t==nullptr) return 0;  
   return 1 +max(height(t->right),height(t->left));}  
  
  void bstree::preorder (tree t) {  
     if (t != nullptr) { WRITE(t->info,"");;  
        preorder(t->left);  
        preorder(t->right);  
         }  
  }  
   
void bstree::postorder (tree t) {  
  if(t==nullptr) return;  
   postorder(t->left);  
   postorder(t->right);  
  WRITE(t->info, "");  
   }  
  
void bstree::inorder (tree t) {  
  if(t==nullptr) return;  
  inorder(t->left);  
    WRITE(t->info, "");  
    inorder(t->right); }  
  
    node*  bstree::get(int x) {  
      node* q=new node;  
      q->info=x;  
      q->left=nullptr;  
      q->right=nullptr;  
      return q; }  
          
node* bstree::insert(tree t, int x) {  
if (t==nullptr) t=get(x);  
if(t->info>x) t->left=insert(t->left, x);  
if(x>t->info) t->right=insert(t->right, x);   
return t; }  
  
  
int bstree::maxi (tree t){  
  node*q=t;  
while (q->right!=nullptr) q=q->right;  
return q->info;}  
  
int bstree::min (tree t) {   
  node *q=t;  
  while(q->left!=nullptr) q=q->left;  
  return q->info; }  
  
  int bstree::search (tree t, int x, int counter) {  
    if(t==nullptr) return 0;  
    if(x==t->info) return counter;  
    else if(x<t->info) {return search(t->left, x, ++counter);  
    }  else if(x>t->info) return search(t->right, x, ++counter);   
  }  
      
  
PROGRAM {int n, m, i, x, *p; node *t=nullptr;  bstree b;  
  n=READ_INT(); SKIP_LINE();  
for(i=0; i<n; i++) {x=READ_INT(); t=b.insert(t, x); }  SKIP_LINE();  
m=READ_INT(); SKIP_LINE(); p=new(nothrow) int[m];  
for(i=0; i<m; i++){ x=READ_INT(); p[i]=b.search(t, x, 1);} SKIP_LINE();  
cout<<b.height(t)<<endl;  
 cout<<b.min(t)<<" "<<b.maxi(t)<<endl;  
for(i=0; i<m-1; i++) cout<<p[i]<<" "; cout<<p[m-1]<<endl;   
b.inorder(t); cout<<"end"<<endl;  
b.preorder(t); cout<<"end"<<endl;  
b.postorder(t); cout<<"end"<<endl;  
  
}
  
  
  
  
