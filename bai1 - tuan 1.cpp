#include <iostream>
using namespace std;
#include <fstream>
#include <windows.h>


void Nhapmt(int a[][50], int &n){
	ifstream doc;
	doc.open("a.txt");
	doc>>n;
	for(int i = 0; i < n; i++)
		for(int j = 0; j < n; j++)
			doc>>a[i][j];
	doc.close();
}

void Xuatmt(int a[][50], int n){
	for(int i = 0; i < n; i++)
		{
			cout<<endl;
			for(int j = 0; j < n; j++)
				cout<<a[i][j]<<"\t";
		}
}

void GhiMtxoan(int a[][50], int m, int n) 
{ 
	ofstream ghi;
	ghi.open("b.txt");
    int i, k = 0, l = 0;  
    while (k < m && l < n) 
    { 
        for (i = l; i < n; ++i) 
        { 
            ghi<<a[k][i]<<"\t";
        } 
        k++; 
          for (i = k; i < m; ++i) 
        { 
            ghi<<a[i][n-1]<<"\t";
        } 
        n--; 
          if ( k < m) 
        { 
            for (i = n-1; i >= l; --i) 
            { 
                ghi<<a[m-1][i]<<"\t"; 
            } 
            m--; 
        } 
          if (l < n) 
        { 
            for (i = m-1; i >= k; --i) 
            { 
                ghi<<a[i][l]<<"\t"; 
            } 
            l++;     
        }         
    } 
    ghi.close();
} 


int main(){
	int a[50][50];
	int n;
	Nhapmt(a,n);
	Xuatmt(a,n);
	cout<<endl<<"Ghi ma tran xoan vao file thanh cong"<<endl;
	GhiMtxoan(a,n,n);
	system("pause");
	return 0;
}
