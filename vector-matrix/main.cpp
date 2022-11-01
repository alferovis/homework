#include <iostream>
#include <string>
#include "vector.h"
#include "matrix.h"
using namespace std;


vector multiply(matrix m, vector v) {
	vector res(m.size, "mult");
	for (int i = 0; i < m.size; i++) {
		res.data[i] = 0;
		for (int j = 0; j < v.size; j++) {
			res.data[i] += m.data2d[i][j] * v.data[j];
		}
	}
	return res;
};

vector operator+(vector v, vector u){
	vector w(v.size, "plus");
	for (int i = 0; i < v.size; i++){
		w.data[i] = v.data[i] + u.data[i];
	}
	return w;
};



int main(){
	cout << "Hello, world" << endl;
	
	vector v1(5, "first vector");
	vector v2(2, "second vector");
	v1.print();
	v2.print();

	vector v3(5);
	double arr[5] = {11, 12, 13, 14, 15};
	v3.set_data(5, arr);
	v3.print();
	//cout << typeid(v3).name() << " " << typeid(arr).name() << endl;

	//cout << v1.size;

	matrix m(2, "first matrix");
	m.print();
	double** arr2d = new double*[2];
	arr2d[0] = new double[2]{111, 112};
	arr2d[1] = new double[2]{113, 114};
	m.set_data(2, arr2d);
	m.print();
	
	cout << "testing multiplication" << endl;
	vector v4 = multiply(m, v2);
	v4.print();

	cout << "testing operator +" << endl;
	vector v5 = v1 + v3;
	v5.print();

	return 0;
}
