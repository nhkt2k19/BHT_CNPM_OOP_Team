#include <iostream>
#include "Hoc_sinh.h"
using namespace std;
int main()
{
	Lop_hoc item1(3);
	{
		Lop_hoc item2 = item1; // Copy constructor do chương trình 
                               // tự định nghĩa được gọi
	}                          // Destructor được gọi trên item2
	item1.Xuat();              // lỗi! item1 bây giờ bị mất vùng nhớ
	//item2.Xuat();
	//hs.Xuat();
	//Hoc_sinh arr[5];
	//Hoc_sinh hs(22520971, "Le Duy Nguyen", 8, 7);
	//hs.Xuat(); 
	//Hoc_sinh hs2 = hs;
	//hs2.Xuat();
	//Hoc_sinh arr[2] = {hs};
	//int n = 5;
	//Hoc_sinh* a = new Hoc_sinh[n];
	//delete[] a;
	return 0;
}
