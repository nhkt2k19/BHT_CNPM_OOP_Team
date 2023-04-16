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

public:
	Hoc_sinh() {
		cout << "Default constructor of Hoc_sinh has been called" << endl;
		MSSV = 0;
		ho_ten = "Unknown";
		toan = 0.0;
		van = 0.0;
		diemtb = 0.0;
	}
	Hoc_sinh(int id, string name, int diem_toan, int diem_van) {
		cout << "Parameterized constructor has been called" << endl;
		MSSV = id;
		ho_ten = name;
		toan = diem_toan;
		van = diem_van;
		Xuly(); // tính diemtb
	}
	Hoc_sinh(int id, string name) {
		MSSV = id;
		ho_ten = name;
		toan = 0.0;
		van = 0.0;
		Xuly(); // tính diemtb
	}
	Hoc_sinh(const Hoc_sinh& hs) {
		cout << "Copy constructor has been called" << endl;
		MSSV = hs.MSSV;
		ho_ten = hs.ho_ten;
		toan = hs.toan;
		van = hs.van;
		diemtb = hs.diemtb;
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


class Lop_hoc {
private:
	Hoc_sinh* arr;
	int size;
public:
	Lop_hoc(int size) {
		this->size = size;
		arr = new Hoc_sinh[size];
	}
	Lop_hoc(const Lop_hoc& temp) {
		this->arr = temp.arr;// sau bước này this->arr và temp.arr 
		                     // cùng trỏ vào một ô nhớ                  
		this->size = temp.size;
	}
	~Lop_hoc() { 

	}
};
