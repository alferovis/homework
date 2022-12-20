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

vector operator+(vector v, vector u) {
	vector w(v.size, "plus");
	for (int i = 0; i < v.size; i++){
		w.data[i] = v.data[i] + u.data[i];
	}
	return w;
};

vector operator*(double a, vector v){
	vector w(v.size, "mult");
	for (int i = 0; i < v.size; i++){
		w.data[i] = a * v.data[i];
        }
        return w;
};

vector operator-(vector v, vector u) {
	vector w(v.size, "minus");
	for (int i = 0; i < v.size; i++){
		w.data[i] = v.data[i] - u.data[i];
	}
	return w;
};


vector simple_iter(matrix A, vector b, double eps){
	vector x_prev(A.size);
	x_prev.set_data(b.size, b.data);
	vector x(A.size);
	vector y(A.size);
	
	int count = 0;
	double tau = 2 / A.norm_frob();
	double error = x_prev.norm2();
        while (error > eps){
		x = x_prev - tau * multiply(A, x_prev) + tau*b;		
		y = x - x_prev;
		error = y.norm2();
		x_prev = x;
		count += 1;
	}
	std::cout << count << std::endl;
	return x;
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

	vector b(2);
	double array[2] = {1, 1};
    b.set_data(2, array);
	b.print();
        
	matrix A(2, "matrix A");
	double** array2d = new double*[2];
    array2d[0] = new double[2]{3, 2};
    array2d[1] = new double[2]{0, 4};
    A.set_data(2, array2d);
    A.print();
	
	vector res(2);
	res = simple_iter(A, b, 0.0001);
	res.print();

	return 0;
}
