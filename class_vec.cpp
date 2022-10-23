#include <iostream>
#include <string>
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


class matrix{
	int size;
	string id;
	double** data2d;
public:
	matrix(int size, string id);
	void print();
};

matrix :: matrix(int size, string id = "unknown"){
	this->size = size;
	this->id = id;

	data2d = new double* [size];
	for (int i = 0; i <size; i++) {
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



int main(){
	cout << "Hello, world" << endl;
	
	vector v1(5, "first vector");
	vector v2(7);
	v1.print();
	v2.print();

	//cout << v1.size;

	matrix m(2, "first matrix");
	m.print();

	return 0;
}
