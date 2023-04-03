#include <iostream>
#include <numeric>
using namespace std;

class Phan_so {
	friend istream& operator>>(istream&, Phan_so&);
	friend ostream& operator<<(ostream&, const Phan_so&);
private:
	int tu = 0;
	int mau = 1;
public:
	Phan_so() = default;
	Phan_so(int a, int b) {
		tu = a;
		mau = b;
	}
	Phan_so(const Phan_so& rhs) {
		this->mau = rhs.mau;
		this->tu = rhs.tu;
	}
	void operator= (const Phan_so& rhs) {
		this->mau = rhs.mau;
		this->tu = rhs.tu;
	}
	ostream& Print_double(ostream&);
	Phan_so reverse() const;
	Phan_so operator+ (const Phan_so&) const;
	Phan_so operator- (const Phan_so&) const;
	Phan_so operator/ (const Phan_so&) const;
	Phan_so operator* (const Phan_so&) const;
	~Phan_so() = default;
};

istream& operator>>(istream& is, Phan_so& ps) {
	is >> ps.mau >> ps.tu;
	return is;
}

ostream& operator<<(ostream& os, const Phan_so& ps) {
	os << ps.tu << "/" << ps.mau;
	return os;
}

ostream& Phan_so::Print_double(ostream& os) {
	double ps = (tu * 1.0) / (mau * 1.0);
	os << ps;
	return os;
}

Phan_so Phan_so::operator+ (const Phan_so& rhs) const {
	Phan_so ret;
	ret.tu = tu * rhs.mau + rhs.tu * mau;
	ret.mau = mau * rhs.mau;
	return ret;
}

Phan_so Phan_so::operator- (const Phan_so& rhs) const {
	Phan_so ret;
	ret.tu = tu * rhs.mau - rhs.tu * mau;
	ret.mau = mau * rhs.mau;
	return ret;
}

Phan_so Phan_so::operator* (const Phan_so& rhs) const {
	Phan_so ret;
	ret.tu = tu * rhs.tu;
	ret.mau = mau * rhs.mau;
	return ret;
}

Phan_so Phan_so::operator/ (const Phan_so& rhs) const {
	Phan_so ret;
	ret = (*this) * rhs.reverse();
	return ret;
}

int gcd(int a, int b) {
	if (b == 0) {
		return a;
	}
	return gcd(b, a % b);
}

Phan_so Phan_so::reverse() const {
	Phan_so ret(mau, tu);
	return ret;
}

