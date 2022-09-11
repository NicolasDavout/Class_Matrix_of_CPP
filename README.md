# Class_Matrix_of_CPP
C++: A simple class of matrix

## Introduction

### Background

Matrix classes are not available in Standard Template Library of C++.

When it comes to the calculation of matrices, we are even going to use dynamic-link library or some other complex methods.

Why not make a matrix class right in C++ in case of a lot of trouble?

### Features

#### Small-scale

This is just a simple project bulit by myself within 2 days with code no more than 1000 lines.

#### Easy to use

You'll be sure to get started quickly after reading this readme file.

#### Double type element

The elements in matrix are double type.

## Installation

### Download

Download matrix.cpp and matrix.h

### Move them to your project

- matrix.cpp
- matrix.h

Move these two files into your project directory

### Include matrix.h in your project

```cpp
#include "matrix.h"
```
Once you have done things above, you can use matrix in your project!

## Usage

### Create a new matrix!

#### Create a matrix with 0 rows and 0 columns by default

```cpp
matrix A;
```

#### Create a matrix with m rows and n columns

```cpp
matrix A(m,n);
```

#### Copy object B onto object A

```cpp
matrix A(B);
```
### Get the count of rows or columns

#### Get_row Get_col

```cpp
int Get_row();
int Get_col();
```

- The return value: The count of rows or columns
- Parameters: NONE

EXAMPLE

```cpp
int x = A.Get_row();
int y = A.Get_col();
```

### Print matrix

Print this matrix on the console

#### Print_matrix

```cpp
void Print_matrix();
```

- The return value: NONE
- Parameters: NONE

EXAMPLE

```cpp
A.Print_matrix();
```

### Initialize

Initialize the elements of matrix

#### Init

```cpp
void Init(int n, vector<double> V);
```

- Function: Modify the elements of row n with V
- The return value: NONE
- Parameters: The vector of a row

EXAMPLE

```cpp
A.Print_matrix();
```

#### InitByKeyBoard

```cpp
void InitByKeyBoard();
```

- Function: Input the elements from keyboard
- The return value: NONE
- Parameters: NONE

EXAMPLE

```cpp
A.InitByKeyBoard();
```






### Delete

Delete a certain row or column

#### Del_row Del_col

```cpp
void Del_row(int N);
void Del_col(int N);
```

- Function: Delete the Nth row or column
- The return value: NONE
- Parameters: The row or column you want to delete

EXAMPLE

```cpp
A.Del_row(1);
A.Del_col(4);
```


### Insert

Insert a row or column

#### Insert_row_before Insert_col_before

```cpp
void Insert_row_before(int N);
void Insert_col_before(int N);
```

- Function: Insert a row or column with 0 before row or col N
- The return value: NONE
- Parameters: The row or column you want to insert before
- TIP: If N is equal to [the size of vector + 1], this row or column will be inserted at the end.

EXAMPLE

```cpp
A.Insert_row_before(2);
A.Insert_col_before(3);
```



### Get elements of a row or column

Return elements of a certain row or column encapsulated in a vector

#### ROW COL

```cpp
vector<double> ROW(int N);
vector<double> COL(int N);
```

- Function: Return elements of a certain row or column encapsulated in a vector
- The return value: A vector filled with Nth row or column
- Parameters: The row or column you want to get

EXAMPLE

```cpp
vecotor<double> V1 = A.ROW(2);
vecotor<double> V2 = A.COL(1);
```





### Modifying the elements of matrix

#### MDF_element

```cpp
void MDF_element(int m, int n, double X);
```

- Function: Modify the element at column n in the m row in the matrix with X
- The return value: A vector filled with Nth row or column
- Parameters: Row m, Column n, value X to replace the original value

EXAMPLE

```cpp
A.MDF_element(1, 2, 3.14);
```

#### CLR_matrix

```cpp
void CLR_matrix();
```

- Function: Set all of the elements to 0
- The return value: NONE
- Parameters: NONE

EXAMPLE

```cpp
A.CLR_matrix();
```

#### Unitize

```cpp
void Unitize();
```

- Function: Modified to the identity matrix
- The return value: NONE
- Parameters: NONE

EXAMPLE

```cpp
A.Unitize();
```





### Rank of matrix

Return the rank of matrix

#### rank

```cpp
int rank();
```

- Function: Return The rank of matrix
- The return value: The rank of matrix
- Parameters: NONE

EXAMPLE

```cpp
A.rank();
```

### Determinant

Return the value of the determinant

#### det

```cpp
double det();
```

- Function: Return the value of the determinant
- The return value: The value of the determinant
- Parameters: NONE

EXAMPLE

```cpp
A.det();
```

### Transpose

Return the matrix transposed by this matrix

#### Transpose

```cpp
matrix& Transpose();
```

- Function: Return the matrix transposed by this matrix
- The return value: The matrix transposed by this matrix
- Parameters: NONE

EXAMPLE

```cpp
matrix B = A.Transpose();
```



### Inverse

Return the matrix inversed by this matrix

#### Inverse

```cpp
matrix& Inverse();
```

- Function: Return the matrix inversed by this matrix
- The return value: The matrix inversed by this matrix
- Parameters: NONE

EXAMPLE

```cpp
matrix B = A.Inverse();
```



### Basic transformation of a matrix

The Basic transformation

#### Row_Mtp Col_Mtp

```cpp
void Row_Mtp(int ROW, double k);
void Col_Mtp(int COL, double k);
```

- Function: Mutiply a row or column by k
- The return value: NONE
- Parameters: Row or column to be mutiplied, k is the coefficient to mutiply

EXAMPLE

```cpp
A.Row_Mtp(2, 1.5);
A.Col_Mtp(4, 3.2);
```

#### Row_Mtp_Add Col_Mtp_Add

```cpp
void Row_Mtp_Add(int Row_1, int Row_2, double k = 1);
void Col_Mtp_Add(int Col_1, int Col_2, double k = 1);
```

- Function: Add elements of Row_1/Col_1 multiplied by k to Row_2/Col_2
- The return value: NONE
- Parameters: As is shown in function

EXAMPLE

```cpp
A.Row_Mtp_Add(1, 2, 1.5);
A.Col_Mtp(2, 4, 3.2);
```





#### Row_Exchange Col_Exchange

```cpp
void Row_Exchange(int Row_1, int Row_2);
void Col_Exchange(int Col_1, int Col_2);
```

- Function: Exchange two rows or two columns
- The return value: NONE
- Parameters: As is shown in function

EXAMPLE

```cpp
A.Row_Exchange(1, 2);
A.Col_Exchange(3, 2);
```


#### Operators of matrix

```cpp
friend matrix& operator+(matrix, matrix);
friend matrix& operator-(matrix, matrix);
friend matrix& operator*(matrix, matrix);
friend matrix& operator*(double, matrix);
void operator=(matrix);
```

- Function: Operations on matrices
- The return value: The result of the calculation for matrix
- Parameters: No redundant explanations are given
- TIP: The multiplication operation of the matrix should put the number to the left

EXAMPLE

```cpp
matrix C;
C = A + B;

matrix D;
D = A * B;

matrix E;
D = 4 * A;
```



## Changelog

### [v0.0 beta] - 2022-9-11

v0.0 beta version was released

## FAQ

### 



