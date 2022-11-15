#ifndef VECT_H
#define VECT_H
	class matrix;

	class vector{
	private:
		int size;
		std::string  id;
		double* data;
	public:
		vector(int size, std::string id = "unknown");
		void print();
		void set_id(std::string id);
		void set_data(int size, double* data);
		friend class matrix;
		friend vector multiply(matrix m, vector v);
		friend vector operator+(vector v, vector u);
		friend vector operator-(vector v, vector u);
		friend vector operator*(double a, vector v);
		double norm2();
		friend vector simple_iter(matrix A, vector b, double eps);
	};
#endif

