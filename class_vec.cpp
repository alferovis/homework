#include <iostream>
#include <string>
#include <typeinfo>
using namespace std;

class vector{
private:
	int size;
	string  id;
	double* data;
public:
	vector(int size, string id);
	void print();
	void set_id(string id);
	void set_data(int size, double* data);
};

vector :: vector(int size, string id = "unknown") {
	this->size = size;
	this->id = id;

	data = new double[size];
	for (int i = 0; i < size; i++) {
		data[i] = i+1;
	}
};

void vector :: print(){
	cout << id << " " << size << endl;
	for (int i = 0; i < size; i++) {
		cout << data[i] << " ";
	}
	cout << endl << endl;
};

void vector :: set_id(string id){
	this->id = id;
};

void vector :: set_data(int size, double* data) {
	this->size = size;
	this->data = new double[size];
	for (int i; i < size; i++) {
		this->data[i] = data[i];
	}
};


class matrix{
	int size;
	string id;
	double** data2d;
public:
	matrix(int size, string id);
	void print();
	void set_data(int size, double** data2d);
};

matrix :: matrix(int size, string id = "unknown"){
	this->size = size;
	this->id = id;

	data2d = new double* [size];
	for (int i = 0; i < size; i++) {
		data2d[i] = new double [size];
	}
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			data2d[i][j] = (i+1)*(j+1);
		}
	}
};

void matrix :: print() {
	cout << id << " " << size << endl;
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			cout << data2d[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
};

void matrix :: set_data(int size, double** data2d) {
	this->size = size;
	this->data2d = new double*[size];

	for (int i = 0; i < size; i++){
		this->data2d[i] = new double[size];
		for (int j = 0; j < size; j++) {
			this->data2d[i][j] = data2d[i][j];
		}
	}
};

/*vector multiply(matrix m, vector v) {
	vector w(5);
	return w;
}*/


int main(){
	cout << "Hello, world" << endl;
	
	vector v1(5, "first vector");
	vector v2(7);
	v1.print();
	v2.print();

	vector v3(5);
	double arr[6] = {10, 11, 12, 13, 14, 15};
	v3.set_data(6, arr);
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

	return 0;
}
