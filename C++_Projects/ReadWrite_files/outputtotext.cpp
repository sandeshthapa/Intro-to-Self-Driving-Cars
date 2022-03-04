#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int main() {

    // create the vector that will be outputted
    vector < vector <int> > matrix (5, vector <int> (3, 2));
    vector<int> row;

    // open a file for outputting the matrix
    ofstream outputfile;
    outputfile.open ("matrixoutput.txt");

    // output the matrix to the file
    if (outputfile.is_open()) {
        for (int row = 0; row < matrix.size(); row++) {
            for (int column = 0; column < matrix[row].size(); column++) {
                if (column != matrix[row].size() - 1) {
                    outputfile << matrix[row][column] << ", ";
                }
                else {
                    outputfile << matrix[row][column];
                }
            }
            outputfile << endl; 
        }
    }

    outputfile.close();

    return 0;
}