#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Hoc_sinh {
private:
	int MSSV;
	string ho_ten;
	double toan;
	double van;
	double diemtb;
	void Xuly();
protected:
public:
	Hoc_sinh() {
		cout << "Default constructor of Hoc_sinh has been called" << endl;
		MSSV = 0;
		ho_ten = "";
		toan = 0.0;
		van = 0.0;
		diemtb = 0.0;
	}
	double get_toan();
	void set_toan(double);
	void Nhap();
	void Xuat();
};

void Hoc_sinh::Xuly() {
	diemtb = (toan + van) / 2;
}

void Hoc_sinh::Nhap() {
	cout << "Nhap MSSV: ";
	cin >> MSSV;
	cout << "Nhap ho ten: ";
	cin.ignore();
	getline(cin, ho_ten);
	cout << "Nhap diem toan: ";
	cin >> toan;
	cout << "Nhap diem van: ";
	cin >> van; 
	this->Xuly();
}

void Hoc_sinh::Xuat() {
	cout << MSSV << endl << ho_ten << endl << toan << endl << van << endl << diemtb;
}

double Hoc_sinh::get_toan() {
	return toan;
}
void Hoc_sinh::set_toan(double toan) {
	if (toan > 10 || toan < 0) {
		cout << "ERROR: điểm toán không được lớn hơn 10 hoặc bé hơn 0" << endl;
		return;
	}
	this->toan = toan;
	this->Xuly(); // tính lại điểm trung bình
}

class DS_Hoc_sinh {
public:
	DS_Hoc_sinh() {
		cout << "Default constructor of DS_Hoc_sinh has been called" << endl;
		size = 0;
		arr = NULL;
	}
	DS_Hoc_sinh(int size) {
		cout << "Specialized constructor of DS_Hoc_sinh has been called" << endl;
		this->size = size;
		arr = new Hoc_sinh[size];
	}
	DS_Hoc_sinh(const DS_Hoc_sinh& rhs) {
		cout << "Copy constructor of DS_Hoc_sinh has been called" << endl;
		size = rhs.size;
		arr = new Hoc_sinh[size];
		for (int i = 0; i < size; ++i) {
			arr[i] = rhs.arr[i];
		}
	}
	DS_Hoc_sinh& operator= (const DS_Hoc_sinh& rhs) {
		cout << "Assignment operator of DS_Hoc_sinh has been called" << endl;
		delete[] arr;
		size = rhs.size;
		arr = new Hoc_sinh[size];
		for (int i = 0; i < size; ++i) {
			arr[i] = rhs.arr[i];
		}
		return *this;
	}
	void Nhap() {
		for (int i = 0; i < size; ++i) {
			cout << "Nhap du lieu hoc sinh thu " << i+1 << " :" << endl;
			arr[i].Nhap();
		}
	}
	void Xuat() {
		for (int i = 0; i < size; ++i) {
			arr[i].Xuat();
			cout << endl;
		}
	}
	~DS_Hoc_sinh() {
		cout << "Destructor has been called" << endl;
		delete[] arr;
	}
	//test;
private:
	Hoc_sinh* arr;
	int size;
	//test;
	//test2;
	//test3;
};

