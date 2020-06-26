
#include "matrix.h"

int main () {

     // assign a 7x5 matrix to the variable initial_grid
    // all values in the matrix are 0.4
	std::vector <std:: vector <float> > initial_grid (7, std::vector <float>(5, 0.4));

    // TODO: Use the initial grid variable to instantiate a matrix object
    // The matrix object should be called matrixa
    Matrix matrixa(initial_grid); 
    matrixa.matrix_print();

    // TODO: Print out the number of rows in matrixa. You will need
    // to use the getRows() function and std::cout
   std::cout << "Rows " << matrixa.getRows() << std::endl; 
   std::cout << "Cols " << matrixa.getCols() << std::endl; 

    // TODO: Print out the number of columns in matrixa

    // TODO: Take the transpose of matrixa and store the results in
    // a variable called transposea
    Matrix transposea =  matrixa.matrix_transpose(); 

    // TODO: Print out transposea
    transposea.matrix_print(); 


    // Now you will use another 7x5 matrix called matrixb to
    // give the results of the matrix_addition function

    // 7x5 2-dimensional vector with values 0.2
	std::vector <std:: vector <float> >
	    second_grid (7, std::vector <float>(5, 0.2));

    // TODO: Instantiate an object called matrixb. Use the second_grid
    // variable as the input to initialize matrixb
    Matrix matrixb(second_grid); 


    // TOOD: Add matrixa and matrixb. Store the results in a new matrix
    // variable called matrixsum
    Matrix matrixsum = matrixa.matrix_additon(matrixb); 
    matrixsum.matrix_print(); 

    // TODO: Print out the matrix contained in the matrixsum variable


    return 0;
}
