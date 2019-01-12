#include"iostream"
#include"string.h"
#include"vector"
#include"fstream"
#include"conio.h"
#include"stdlib.h"
using namespace std;

#define INFINITY 9999
struct cap{
	int x;
	int y;
};

//doc file
void Docfile(int a[][10], int &n){
	ifstream fi;
	fi.open("Matran.txt");
	fi>>n;
	for(int i=0; i<n; i++){
	 for(int j=0; j<n; j++)
	 fi>>a[i][j];
	 }
	fi.close();
}

void Xuatdothi( int a[][10],int n){
	
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++)
			cout<<a[i][j]<<" ";
		cout<<endl;
	}	
}
void Taomoi(int a[][10], int &n){
	
	cout<<"\nNhap n: "; cin>>n;
	ofstream fo;
	fo.open("Matranmoi.txt");
	fo<<n<<endl;
	for(int i=0; i<n; i++){
	  for(int j=0; j<n; j++){
	  
		
    	cout<<"Trong so "<<i<<" den "<<j<<": ";
    	cin>>a[i][j];
    	fo<<a[i][j]<<" ";
		}
			fo<<endl;

	}
}

void dijkstra(int a[][10], int n, int startnode)
{
	ofstream fi;
	fi.open("Ketqua.txt");
	int min = INFINITY;
	int vt; //vt la luu vt cua dinh den co duong di ngan nhat
	int cost[10][10], kc[10], nodetruoc[10];
	int trangthai[10], dem, minkc, nodetiep, i, j;

	//nodetruoc[] luu cac dinh ma khoang cach ngan nhat tu no den dinh nguon
	//dem dem so nut ma di qua den den dich
	//Tao ma tran trong so
	for (i = 0; i<n; i++)
		for (j = 0; j<n; j++)
			if (a[i][j] == 0)
				cost[i][j] = INFINITY;
			else
				cost[i][j] = a[i][j];

	//Khoi tao mang nodetruoc[],kc[] and trangthai[]
	for (i = 0; i<n; i++)
	{
		kc[i] = cost[startnode][i];
		nodetruoc[i] = startnode;
		trangthai[i] = 0;
	}

	kc[startnode] = 0;
	trangthai[startnode] = 1;
	dem = 1;

	while (dem<n - 1)
	{
		minkc = INFINITY;

		//Nut ke tiep co khoang cach nho nhat
		for (i = 0; i<n; i++)
			if (kc[i]<minkc && !trangthai[i])
			{
				minkc = kc[i];
				nodetiep = i;
			}

		//Kiem tra neu co duong dan tot hon: tinh lai khoang cach cac nut chua duoc tham      
		trangthai[nodetiep] = 1;
		for (i = 0; i<n; i++)
			if (!trangthai[i])
				if (minkc + cost[nodetiep][i]<kc[i])
				{
					kc[i] = minkc + cost[nodetiep][i];
					nodetruoc[i] = nodetiep;
				}
		dem++;
	}

	//In ra duong di va khoang cach den moi nut
	for (i = 0; i<n; i++)
		if (i != startnode)
		{
			if(min > kc[i]) {
				min = kc[i];
				vt = i;
			}
			
			cout<<"\nKhoang cach tu dinh "<<startnode<<" toi dinh "<<i<<" = "<<kc[i];
			cout<<"\n Duong di : "<<i;
			
			j = i;
			do
			{
				j = nodetruoc[j];
				cout<<" <- "<<j;
			} while (j != startnode);
		}
		
		if (vt != startnode)
		{
		
			cout<<"\n\nDuong di ngan nhat trong tat ca cac dinh la: ";
			cout<<"\nKhoang cach tu dinh "<<startnode<<" toi dinh "<<vt<<" = "<<kc[vt];
			fi<<"\nKhoang cach tu dinh "<<startnode<<" toi dinh "<<vt<<" = "<<kc[vt];
			cout<<"\n Duong di : "<<vt;
			fi<<"\n Duong di : "<<vt;			
			j = vt;
			do
			{
				j = nodetruoc[j];
				cout<<" <- "<<j;
				fi<<" <- "<<j;
			} while (j != startnode);
		}
	fi.close();
}



int main(){
	int n,x; //x la dinh xuat phat startnode
	int a[10][10];
	Docfile(a,n);
	Xuatdothi(a,n);
	
//	Taomoi(a,n);
//	Xuatdothi(a,n);

	cout<<"\nNhap dinh xuat phat: ";
	cin>>x;
	dijkstra(a,n,x);
	getch();
}
