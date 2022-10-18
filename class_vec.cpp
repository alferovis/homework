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
	cout << endl;
};

void vecotr :: set_id(int size){
	this->id = id;
}

int main(){
	cout << "Hello, world" << endl;
	
	vector v1(5, "first vector");
	vector v2(7);
	v1.print();
	v2.print();

	cout << v1.size;
	return 0;
}
