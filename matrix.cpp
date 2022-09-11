#include "matrix.h"

//new_mat
vector<vector<double>*>* new_mat(int ROW, int COLUMN)
{
	vector<vector<double>*>* TEM_P = new vector<vector<double>*>;
	for (int i = 0; i < ROW; i++)
	{
		vector<double>* unit = new vector<double>;
		for (int j = 0; j < COLUMN; j++)
		{
			unit->push_back(0);
		}
		TEM_P->push_back(unit);
	}
	return TEM_P;
}

//DEL_NUMELE_VEC
template<typename T>
void DEL_NUMELE_VEC(vector<T>& X, int COUNT)
{
	typename vector<T>::iterator ite = X.begin();
	for(int i = 0; i < COUNT - 1; i++)
	{
		ite++;
	}
	X.erase(ite);
}

//INST_NUMELE_BEFVEC
template<typename T>
void INST_NUMELE_BEFVEC(vector<T>& X, int COUNT, T ELE)
{
	typename vector<T>::iterator ite = X.begin();
	for (int i = 0; i < COUNT - 1; i++)
	{
		ite++;
	}
	X.insert(ite, ELE);
}

//Constructer with row and column
matrix::matrix(int ROW, int COLUMN)
{
	if ((ROW>=0) && (COLUMN>=0))
	{
		this->row = ROW;
		this->col = COLUMN;
	}
	else
	{
		this->row = 0;
		this->col = 0;
	}
	if (CRIsValid())
	{
		this->mat = new_mat(ROW, COLUMN);
	}
	
	
}

//Copy constructer
matrix::matrix(matrix& COPIED)
{
	this->row = COPIED.row;
	this->col = COPIED.col;
	this->mat = new_mat(COPIED.row, COPIED.col);
	for (int i = 0; i < this->row; i++)
	{
		this->Init(i + 1, COPIED.ROW(i+1));
	}
}

//Destructor
matrix::~matrix()
{
	vector<double>* DESTROYER_ROW;
	for (int i = 0; i < row; i++)
	{
		DESTROYER_ROW = (*(this->mat))[i];
		delete DESTROYER_ROW;
	}
	delete this->mat;
	this->mat = NULL;
}


//CRIsValid
bool matrix::CRIsValid()
{
	if ((this->col <= 0) || (this->row <= 0))
	{
		return 0;
	}
	else
	{
		return 1;
	}
}

//Del_row
void matrix::Del_row(int ROW)
{
	if ((ROW > 0)&&(ROW <= this->row))
	{
		delete (*(this->mat))[ROW - 1];
		DEL_NUMELE_VEC(*(this->mat), ROW);
		if (this->row <= 1)
		{
			this->row = 0;
			this->col = 0;
		}
		else
		{
			match();
		}
	}
}

//Del_col
void matrix::Del_col(int COLUMN)
{
	if ((COLUMN > 0) && (COLUMN <= this->col))
	{
		vector<vector<double>*>::iterator ite;
		for (ite = (this->mat)->begin(); ite != (this->mat)->end(); ite++)
		{
			DEL_NUMELE_VEC(**ite, COLUMN);
		}
		if (this->col <= 1)
		{
			this->row = 0;
			this->col = 0;
		}
		else
		{
			match();
		}
	}
}

//match
void matrix::match()
{
	if ((this->mat->size()==0) || ((*(this->mat))[0]->size()) == 0)
	{
		this->row = 0;
		this->col = 0;
	}
	else
	{
		this->row = this->mat->size();
		this->col = (*(this->mat))[0]->size();
	}
}

//Print_matrix
void matrix::Print_matrix()
{
if (this->CRIsValid() == 1)
{
	for (int i = 0; i < this->row; i++)
	{
		if (i == 0)
		{
			cout << "┏━";
		}
		else
		{
			if (i == this->row - 1)
			{
				cout << "┗━";
			}
			else
			{
				cout << "┃ ";
			}
		}

		for (int j = 0; j < this->col; j++)
		{
			cout << setw(10) << (*((*(this->mat))[i]))[j] << setw(10);
		}
		if (i == 0)
		{
			cout << "━┓" << endl;
		}
		else
		{
			if (i == this->row - 1)
			{
				cout << "━┛" << this->row << "×" << this->col << endl;
			}
			else
			{
				cout << setw(9) << "┃" << endl;
			}
		}
	}
}
else
{
	cout << "ERROR: Print matrix failed, 0 row and 0 column." << endl;
}
}

//Init
void matrix::Init(int ROW, vector<double> DATA)
{
	if (DATA.size() == this->col)
	{
		*((*(this->mat))[ROW - 1]) = DATA;
	}
}

//InitByKeyBoard
void matrix::InitByKeyBoard()
{
	if (this->CRIsValid())
	{
		cout << "Enter the data of matrix with " << this->row << " row " << this->col << " column:" << endl;
		for (int i = 0; i < this->row; i++)
		{
			vector<double> COL_VEC;
			for (int j = 0; j < this->col; j++)
			{
				double element;
				cin >> element;
				COL_VEC.push_back(element);
			}
			Init(i + 1, COL_VEC);
		}
	}
	else
	{
		cout << "Invalid Matrix" << endl;
	}
}

//ROW
vector<double> matrix::ROW(int N)
{
	vector<double> r;
	r = *(*(this->mat))[N - 1];
	return r;
}

//COL
vector<double> matrix::COL(int N)
{
	vector<double> c;
	vector<vector<double>*>::iterator ite;
	for (ite = (this->mat)->begin(); ite != (this->mat)->end(); ite++)
	{
		c.push_back((**ite)[N - 1]);
	}
	return c;
}

//Insert_row_before
void matrix::Insert_row_before(int N)
{
	if ((N > 0) && (N <= (this->row + 1)))
	{
		vector<double>* p = new vector<double>;
		for (int i = 0; i < this->col; i++)
		{
			p->push_back(0);
		}
		INST_NUMELE_BEFVEC(*(this->mat), N, p);
		this->match();
	}
}

//Insert_col_before
void matrix::Insert_col_before(int N)
{
	if ((N > 0) && (N <= (this->col + 1)))
	{
		vector<vector<double>*>::iterator ite;
		for (ite = (this->mat)->begin(); ite != (this->mat)->end(); ite++)
		{
			INST_NUMELE_BEFVEC(**ite, N, 0.0);
		}
		match();
	}
}

//Transpose
matrix& matrix::Transpose()
{
	if (this->CRIsValid())
	{
		matrix* p = new matrix(this->col, this->row);
		for (int i = 0; i < this->col; i++)
		{
			p->Init(i + 1, this->COL(i + 1));
		}
		p->match();
		return *p;
	}
	else
	{
		matrix* p = new matrix(this->col, this->row);
		return *p;
	}
}

//det
double matrix::det()
{
	if ((this->row) != (this->col))
	{
		return 1.79769e+308;
	}
	else
	{
		int Order = this->row;
		if (Order == 1)
		{
			return (*((*(this->mat))[0]))[0];
		}
		else
		{
			double SUM = 0;
			for (int i = 0; i < Order; i++)
			{
				matrix MINOR = Minor(*this, 1, i + 1);
				if (i % 2 == 0)
				{
					SUM += (*((*(this->mat))[0]))[i] * MINOR.det();
				}
				else
				{
					SUM -= (*((*(this->mat))[0]))[i] * MINOR.det();
				}
				
			}
			return SUM;
		}
	}
}

//operator=
void matrix::operator=(matrix COPIED)
{
	for (int i = 0; i < this->row; i++)
	{
		delete (*(this->mat))[i];
	}
	delete this->mat;
	this->row = COPIED.row;
	this->col = COPIED.col;

	this->mat = new_mat(row, col);
	vector<vector<double>*>::iterator ite;
	for (int i = 0; i < this->row; i++)
	{
		this->Init(i + 1, COPIED.ROW(i + 1));
	}
}

//operator+
matrix& operator+(matrix A, matrix B)
{
	if ((A.row == B.row) && (A.col == B.col))
	{
		matrix* p = new matrix(A.row, A.col);
		for (int i = 0; i < A.row; i++)
		{
			for (int j = 0; j < A.col; j++)
			{
				(*((*(p->mat))[i]))[j] = (*((*(A.mat))[i]))[j] + (*((*(B.mat))[i]))[j];
			}
		}
		return *p;
	}
	else
	{
		matrix* p = new matrix(1,1);
		return *p;
	}
}

//operator-
matrix& operator-(matrix A, matrix B)
{
	if ((A.row == B.row) && (A.col == B.col))
	{
		matrix* p = new matrix(A.row, A.col);
		for (int i = 0; i < A.row; i++)
		{
			for (int j = 0; j < A.col; j++)
			{
				(*((*(p->mat))[i]))[j] = (*((*(A.mat))[i]))[j] - (*((*(B.mat))[i]))[j];
			}
		}
		return *p;
	}
	else
	{
		matrix* p = new matrix(1, 1);
		return *p;
	}
}

//operator*
matrix& operator*(matrix A, matrix B)
{
	matrix* p = new matrix(A.row, B.col);
	p->CLR_matrix();
	int ELE_SUM = A.col;
	if ((A.col != B.row)||(A.CRIsValid()==0)|| (B.CRIsValid() == 0))
	{
		return *p;
	}
	else
	{
		for (int i = 0; i < A.row; i++)
		{
			for (int j = 0; j < B.col; j++)
			{
				for (int k = 0; k < ELE_SUM; k++)
				{
					(*((*(p->mat))[i]))[j] += (*((*(A.mat))[i]))[k] * (*((*(B.mat))[k]))[j];
				}
			}
		}
	}
	return *p;
}

//operator*
matrix& operator*(double k, matrix A)
{
	matrix* p = new matrix;
	*p = A;
	if (A.CRIsValid() == 0)
	{
		return *p;
	}
	else
	{
		for (int i = 0; i < A.row; i++)
		{
			for (int j = 0; j < A.col; j++)
			{
				(*((*(p->mat))[i]))[j] *= k;
			}
		}
	}
	return *p;
}

//MDF_element
void matrix::MDF_element(int ROW, int COLUMN, double ELE)
{
	if (this->CRIsValid())
	{
		(*((*(this->mat))[ROW - 1]))[COLUMN - 1] = ELE;
	}
}

//Unitize
void matrix::Unitize()
{
	if ((this->CRIsValid())&&(this->row==this->col))
	{
		int ORDER = this->row;
		for (int i = 0; i < ORDER; i++)
		{
			for (int j = 0; j < ORDER; j++)
			{
				if (i == j)
				{
					(*((*(this->mat))[i]))[j] = 1;
				}
				else
				{
					(*((*(this->mat))[i]))[j] = 0;
				}
			}
		}
	}
}

//CLR_matrix
void matrix::CLR_matrix()
{
	for (int i = 0; i < this->row; i++)
	{
		for (int j = 0; j < this->col; j++)
		{
			(*((*(this->mat))[i]))[j] = 0;
		}
	}
}

//Row_Mtp
void matrix::Row_Mtp(int ROW, int k)
{
	for (int i = 0; i < this->col; i++)
	{
		(*((*(this->mat))[ROW - 1]))[i] *= k;
	}
}

//Col_Mtp
void matrix::Col_Mtp(int COL, int k)
{
	for (int i = 0; i < this->row; i++)
	{
		(*((*(this->mat))[i]))[COL - 1] *= k;
	}
}

//Row_Mtp_Add
void matrix::Row_Mtp_Add(int Row_1, int Row_2, double k)
{
	for (int i = 0; i < this->col; i++)
	{
		(*((*(this->mat))[Row_2 - 1]))[i] += k * (*((*(this->mat))[Row_1 - 1]))[i];
	}
}

//Col_Mtp_Add
void matrix::Col_Mtp_Add(int Col_1, int Col_2, double k)
{
	for (int i = 0; i < this->row; i++)
	{
		(*((*(this->mat))[i]))[Col_2 - 1] += k * (*((*(this->mat))[i]))[Col_1 - 1];
	}
}

//Row_Exchange
void matrix::Row_Exchange(int Row_1, int Row_2)
{
	for (int i = 0; i < this->col; i++)
	{
		swap((*((*(this->mat))[Row_1 - 1]))[i], (*((*(this->mat))[Row_2 - 1]))[i]);
	}
}

//Col_Exchange
void matrix::Col_Exchange(int Col_1, int Col_2)
{
	for (int i = 0; i < this->row; i++)
	{
		swap((*((*(this->mat))[i]))[Col_1 - 1], (*((*(this->mat))[i]))[Col_2 - 1]);
	}
}

//SINK
void matrix::SINK(int COL)
{
	vector<int> ZERO_RANK;
	
	for (int i = 0; i < this->row; i++)
	{
		if ((*((*(this->mat))[i]))[COL - 1] == 0)
		{
			ZERO_RANK.push_back(i + 1);
		}
	}
	int BACK_COUNT = this->row;
	while (ZERO_RANK.size() != 0)
	{
		this->Row_Exchange(BACK_COUNT, ZERO_RANK.back());
		BACK_COUNT--;
		ZERO_RANK.pop_back();
	}
}

//Stepwise
void matrix::Stepwise()
{
	for (int I = 1; I <= this->row; I++)
	{
		SINK(I);
		for (int J = 1; J <= this->row; J++)
		{
			if (J > I)
			{
				this->Row_Mtp_Add(I, J, -(((*((*(this->mat))[J - 1]))[I - 1]) / (*((*(this->mat))[I - 1]))[I - 1]));
			}
		}
	}
}

//rank
int matrix::rank()
{
	matrix A = *this;
	A.Stepwise();
	int R = 0;
	for (int i = 0; i < this->row; i++)
	{
		for (int j = 0; j < this->col; j++)
		{
			if ((*((*(A.mat))[i]))[j] != 0)
			{
				break;
			}
			if (j == this->col - 1)
			{
				R++;
			}
		}
	}
	return A.row - R;
}

//Inverse
matrix& matrix::Inverse()
{
	matrix Adjugate(this->row, this->col);
	for (int I = 1; I <= this->row; I++)
	{
		for (int J = 1; J <= this->col; J++)
		{
			if ((I + J) % 2 == 0)
			{
				(*((*(Adjugate.mat))[I - 1]))[J - 1] = Minor(*this, I, J).det();
			}
			else
			{
				(*((*(Adjugate.mat))[I - 1]))[J - 1] = -Minor(*this, I, J).det();
			}
		}
	}
	matrix *Inv = new matrix(this->row, this->col);
	*Inv = (1.0 / this->det()) * Adjugate;
	return Inv->Transpose();
}

//Minor
matrix& Minor(matrix ORI_MAT, int nROW,int nCOL)
{
	int ORI_ROW = ORI_MAT.mat->size();
	int ORI_COL = (*ORI_MAT.mat)[0]->size();
	matrix* NEW_MAT = new matrix(ORI_ROW, ORI_COL);
	if ((ORI_ROW != ORI_COL)||(ORI_MAT.CRIsValid()==0))
	{
		matrix a(1, 1);
		*NEW_MAT = a;
		return *NEW_MAT;
	}
	else
	{
		NEW_MAT->mat = new_mat(ORI_ROW, ORI_COL);
		NEW_MAT->match();
		for (int i = 1; i <= ORI_ROW ; i++)
		{
			NEW_MAT->Init(i, ORI_MAT.ROW(i));
		}
		NEW_MAT->Del_row(nROW);
		NEW_MAT->Del_col(nCOL);
	}
	return *NEW_MAT;
}