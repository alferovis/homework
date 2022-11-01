#ifndef MATR_H
#define MATR_H
class vector;

class matrix{
private:
        int size;
        std::string id;
        double** data2d;
public:
        matrix(int size, std::string id);
        void print();
        void set_data(int size, double** data2d);
        friend class vector;
        friend vector multiply(matrix m, vector v);
};
#endif
