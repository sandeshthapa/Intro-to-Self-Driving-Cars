#include <iostream>
#include <vector>

using namespace std;

vector < vector <int> > matrixsum(vector < vector <int> > matrix1, vector < vector <int> > matrix2);
void matrixprint(vector < vector <int> > inputmatrix);

int main() {

	// declare two matrices
	vector < vector <int> > matrix1 (5, vector <int> (3, 2));
	vector < vector <int> > matrix2 (5, vector <int> (3, 26));

	//declare an empty matrix to hold the result
	vector < vector <int> > matrixresult;

	//calculate the sum of the two matrices
	matrixresult = matrixsum(matrix1, matrix2);

	// call the matrix print function to print out the results
	matrixprint(matrixresult);

	return 0;
}

//function to add two matrices together
vector < vector <int> > matrixsum(vector < vector <int> > matrix1, vector < vector <int> > matrix2) {

	// declare a matrix with the same size as matrix1 and matrix2
	vector < vector <int> > matrixsumresult (matrix1.size(), vector <int> (matrix1[0].size(), 0));

	// iterate through matrix1 and assign the sum of each element to the results matrix
	for (int row = 0; row < matrix1.size(); row++) {
		for (int column = 0; column < matrix1[0].size(); column++) {
			matrixsumresult[row][column] = matrix1[row][column] + matrix2[row][column];
		}

	}

	return matrixsumresult;


}

// function to print an integer matrix
void matrixprint(vector < vector <int> > inputmatrix) {

	for (int row = 0; row < inputmatrix.size(); row++) {
		for (int column = 0; column < inputmatrix[0].size(); column++) {
			cout << inputmatrix[row][column] << " ";
		}
		cout << endl;

	}
}
