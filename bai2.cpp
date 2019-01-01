#include <iostream>                  
using namespace std;
#include <string.h>
#include <windows.h>
struct xe{
	char Soxe[10];
	char Tenhang[20];
	xe *tiepxe;
};

struct con{
	char Manhankhau[5];
	char Hoten[20];
	con *tiepcon;
};

struct hk{
	char Sohk[5];
	char Hotench[20];
	char Diachi[30];
	xe *txe;
	con *tcon;
	hk *tiepho;
};

hk *dau;
void khoitao(hk *&dau){
	dau = NULL;
}

void Nhapxe(xe *&dauxe){
	xe *p, *q;
	char Soxetam[10];
	char Tenhangtam[20];
	do{
		cout<<endl<<"Nhap bang so xe: ";
		fflush(stdin);
		cin.getline(Soxetam,10);
			if(strcmp(Soxetam,"\0")!=0){
				p = new xe;
				strcpy(p ->Soxe, Soxetam);
				cout<<endl<<"Ten hang sang xuat: ";
				fflush(stdin);
				cin.getline(Tenhangtam,20);
				strcpy(p->Tenhang, Tenhangtam);
				p->tiepxe = NULL;
				if(dauxe == NULL)
					dauxe = p;
				else
					q ->tiepxe =p;
				q = p;
			}
	}while(strcmp(Soxetam,"\0")!=0);
}

void Nhapcon(con *&daucon){
	con *p, *q;
	char Manhankhautam[10];
	char Hotentam[20];
	do{
		cout<<endl<<"Nhap ma nhan khau cua con: ";
		fflush(stdin);
		cin.getline(Manhankhautam,10);
			if(strcmp(Manhankhautam,"\0")!=0){
				p = new con;
				strcpy(p ->Manhankhau, Manhankhautam);
				cout<<endl<<"Ho ten con: ";
				fflush(stdin);
				cin.getline(Hotentam,20);
				strcpy(p->Hoten, Hotentam);
				p->tiepcon = NULL;
				if(daucon == NULL)
					daucon = p;
				else
					q ->tiepcon =p;
				q = p;
			}
	}while(strcmp(Manhankhautam,"\0")!=0);
}

/*
Nhap danh sach cac ho
*/

void Nhapho(hk *&dau){
	hk *p, *q;
	char Sohktam[5];
	char Hotenchtam[20];
	char Diachitam[30];
	do{
		cout<<endl<<"Nhap so ho khau: ";
		fflush(stdin);
		cin.getline(Sohktam,5);
		if(strcmp(Sohktam,"\0")!=0){
			p = new hk;
			strcpy(p->Sohk,Sohktam);
			cout<<"Nhap ho ten chu ho: ";
			fflush(stdin);
			cin.getline(Hotenchtam,20);
			strcpy(p->Hotench, Hotenchtam);
			p->tcon = NULL;
			p->txe = NULL;
			Nhapcon(p->tcon);
			Nhapxe(p->txe);
			if(dau == NULL)
				dau = p;
				else q->tiepho = p;
			q = p;
		}
	}while(strcmp(Sohktam,"\0")!=0);
}

void Xuatxe(xe *dau){
	if(dau==NULL) return;
	xe *p;
	p = dau;
	while(p != NULL){
		cout<<endl;
		cout<<"So xe: "<<p->Soxe<<endl;
		cout<<"Ten hang: "<<p->Tenhang<<endl;
		p = p->tiepxe;	
	}
}
int Timxe(xe *p, char tent[20]){
    if(strcmp(p->Tenhang,tent) == 0) return 1;
    return 0;
	}


void Xuatcon(con *dau){
	if(dau == NULL) return;
	if(dau != NULL){
		cout<<endl;
		cout<<"Ma nhan khau cua con : "<<dau->Manhankhau<<endl;
		cout<<"Ten con: "<<dau->Hoten<<endl;
		Xuatcon(dau->tiepcon);
	}
}

void Xuatho(hk *dau){
	char shkt[5];
	hk *p;
	do{
	
	cout<<"Nhap so ho khau can xem: ";
	fflush(stdin);
	cin.getline(shkt,5);
		p=dau;
			while((p!=NULL) &&(strcmp(p->Sohk,shkt) != 0))
			p = p->tiepho;
		if(p == NULL) cout<<"Khong co, nhap lai "<<endl;
		else{
			cout<<endl<<"So ho khau: "<<p->Sohk;
			cout<<endl<<"Ho ten chu ho: "<<p->Hotench;
			cout<<endl<<"Cac xe cua ho: "<<endl;
			Xuatxe(p->txe);
			cout<<endl<<"Danh sach cac con: "<<endl;
			Xuatcon(p->tcon);
		}
	}while(p == NULL);
}

void Xoaxetheoso(hk *&dau,char x[10])
{
    char shkt[5];
	hk *q;
	do{
	
	cout<<"Nhap so ho khau can xoa xe: ";
	fflush(stdin);
	cin.getline(shkt,5);
		q=dau;
			while((q!=NULL) &&(strcmp(q->Sohk,shkt) != 0))
			q = q->tiepho;
	}while(q==NULL);
	cout<<endl<<"Nhap so xe can xoa: ";
	fflush(stdin);
	cin.getline(x,10);
    xe *truoc,*p; 
    p=q->txe;
    while((p!=NULL) && strcmp(p->Soxe,x) !=0)
    {
        truoc=p;
        p=p->tiepxe;
    }
    if(p!=NULL)
    {
        if(p==q->txe) q->txe=p->tiepxe;
        else truoc->tiepxe=p->tiepxe;
        delete p; 
}
}    


void Xuattheoxe(hk *dau){
    char tent[20];
	hk *p;
	do{
	
	cout<<endl<<"Nhap ten hang xe can xem: ";
	fflush(stdin);
	cin.getline(tent,20);
		p=dau;
		cout<<endl<<"Cac ho co xe "<<tent<<endl;
			while(p!=NULL){
				if(Timxe(p->txe,tent)){
					cout<<endl<<"So ho khau: "<<p->Sohk;
					cout<<endl<<"Ho ten chu ho: "<<p->Hotench;
					cout<<endl<<"Cac xe cua ho: "<<endl;
					Xuatxe(p->txe);
					cout<<endl<<"Danh sach cac con: "<<endl;
					Xuatcon(p->tcon);
		}
		p = p->tiepho;
		}
	}while(strcmp(tent,"\0") !=0);
}



int main(){
	khoitao(dau);
	Nhapho(dau);
	Xuatho(dau);
	Xuattheoxe(dau);
	char x[10];
	Xoaxetheoso(dau,x);
	Xuatho(dau);
	system("pause");
	return 0;
}

