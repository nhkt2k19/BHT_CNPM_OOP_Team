#include "Hoc_sinh.h"
#include <iostream>
using namespace std;
// ... khai báo thư viện, lớp, không gian tên 
int main()
{
	Lop_hoc lop(10);
	Hoc_sinh* a = new Hoc_sinh();
	delete a; // Phương thức phá hủy của lớp Hoc_sinh được gọi
	return 0;
}