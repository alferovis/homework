#include <iostream>
#include <string>
#include <cmath>
#include "vector.h"

using namespace std;

vector :: vector(int size, string id) {
	this->size = size;
	this->id = id;

	data = new double[size];
	for (int i = 0; i < size; i++) {
		data[i] = i+1;
	}
};

void vector :: print() {
	cout << id << " " << size << endl;
	for (int i = 0; i < size; i++) {
		cout << data[i] << " ";
	}
	cout << endl << endl;
};

void vector :: set_id(string id) {
	this->id = id;
};

void vector :: set_data(int size, double* data) {
	this->size = size;
	this->data = new double[size];
	for (int i = 0; i < size; i++) {
		this->data[i] = data[i];
	}
};

double vector :: norm2() {
	double n = 0;
	for (int i = 0 ; i < this->size; i++){
		n += this->data[i] * this->data[i];
	}
	return sqrt(n);
};

