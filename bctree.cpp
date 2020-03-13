#include <iostream>


class tree { 
  
  struct branch{
   int info;
   branch *left;
   branch *right;
   };
   
   branch *root;
   
   int TH(branch *t){
   if(t==nullptr) return 0;
   int a,b;
   a=1+TH(t->left);
   b=1+TH(t-right);
   if (a>b) return a;
   return b;
   }
   
   void TI(int x,branch *t){
   if(t==nullptr){
   t= new branch;
   t->info=x;
   t->left=t->right=nullptr;
   }
   while(x<=t->info) TI(x,t->left);
   TI(x,t->right);
   }
  
  void Tpre(branch *q){
    if(q==nullptr) return;
    printf("%d ",q->info);
      Tpre(q->left);
      Tpre(q->right);
  }
   void Tin(branch *q){
    if(q==nullptr) return;
      Tin(q->left);
     printf("%d ",q->info);
      Tin(q->right);
   }
  void Tpost(branch *q){
   if(q==nullptr) return;
      Tpost(q->left);
      Tpost(q->right);
    printf("%d ",q->info);
  }
  public: 
       tree    ();      
  int  height    ();     
  void insert    (int x); 
  int  search    (int x);  
  int  min       ();      
  int  max       ();      
  void inorder   ();       
  void preorder  ();      
  void postorder ();       
};

tree::tree{root=nullptr;};

int tree::height(){
 return TH(root);
};

void tree::insert(int x){
TI(x,root);
};

int tree::min(){
 branch *q;
 q=root
 while (q->left!=nullptr) q=q->left;
 return q->info;
 };
 
 int tree::max(){
 branch *q;
 q=root;
 while (q->right!=nullptr) q=q->right;
 return q->info;
 };
 
 int tree::search(int x){
  branch *q;
  q=root;
  int level=0;
   bool fak=0;
   while (q!=nullptr){
     level++;
     if(x==q->info) {fak=1; break;}
     if (x>q->info) q=q->right;
     q=q->left;
   }
   if(fak==0) return 0;
   return level;  
 };
  
  void tree::preorder(){
   Tpre(root);
   };
 void tree::inorder(){
   Tin(root);
 };

void tree::postorder(){
  Tpost(root);
};

int main(){}
  
  
  
  
