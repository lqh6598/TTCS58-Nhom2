#include <iostream>
using namespace std; 
#include <iterator>
#include <string>
#include <vector>
#include <windows.h>

template<typename Mang>
void Xuat(Mang& A){
    size_t n = A.size();
    for(int i = 0; i<n; i++)
        cout<<A[i]<<" ";
}

void SetTexColor(WORD color)
{ 
    HANDLE hConsoleOutput;
    hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO screen_buffer_info;
    GetConsoleScreenBufferInfo(hConsoleOutput, &screen_buffer_info);
    WORD wAttributes = screen_buffer_info.wAttributes;
    color &= 0x000f;
    wAttributes &= 0xfff0; wAttributes |= color;
    SetConsoleTextAttribute(hConsoleOutput, wAttributes);
}

template<typename Mang>
void heap(Mang& A, size_t i, size_t n)
{
  
  size_t left=2*i+1, right=2*i+2;
  if (right >= n) return;
              
  if ((A[left] > A[right]) && (A[left] > A[i]))
  {
  	  cout<<endl;
	  cout<<endl<<"A["<<i<<"] : "<<A[i];
      cout<<endl<<"A["<<left<<"] : "<<A[left];
      cout<<endl<<"A["<<right<<"] : "<<A[right];
      swap(A[i], A[left]);
      cout<<endl<<"Hoan vi A["<<i<<"] va A["<<left<<"]: ";
      Xuat(A);
      heap(A, left, n);
  }
  else if(A[right] > A[i]) 
  {
  	  cout<<endl;
      cout<<endl<<"A["<<i<<"] : "<<A[i];
      cout<<endl<<"A["<<left<<"] : "<<A[left];
      cout<<endl<<"A["<<right<<"] : "<<A[right];
      swap(A[i], A[right]);
      cout<<endl<<"Hoan vi A["<<i<<"] va A["<<right<<"]: ";
      Xuat(A);
      heap(A, right, n);
  }
}

template<typename Mang>
void heapsort(Mang& A)
{

	size_t n = A.size();
	for (int i=(n/2)-1; i>=0; --i) {
	heap(A, i, n-1);
  }
	for (int i=n-1; i>0; --i) 
  {
		if(A[i] < A[0]){
			SetTexColor(4);
    		cout<<endl<<"Dua goc ve vi tri   : ";
    		swap(A[i], A[0]);
    		SetTexColor(7);
	}
    	else {
 		    SetTexColor(5);
 			cout<<endl<<"Giu nguyen vi A["<<i<<"] lon hon A[0], i--"<<endl;
 		    SetTexColor(7);
		 	
	}
    Xuat(A);
    heap(A, 0, i);
  }
}


int main()
{
  vector<int> phantu= {9,23,20,18,14,17,13,11,10,5,7,3,2,26,27};
  Xuat(phantu);
  heapsort(phantu); 
  return 0;
}
