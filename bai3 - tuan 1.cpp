#include <iostream>
using namespace std;

struct nut {
    int giatri;
    nut *left, *right;
};

typedef nut Node;
Node *goc, *goc1;

void khoiTao(Node *&goc) {
    goc= NULL;
}

void mocNut(Node *&goc, int x) {
    if(goc == NULL) {
    goc= new Node;
    goc->giatri = x;
    goc->left = NULL;
    goc->right = NULL;
    }
    else {
    if(goc->giatri >= x)
    mocNut(goc->left,x);
    else
    mocNut(goc->right,x);
    }
}

void taoCay(Node *&goc) {
    int tmp;
    do{
    cout<<"Nhap so nguyen, 0 de dung: ";
    cin>>tmp;
    if(tmp != 0)
    mocNut(goc,tmp);
    }while(tmp != 0);
}


void duyetLNR(Node *goc) {
    if(goc != NULL) {
    duyetLNR(goc->left);
    cout<<goc->giatri<<" ";
    duyetLNR(goc->right);
    }
} 


int max(int a, int b)
{
    if(a>=b)
    return a;
    return b;
}

int chieuCao(Node *goc)
{
    if(goc == NULL)
    return 0;
    return 1 + max(chieuCao(goc->left),                         chieuCao(goc->right));
}

void inMuci(Node *goc, int i, int muc = 1)
{
    if(goc != NULL)
        if(muc == i)
        cout<<goc->giatri<<" ";
    else
    {
        inMuci(goc->left, i, muc+1);
        inMuci(goc->right, i, muc+1);
    }
}


void saoChep(Node *goc, Node *&goc1)
{
    if(goc == NULL)
    goc1 = NULL;
    else
    {
        goc1 = new Node;
        goc1->giatri = goc->giatri;
        saoChep(goc->left, goc1->left);
        saoChep(goc->right, goc1->right);
    }
}


void thaythe(Node *&goc, Node *&q){
    if(goc->left!=NULL){
        thaythe(goc->left,q);
    }
    else {
        q->giatri = goc->giatri;
        q=goc;
        goc=goc->right;
    }
}

int timX(Node *&goc, int x)
{
   if(goc != NULL){
       if(goc->giatri == x) return 1;
       else 
           return timX(goc->left,x)  + timX(goc->right,x);
   }
   return 0;
}
void delGoc(Node *&goc, int x){
    if(goc==NULL) return;
    if(goc->giatri > x) delGoc(goc->left,x);
    if(goc->giatri < x) delGoc(goc->right,x);
    if(goc->giatri == x) { 
        Node *q;
        q = goc;
        if(goc->left==NULL) { 
            goc=goc->right; 
        }
        else if(goc->right==NULL){
            goc=goc->left;
        }        
       else thaythe(goc->right,q);
        delete q;
    }
}

int main(){
    khoiTao(goc);
    taoCay(goc);
    duyetLNR(goc);
    cout<<endl<<"Chieu cao cua cay: "<<chieuCao(goc);
    cout<<endl<<"In nut muc 3: ";
    inMuci(goc,3,1);
    saoChep(goc,goc1);
    cout<<endl<<"Sao chep cay: ";
    duyetLNR(goc1);
    cout<<endl<<"Xoa nut co gia tri 12: ";
    while(timX(goc,12) !=0){
    delGoc(goc,12);
    }
    duyetLNR(goc);
}

