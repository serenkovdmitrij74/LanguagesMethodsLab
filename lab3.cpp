#include <iostream>


using namespace std;


void print_matrix(float** mat, int size)
{
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			cout << mat[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
}


float** create_matrix(int* size)
{
	cout << "Enter the matrix size: ";
	cin >> *size;
	float** mat = new float* [*size];

	for (int i = 0; i < *size; i++)
		mat[i] = new float[*size];

	for (int i = 0; i < *size; i++) {
		for (int j = 0; j < *size; j++) {
			cout << "Enter element(" << i << ":" << j << "): ";
			cin>>mat[i][j];
		}
	}

	return mat;
}


void rows_substraction(float** mat, int size, int worked_num)
{
	for (int y = worked_num + 1; y < size; y++) {
		for (int x = size-1; x >= worked_num; x--) {
			mat[y][x] -= (mat[worked_num][x] * mat[y][worked_num]) / mat[worked_num][worked_num];
		}
	}
}


void gauss(float** mat, int size, float* det)
{
	for (int x = 0; x < size; x++) {
		for (int y = x; y < size; y++) {
			if (mat[y][x] != 0) {
				if (mat[x][x] == 0)
					(*det) *= -1;
				swap(mat[y], mat[x]);
				rows_substraction(mat, size, x);
			}
		}
	}
}


void colculate_determinant(float** mat, int size, float* det)
{
	for (int i = 0; i < size; i++) {
		*det *= mat[i][i];
	}
}


int main()
{
	int size;
	float det = 1, ** mat = create_matrix(&size);


	gauss(mat, size, &det);
	print_matrix(mat, size);
	colculate_determinant(mat, size, &det);


	cout << "Determinant = " << det;


	delete[] mat;
}
