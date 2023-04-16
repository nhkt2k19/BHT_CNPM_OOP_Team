#include <iostream>
#include "Hoc_sinh.h"
using namespace std;
class Lop_hoc {
private:
	Hoc_sinh* arr;
	int size;
public:
	Lop_hoc(int size) {
		this->size = size;
		arr = new Hoc_sinh[size];
	}
};
