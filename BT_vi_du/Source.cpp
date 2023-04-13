#include <iostream>
#include "Hoc_sinh.h"
using namespace std;
int main()
{
	DS_Hoc_sinh item2;
	{
		DS_Hoc_sinh item(4);
		item.Nhap();
		item.Xuat();
		item2 = item;
	}
	item2.Xuat();
	return 0;
}
