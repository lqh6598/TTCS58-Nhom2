#include <iostream>
using namespace std;
#include <cstdlib>
#include <math.h>
#include <fstream>
int tt[28]; // trang thai cac quan co
int max;
struct co{
     int tren,duoi;
     };

int luu[28];
int cl = 168;




void Nhaptufile(co a[], int &n){
    ifstream doc;
    doc.open("a.txt");
    doc>>n;
    for(int i = 0; i < n; i++){
    	doc>>a[i].tren;
    	doc>>a[i].duoi;
	}
	doc.close();
}

void Kiemtra(co a[], int n){
    int dochenh;
    int sumt = 0, sumd = 0;
    int k;
    for(k = 0; k<n; k++)
        if(tt[k]==0){
            sumt += a[k].tren;
            sumd += a[k].duoi;
            
        }
        else{
            sumt += a[k].duoi;
            sumd += a[k].tren;
           
        }
        dochenh = abs(sumt - sumd);
        if(dochenh < cl){
            cl = dochenh;
            for (k = 0; k < n; k++)
                luu[k] = tt[k];
            }
}


void thu(co a[], int i,int n){
    int k;
    for(k = 0; k<=1; k++){
        tt[i] = k;
        if(i<n) thu(a,i+1,n);
        else Kiemtra(a,n);
        tt[i] = 0;
    }
}


void Xuat(co a[], int n){
    for(int i = 0; i<n ; i++)
        {
            cout<<endl<<"co["<<i+1<<"]: ";
            cout<<"tren:"<<a[i].tren<<"\tduoi:  "<<a[i].duoi;
        }
}


void Ketqua(co a[], int n){
        int tongxoay = 0;
        for(int i = 0; i<n; i++)
            if(luu[i] == 1) {
                tongxoay +=1;
                cout<<endl<<"Xoay co["<<i+1<<"]";
                }
        cout<<endl<<"do lech be  nhat: "<<cl;
        cout<<endl<<"so co phai quay: "<<tongxoay;
}



int main(){
    co a[27];
    int n;
    Nhaptufile(a,n);
    Xuat(a,n);
    thu(a,0,n);
    Ketqua(a,n);
    return 0;
}

