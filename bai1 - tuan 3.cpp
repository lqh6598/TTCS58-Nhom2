#include <iostream>
using namespace std;
#include <cstdlib>


void Nhaprandom(int a[], int n, int m){ // Nhap random n so tu nhien tu 1 den m
/*
Input: mang a,  n: so luong phan tu,  m: gia tri gioi han
Output: nhap gia tri cac phan tu trong mang a
*/
	for(int i = 0; i < n; i++)
		a[i] = rand() % m + 1;
}

void Xuat(int a[], int n){ // Xuat mang
/*
Input: mang a, n: so luong phan tu
Output: in gia tri cac phan tu trong mang a
*/
	for(int i = 0; i<n;i++)
		cout<<a[i]<<" ";
}

int main(){
	int a[100], n , m;
	cout<<endl<<"Nhap gia tri gioi han: ";
	cin>>m;
	do{
		cout<<endl<<"Nhap so luong phan tu: ";	
		cin>>n;
		if(n>= m) cout<<endl<<"Nhap lai, n < m";	
	}while(n>=m);
	Nhaprandom(a,n,m);
	Xuat(a,n);
}
