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


int min_index(int size, float* mas, bool* vismas)
{
	int min=0;
	for(int i=0; i<size;i++){
		if (mas[i] != 0 && (mas[i]<mas[min] || mas[min]==0) && !vismas[i])
			min=i;
	}

	return min;
}


void print(int size, float* mas)
{
	for (int i = 0; i < size; i++)
		cout<<mas[i]<< " ";
}



void deecstra(int size, float** mat)
{
	int wn, sp;
	bool * vispoints = new bool[size];
	float * mindests = new float[size];
	cout<<"Start point: ";
	cin>> sp;

	for(int i=0; i<size;i++){
		vispoints[i]=false;
		mindests[i]=mat[sp][i];
	}

	vispoints[sp]=true;
	
	for(int i=0; i<size; i++){
		wn = min_index(size, mindests, vispoints);
		vispoints[wn]=true;
		for(int j=0; j<size; j++){
			if (mat[wn][j] != 0 && !vispoints[j] && (mat[wn][j]+mindests[wn]<mindests[j] || mindests[j]==0 && !vispoints[j]))
				mindests[j]=mat[wn][j]+mindests[wn];
		}
	}

	print(size, mindests);
}


int main()
{
	int size;
	float ** mat;
	int * mas = new int[4];

	read_file(&size, &mat, "tab.txt");

	deecstra(size, mat);
}
