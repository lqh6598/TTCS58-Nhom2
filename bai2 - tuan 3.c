		   /*         CALENDAR
		   Code chay tren phan mem Turbo C++
		            */
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
#include <dos.h>

#define  gt  gotoxy
#define  tc  textcolor
#define  tb  textbackground

struct dosdate_t date ;
/*Hien thoi gian*/
void cur_time()
	{
	char *mer = (char *)malloc(2*sizeof(char)) ;
   while( !kbhit() ){
	    struct dostime_t t ;
	      _dos_gettime(&t) ;
	gt (28,21) ; tb( 0 )   ; tc(15) ;
	if (t.hour<12) mer = "AM" ;
	else strcpy (mer,"PM")    ;
	if (t.hour>12) t.hour = t.hour - 12 ;
	cprintf (" Current Time: %d:%02d:%02d  %s",t.hour,t.minute,t.second,mer) ;
	}
	}

void Event() ;

void main(){
	/*Dinh nghia cac thu trong tuan*/
	char *day[] = {"CN","2","3","4","5","6","7"} ;
	/*Dinh nghia cac thang*/
	char *month[] = {"T1","T2","T3","T4","T5","T6","T7","T8","T9","T10","T11","T12"} ;
	char ca[]="Lich " ;
	/*Tinh xem bao nhieu ngay mot thang*/
	long tdm[] = {31,28,31,30,31,30,31,31,30,31,30,31} ;
	long year,i,j,n,T,Startday,color,k=0,ch,endday,to,lastday ;
	tb(0)  ; window(0,0,80,25) ; clrscr() ; tc(15) ;
      gt(23,18); tc(3) ; cprintf(" Prepared by:")          ;
      gt(37,18); tc(10); cprintf("Le Quang Huy ")          ;
   start:
    _setcursortype(_NORMALCURSOR) ; tc(6) ;
     gt(18,10) ; cprintf("ษออออออออออออออออออออออออออออออออออป") ;
     gt(18,11) ; cprintf("บ                                  บ") ;
     gt(18,12) ; cprintf("วฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤถ") ;
     gt(18,13) ; cprintf("บ                                  บ") ;
     gt(18,14) ; cprintf("ศออออออออออออออออออออออออออออออออออผ") ;
   iy:
     gt(42,11) ; clreol() ;
     gt(53,11) ; tc(6)  ; cprintf("บ") ;
     gt(20,11) ; tc(15) ; cprintf("Nhap nam can xem:") ;
     gt(40,11) ; scanf("%ld",&year) ;
	if (year<=0 || year>=999999999) goto iy ;
   im:
     gt(40,13) ; clreol() ;
     gt(53,13) ; tc(6)  ; cprintf("บ") ;
     gt(20,13) ; tc(15) ; cprintf("Nhap thang can xem:") ;
     gt(40,13) ; scanf("%ld",&k) ;
       if (k<1 || k>12) goto im ;
       else k-- ;
	 _setcursortype(_NOCURSOR) ;
     clrscr();
      for (i=0;i<strlen(ca);i++) { gt(30+strlen(ca)-1-i,2) ; cprintf("%c",ca[strlen(ca)-1-i]) ; delay(30) ;}
      for (i=0;i<strlen(ca);i++) { gt(30+strlen(ca)-1-i,2) ; cprintf(" ") ; delay(30) ; }
      for (i=0;i<strlen(ca);i++) { gt(30+i,2) ; cprintf("%c",ca[i]) ; delay(30) ; }
     gt(47,2)  ; cprintf("%ld",year) ;
     tha:
	tb(14) ; tc(WHITE) ; gt(5,23);cprintf("  hap nam ") ;
	gt(43,23) ; cprintf(" L  trong nam ") ;
	gt(23,23) ; cprintf(" Ngay  om nay ")   ;
	gt(65,23) ; cprintf(" E it = Esc")     ;
	tc(10)    ;
	gt(6,23)  ; cprintf("N") ; gt(45,23) ; cprintf("e") ;
	gt(29,23) ; cprintf("H") ; gt(67,23) ; cprintf("x") ;
	tb(0)     ; tc(3) ;
	gt(6,24)  ; cprintf("฿฿฿฿฿฿฿฿฿฿฿฿")     ;
	gt(17,23) ; cprintf("Ü") ;
	gt(24,24) ; cprintf("฿฿฿฿฿฿฿฿฿฿฿฿฿฿")   ;
	gt(37,23) ; cprintf("Ü") ;
	gt(44,24) ; cprintf("฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿") ;
	gt(59,23) ; cprintf("Ü") ;
	gt(66,24) ; cprintf("฿฿฿฿฿฿฿฿฿฿฿฿")     ;
	gt(77,23) ; cprintf("Ü") ;
	gt(2,10)  ; cprintf("%c Tang nam" ,24) ;
	gt(65,10) ; cprintf("%c Tang thang",26) ;
	gt(2,12)  ; cprintf("%c Giam nam" ,25) ;
	gt(65,12) ; cprintf("%c Giam thang",27) ;
	tc(7)     ;
	gt(7,25)  ; cprintf("Prepared by: Le Quang Huy   ")   ;
   tt:
   tb(0) ; to=0 ; lastday = 0 ;
	/*Tinh ngay dau tien cua nam (1 T1)*/
     T = ((year-1)*365) + ((year-1)/4) - ((year-1)/100) + ((year-1)/400) + 1 ;
	   Startday = T % 7 ;
	/*Tinh nam co nhuan hay khong*/
      tdm[1]=(!((year%4) || !(year%100) && (year%400)))? 29 :  28 ;

      if(k>0)
	{ for (i=0;i<k;i++) to = to + tdm[i] ;
	  lastday = to % 7 ; }
	Startday = Startday + lastday ;
	_dos_getdate(&date) ;
	j = 0 ;  tb(0) ; tc(15) ;
	gt(47,2) ; clreol() ;
	gt(30,2) ; cprintf("Lich trong nam %ld",year) ;
	gt(36,3) ; cprintf(" ฤฤฤฤฤฤ") ;
	gt(39,4) ; cprintf("%s",month[k]) ;
	/*Ngay cuoi cung trong thang*/
	endday = tdm[k] ;

	tc(11)   ;
	gt(21,5) ; cprintf("ษอออออออออออออออออออออออออออออออออออออป") ;
	gt(21,6) ; cprintf("บ                                     บ") ;
	gt(21,7) ; cprintf("วฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤถ") ;
	gt(22,8) ; cprintf("                                     "  ) ;
	for (i=0;i<10;i++) { gt(21,10+i) ; cprintf("                                       "  ) ; }

	for (i=0;i<7;i++)
	      { if (i==0) color = 12 ;
		else color = 7 ;
		gt(24+5*i,6) ; tc(color) ; cprintf("%s",day[i]) ; }
	for(i=1;i<=endday;i++)
	      {	if(Startday>6) { Startday = Startday - 7 ; j++ ; }

		if(Startday==0) color = 12 ;
		else color = 7 ;
		/*Le trong nam*/
		if(year>1993)/*k+1 = thang' i = ngay`*/
			{
			if(k==0) if(i==1 ) color = 12;
			if(k==2) if(i==8) color = 12;
			if(k==3) if(i==1) color = 12;
			if(k==4) if(i==1) color = 12;
			if(k==5) if(i==1) color = 12;
			if(k==8) if(i==2) color = 12;
			if(k==9) if(i==20) color = 12;
			if(k==10) if(i==20) color = 12;
			if(k==11)if(i==22) color = 12 ;
			}
		if(Startday==0) color = 12 ;
		if(i==1) j = 0 ;
		/*Hien ngay hien tai*/
		((i==date.day) && ((k+1)==date.month) && (year==date.year)) ?
			tb(9) : tb(0) ;
		/*In ra lich cua thang*/
		gt(25+5*Startday,8+2*j) ; tc(color) ; cprintf("%ld",i) ;

		Startday++ ;
		}

	tc(11) ; tb(0) ;
	for (i=8;i<=8+2*j;i++) { gt(21,i) ; cprintf("บ") ;
				 gt(59,i) ; cprintf("บ") ; }
	gt(21,8+2*j+1) ; cprintf("ศอออออออออออออออออออออออออออออออออออออผ") ;
     again:
	cur_time() ;       /*Goi ham tinh thoi gian*/

	ch = getch() ;
	if(ch==77)
	      { if (k<11) k++ ;
		else { k=0 ; year++ ; }
		goto tt ; }
	else if(ch==72) { year++  ; goto tt ; }
	else if(ch==80) {
		if(year>1) year-- ; goto tt ; }
	else if(ch==75) {
		if(k>0) k = k - 1 ;
		else { if(year>1) { year-- ; k = 11 ; }
		       else k=0   ; }
		       goto tt    ; }
	else if(ch==27  || ch=='x' || ch=='X') exit(1) ;
	else if(ch=='h' || ch=='H') { k=date.month-1 ; year=date.year ; goto tt ; }
	else if(ch=='n' || ch=='N') { clrscr() ; goto start; }
	else if(ch=='e' || ch=='E') { Event() ; clrscr() ; goto tha ; }
	else goto again ;
	}
	
void Event ()
    {
    int i,j = 0 ;
    clrscr() ;
    tc(3) ; gt(3,5)  ; cprintf("ษ") ;
	    gt(78,5) ; cprintf("ป") ;
    for(i=0;i<74;i++) { gt(4+i,5) ; cprintf("อ") ; gt(4+i,21) ; cprintf("อ") ; }
    for(i=0;i<15;i++) { gt(3,i+6) ; cprintf("บ") ; gt(78,i+6) ; cprintf("บ") ;
			gt(41,i+6); cprintf("ณ") ; }
    gt(3,21) ; cprintf("ศ") ; gt(78,21) ; cprintf("ผ") ;
    gt(41,5) ; cprintf("ั") ; gt(41,21) ; cprintf("ฯ") ;
       tc(1) ; gt(7,7)  ; cprintf("1-T1 : ");
       tc(7) ; cprintf("Nam moi");
       tc(1) ; gt(7,9) ; cprintf("8-T3: ");
       tc(7) ; cprintf("Quoc te phu nu");
       tc(1) ; gt(7,11) ; cprintf("1-T4 : ");
       tc(7) ; cprintf("Ngay ca thang tu");
       tc(1) ; gt(7,13) ; cprintf("1-T5 : ");
       tc(7) ; cprintf("Quoc te lao dong");
       tc(1) ; gt(7,15) ; cprintf("1-T6 : ");
       tc(7) ; cprintf("Quoc te tre em");
       tc(1) ; gt(7,17) ; cprintf("2-T9 : ");
       tc(7) ; cprintf("Quoc Khanh");
       tc(1) ; gt(7,19) ; cprintf("20-T10 : ");
       tc(7) ; cprintf("Phu nu Viet Nam");
       tc(1) ; gt(44,7); cprintf("20-T11 : ");
       tc(7) ; cprintf("Nha giao Viet Nam") ;
       tc(1) ; gt(44,9); cprintf("22-T12 : ");
       tc(7) ; cprintf("Quan doi nhan dan Viet Nam") ;
       tc(14+BLINK) ; gt(28,24) ; cprintf("Nhan nut bat ky de tro lai.....") ;

    while(!kbhit()){
	if(i>15) i = 1 ;
	if(j>10) j = 0 ;
	tc(15) ; gt(34,4)  ; cprintf("    ออออออ     ") ;
	tc(i)  ; gt(34,3)  ; cprintf("Le trong nam") ;
	tc(j)  ; gt(35+j,4); cprintf("อ")               ;
	i++    ; j++       ; }
	}

