#include <iostream>
#include <fstream>
#include <string>


using namespace std;


void read_file(int* size, float*** mat, string filename)
{
	ifstream file(filename);

	file >> *size;

	* mat = new float* [*size];

	for (int i = 0; i < *size; i++)
		(*mat)[i] = new float[*size];

	for (int i = 0; i < *size; i++) {
		for (int j = 0; j < *size; j++) {
			file >> (*mat)[i][j];
		}
	}
	
	file.close();
}


float len(float** mat, int* mas, int wn, int sp)
{
	float len=0;

	while (wn != sp){
		len+=mat[mas[wn]][wn];
		wn=mas[wn];
	}

	return len;
}


int min_index(float** mat, int sp, int size, int* mas, bool* vismas)
{
	int min=0;
	for(int i=0; i<size;i++){
		if (len(mat, mas, i, sp) != 0 && (len(mat, mas, i, sp)<len(mat, mas, min, sp) || vismas[min]) && !vismas[i]){
			min=i;
		}
	}

	return min;
}


void print(float** mat, int sp, int size, int* mas)
{
	int wn = 0;

	for (int i = 0; i < size; i++){
		cout<<"Вершина "<< i<< ": ";
		wn = i;
		cout<< wn;
		while (wn != sp){
			wn = mas[wn];
			cout<< "-"<<wn;
		}
		cout<<" Расстояние от начальной точки: "<<len(mat, mas, i, sp)<<endl;
	}
		
}


void deecstri(int size, float** mat)
{
	int wn, sp, * mindests = new int[size];
	bool * vispoints = new bool[size];
	cout<<"Start point: ";
	cin>> sp;

	for(int i=0; i<size;i++){
		vispoints[i]=false;
		mindests[i]=sp;
	}

	vispoints[sp]=true;

	
	for(int i=0; i<size-1; i++){
		wn = min_index(mat, sp, size, mindests, vispoints);
		vispoints[wn]=true;

		for(int j=0; j<size; j++){
			if (mat[wn][j] != 0 && !vispoints[j] && (mat[wn][j]+len(mat, mindests, wn, sp)<len(mat, mindests, j, sp) || len(mat, mindests, j, sp)==0 && !vispoints[j]))
				mindests[j]=wn;
		}
	}

	print(mat, sp, size, mindests);
}


int main()
{
	int size;
	float ** mat;
	int * mas = new int[4];

	read_file(&size, &mat, "tab.txt");

	deecstri(size, mat);
}
