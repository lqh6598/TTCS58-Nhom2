/*Chuong trinh chay tren phan mem Turbo C++*/

#include<stdio.h>
#include<conio.h>
#include<dos.h>

int Nhap1kitu()
{
union REGS regs;
int x=0;
int temp;
do
{
regs.h.ah=01; // khai bao thanh ghi su dung ham 01 cua ngat 21h
int86(0x21,&regs,&regs); // dinh dang ngay 21h
temp=regs.h.al; // dia chi al cua thanh ghi
if(temp==0x0D) 
goto EXIT;
temp -=0x30;
x=x*10+temp;
EXIT:
}while(temp!=13);
return x;
}

void Xuat1kitu(int x)
{
union REGS regs;
regs.h.ah=02;
x+=0x30;
regs.h.dl=x; // dia chi dl cua thanh ghi
int86(0x21,&regs,&regs);
}

int Nhapkitu()
{
union REGS regs1;
int y=0;
long temp;
regs1.h.ah=10;
int86(0x21,&regs1,&regs1);
temp=regs1.x.dx;
return temp;
}

void Xuatkitu(int y)
{
union REGS regs1;
regs1.h.ah=09;
regs1.x.dx=y;
int86(0x21,&regs1,&regs1);
}



int main()
{
int x;
printf ("\n Nhap mot so (tu 0 den 9):");
x=Nhap1kitu();
printf("\n So vua nhap la: ");
Xuat1kitu(x);
getch();
}


