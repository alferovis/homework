#include <iostream>
#include <string>
#include "matrix.h"
#include <cmath>

using namespace std;

matrix :: matrix(int size, string id = "unknown") {
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

double matrix :: norm_frob() {
	double n = 0;
	for (int i = 0 ; i < this->size; i++){
		for (int j = 0; j < this->size; j++){
			n += this->data2d[i][j] * this->data2d[i][j];
		}
	}
	return sqrt(n);
};

