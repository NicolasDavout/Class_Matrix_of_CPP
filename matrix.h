#pragma once
#include<vector>
#include<iostream>
#include<iomanip>
#include<string>
using namespace std;

vector<vector<double>*>* new_mat(int, int);
template<typename T>
void DEL_NUMELE_VEC(vector<T>&, int);

template<typename T>
void INST_NUMELE_BEFVEC(vector<T>&, int, T);

class matrix
{
public:
	//Constructor
	matrix() :col(0), row(0) { this->mat = NULL; }
	matrix(int, int);
	matrix(matrix &);

	//Destructor
	virtual ~matrix();
	
	//Get the count of rows or columns
	int Get_row() { return this->row; }
	int Get_col() { return this->col; }

	//Print this matrix on console
	void Print_matrix();

	//Initialize
	void Init(int,vector<double>);//Initialize/modify a row
	void InitByKeyBoard();//Initialize by entering from keyboard

	//Delete a certain row or column
	void Del_row(int);
	void Del_col(int);

	//Insert a row or column before row or column N. if N is equal to [the size of vector + 1], this row or column will be inserted at the end.
	void Insert_row_before(int N);
	void Insert_col_before(int N);

	//Return a certain row or column encapsulated in vector
	vector<double> ROW(int);
	vector<double> COL(int);

	//Modifying the matrix
	void MDF_element(int, int, double);//Modify a certian element
	void CLR_matrix();//Set all of the elements to 0
	void Unitize();//Make it as an identity matrix

	//Return the rank and value of the determinant
	int rank();
	double det();

	//Return a matrix transposed or inversed by this matrix
	matrix& Transpose();
	matrix& Inverse();

	//Basic transformation of a matrix
	void Row_Mtp(int ROW, double k);//Mutiply a row by k
	void Col_Mtp(int COL, double k);//Mutiply a column by k
	void Row_Mtp_Add(int Row_1, int Row_2, double k = 1);//Add elements of Row_1 multiplied by k to Row_2
	void Col_Mtp_Add(int Col_1, int Col_2, double k = 1);//Add elements of Col_1 multiplied by k to Col_2
	void Row_Exchange(int Row_1, int Row_2);//Exchange ROW_1 with ROW_2
	void Col_Exchange(int Col_1, int Col_2);//Exchange COL_1 with COL_2

	//Operators of matrix
	friend matrix& operator+(matrix, matrix);
	friend matrix& operator-(matrix, matrix);
	friend matrix& operator*(matrix, matrix);
	friend matrix& operator*(double, matrix);
	void operator=(matrix);
	
private:
	bool CRIsValid();
	void SINK(int);
	void Stepwise();
	void match();
	friend matrix& Minor(matrix, int, int);
	int row;
	int col;
	vector<vector<double>*>* mat;
};

