#include <iostream>
using namespace std;

class Complex {
public:
	Complex() {real = 0; imag = 0;}
	Complex(int a, int b) { real = a; real = b; }
	~Complex() {}
	void get_Complex();
	void display();
	void fuhao();
	friend Complex* operator+(Complex& c1, Complex& c2);
	friend Complex* operator-(Complex& c1, Complex& c2);
	friend Complex* operator*(Complex& c1, Complex& c2);
private:
	double real;
	char imag_fuhao;
	double imag;
	int pt_y_n=0;
};
void Complex::get_Complex() {
	int a, b;
	cout << "请输入实部和虚部的值：";
	cin >> real>>imag;
	fuhao();
}
void Complex::display() {
	cout  << real << imag_fuhao << imag << 'i' << endl;
}
void Complex :: fuhao() {
	if (imag >= 0)imag_fuhao = '+';
	else imag_fuhao = 0;
}
Complex* operator+(Complex& c1, Complex& c2) {
	Complex* pt = new Complex;
	pt->real = c1.real + c2.real;
	pt->imag = c1.imag + c2.imag;
	pt->pt_y_n = 1;
	pt->fuhao();
	cout << "相加后的结果如下:";
	pt->display();
	return pt;
}
Complex* operator-(Complex& c1, Complex& c2) {
	Complex* pt = new Complex;
	pt->real = c1.real - c2.real;
	pt->imag = c1.imag - c2.imag;
	pt->pt_y_n = 1;
	pt->fuhao();
	cout << "相减后的结果如下:";
	pt->display();
	return pt;
}
Complex* operator*(Complex& c1, Complex& c2) {
	Complex* pt = new Complex;
	pt->real = c1.real*c2.real-c1.imag*c2.imag;
	pt->imag = c1.imag*c2.real-c1.real*c2.imag;
	pt->pt_y_n = 1;
	pt->fuhao();
	cout << "相乘后的结果如下:" ;
	pt->display();
	cout << endl;
	return pt;
}
int main() {
	int Statues = 1;
	while (Statues) {
		Complex c1, c2,* c3;
		c1.get_Complex();
		c2.get_Complex();
		c3 = c1 + c2;
		c3 = c1 - c2;
		c3 = c1 * c2;
		delete c3;
	}
	return 0;
}