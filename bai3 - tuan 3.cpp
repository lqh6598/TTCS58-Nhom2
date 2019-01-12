#include <iostream>
using namespace std;
#include <fstream>
#include <stdlib.h>;
#include <string.h>
#include <windows.h>


struct Giaodich{
	bool Loai; // loai giao dich, true la gui tien, false la rut tien
	int Tien = 0;
};

struct Khachhang{
	char Ma[10];
	char Ten[30];
	int Sodu;
	Giaodich GD[1000];
	int SLGD = 0;
};



void NhapKH(Khachhang a[], int &n){ 
	int t, vt;
	vt = n;
	ifstream doc;
	doc.open("customer.txt");
	doc>>t;
	n += t;
	for(int i = vt; i < n; i++)
		{
			doc>>a[i].Ma;
			doc>>a[i].Sodu;
			fflush(stdin);
			doc.getline(a[i].Ten,30); 
		}
	doc.close();
}

void XuatKH(Khachhang a[], int n){
	ofstream ghi;
	ghi.open("customer.txt");
	ghi<<n;
	for(int i = 0; i < n; i++)
		{
			cout<<endl<<"Ma: "<<a[i].Ma;
			ghi<<endl<<a[i].Ma<<" "<<a[i].Sodu<<" "<<a[i].Ten;
			cout<<endl<<"Ten: "<<a[i].Ten;
			cout<<endl<<"So du: "<<a[i].Sodu;
		}
	
	ghi.close();
	
}

void ThemKH(Khachhang a[], int &n){
	n++;
	cout<<endl<<"Nhap thong tin khach hang can them: ";
	cout<<endl<<"Nhap ma: ";
	fflush(stdin);
	cin.getline(a[n-1].Ma,10);
	cout<<endl<<"Nhap ten: ";
	fflush(stdin);
	cin.getline(a[n-1].Ten,30);
	cout<<endl<<"Nhap so du: ";
	cin>>a[n-1].Sodu;
	
}


void Guitien(Khachhang a[], int n){
	char loai[10];
	fstream ghi;
	ghi.open("trans.txt", ios::out | ios::app);
	char ma[10];
	int temp, tam;
	int vt;
	int i;
	int money;
	do{	
	vt = -1;
	i = 0;
	cout<<endl<<"Nhap ma khach hang muon gui tien: ";
	fflush(stdin);
	cin.getline(ma,10);
	if(strcmp(ma,"\0") != 0){
	tam = atoi(ma);
	while(i < n){
		temp = atoi(a[i].Ma);
		if(tam == temp){
			vt = i;
			break;
		}
		i++;
	}
	if (vt == -1) {
		cout<<endl<<"Khong co khach hang, nhap lai";
	}
	else{		
		do{
		cout<<endl<<"Nhap so tien muon gui: ";
		cin>>money;	
		}while(money > a[vt].Sodu);
		a[vt].SLGD++;
		for(int j = 0; j < a[vt].SLGD; j++)
			if(a[vt].GD[j].Tien == 0){
				a[vt].GD[j].Loai = true;
				a[vt].GD[j].Tien = money;
				a[vt].Sodu += money;
				ghi<<"Ma: "<<a[vt].Ma<<",  Loai giao dich: gui tien,  So tien gui: "<<a[vt].GD[j].Tien<<endl;
			}
		}
	}
	}while(strcmp(ma,"\0") != 0);
	ghi.close();
}


void Ruttien(Khachhang a[], int n){
	char loai[10];
	fstream ghi;
	ghi.open("trans.txt", ios::out | ios::app);
	char ma[10];
	int temp, tam;
	int vt;
	int i;
	int money;
	do{	
	vt = -1;
	i = 0;
	cout<<endl<<"Nhap ma khach hang muon rut tien: ";
	fflush(stdin);
	cin.getline(ma,10);
	if(strcmp(ma,"\0") != 0){
	tam = atoi(ma);
	while(i < n){
		temp = atoi(a[i].Ma);
		if(tam == temp){
			vt = i;
			break;
		}
		i++;
	}
	if (vt == -1) {
		cout<<endl<<"Khong co khach hang, nhap lai";
	}
	else{		
		cout<<endl<<"Nhap so tien muon rut: ";
		cin>>money;	
		a[vt].SLGD++;
		for(int j = 0; j < a[vt].SLGD; j++)
			if(a[vt].GD[j].Tien == 0){
				a[vt].GD[j].Loai = false;
				a[vt].GD[j].Tien = money;
				a[vt].Sodu -= money;
				ghi<<"Ma: "<<a[vt].Ma<<",  Loai giao dich: rut tien,  So tien rut: "<<a[vt].GD[j].Tien<<endl;
			}
		}
		}
	}while(strcmp(ma,"\0") != 0);
	ghi.close();
}

void GiaodichKH(Khachhang a[], int n){
	
	int i, vt;
	char ma[10];
	int tam, temp;
	char loai[10];
	do{
		i = 0;
		vt = -1;
		cout<<endl<<"Nhap ma khach hang can in: ";
		fflush(stdin);
		cin.getline(ma,10);
		if(strcmp(ma,"\0") != 0){
			tam = atoi(ma);
			while(i < n){
				temp = atoi(a[i].Ma);
				if(tam == temp){
					vt = i;
					break;
				}
				i++;
			}
			if(vt == -1) cout<<endl<<"Khong co khach hang";
			else{
				if(a[vt].SLGD == 0) cout<<endl<<"Khong co giao dich";
				else{
					for(int j = 0; j < a[vt].SLGD; j++){
						if(a[vt].GD[j].Loai == true) strcpy(loai,"gui tien");
						else strcpy(loai,"rut tien");
						cout<<endl<<"Ma: "<<a[vt].Ma<<",  Loai giao dich: "<<loai<<",  So tien: "<<a[vt].GD[j].Tien;
					}
					
				}
				
			}
		}
	}while(strcmp(ma,"\0") != 0);
	
}

void Sapxep(Khachhang a[], int n){
	int tam, temp;
	for(int i = 0; i < n-1; i++)
		{
			tam = atoi(a[i].Ma);
			for(int j = i+1; j < n; j++)
				{
					temp = atoi(a[j].Ma);
					if(tam > temp) swap(a[i],a[j]);
				}
		}
	
}


void menu(){
	cout<<endl<<"---------------Menu-------------";
	cout<<endl<<"1. Nhap thong tin tu file";
	cout<<endl<<"2. Xuat thong tin khach hang";
	cout<<endl<<"3. Them khach hang";
	cout<<endl<<"4. Gui tien";
	cout<<endl<<"5. Rut tien";
	cout<<endl<<"6. In giao dich cua 1 khach hang";
	cout<<endl<<"7. Sap xep (theo ma khach hang)";
	cout<<endl<<"8. Ket thuc";
	cout<<endl<<"---------------------------------";
	cout<<endl<<endl;
}


int main(){
	Khachhang a[100];
	int n = 0;
	int thaotac;
	ofstream tao;
	tao.open("trans.txt");
	tao<<"";
	tao.close();
	menu();
	do{
		cout<<endl<<"Nhap thao tac muon thuc hien: ";
		cin>>thaotac;
		if(thaotac > 0 || thaotac < 8){
			if(thaotac == 1){
				system("cls");
				NhapKH(a,n);
				menu();
			}
			else if(thaotac == 2){
				XuatKH(a,n);
				cout<<endl;
				system("pause");
				system("cls");
				menu();
			}
			else if(thaotac == 3){
				ThemKH(a,n);
				cout<<endl;
				system("pause");
				system("cls");
				menu();
			}
			else if(thaotac == 4){
				Guitien(a,n);
				cout<<endl;
				system("pause");
				system("cls");
				menu();
			}
			else if(thaotac == 5){
				Ruttien(a,n);
				cout<<endl;
				system("pause");
				system("cls");
				menu();
			}
			else if(thaotac == 6){
				GiaodichKH(a,n);
				cout<<endl;
				system("pause");
				system("cls");
				menu();
			}
			else if(thaotac == 7){
				Sapxep(a,n);
				cout<<endl;
				system("pause");
				system("cls");
				menu();
			}
			else break;
		}
		else cout<<endl<<"Nhap lai";
	}while(thaotac < 9);

	
}

