#include <iostream> 
#include <fstream> 
#include <string> 
#include <sstream> 
#include <vector>
; 
using namespace std; 

int main(){

    // initialize string variables for reading text file lines 
    string line; 
    stringstream ss; 

    // initialize variables to hold the matrix 
    vector < vector <float> > matrix; 
    vector <float> row; 

    // counter for charaters in a text file line
    float i; 

    // read in the file 
    ifstream matrixfile ("matrix.txt"); 

    // read in the matrix file line by line 
    // parse the file 

    if(matrixfile.is_open())
    {

        while(getline(matrixfile, line))
        {
            // parse the text line with stringstream 
            // clear the string stream to hold the next line 
            ss.clear(); 
            ss.str(" "); 
            ss.str(line); 
            row.clear(); 

            // parse each line and push to the end of the row vector 
            // the ss variable holds a line of text 
            // ss >> i puts the next character into the i variable 
            // the >> syntax is like cin>> some_value or cout << some_value 
            // ss ? i is false when the end of the line is reached. 

            while (ss >> i)
            {
                row.push_back(i); 
                if (ss.peek() == ',' || ss.peek() == ' ')
                {
                    ss.ignore(); 
                }
                
            }

            matrix.push_back(row); 

            matrixfile.close();

            // print the matrix 
            for (int i = 0; i < matrix.size(); i++)
            {
                for (int j = 0; j < matrix[i].size(); j++)
                {
                    cout << matrix[i][j] << " " ; 
                }
                cout << endl; 
                
            }
            
        }
    }

    else cout << " Unable to open file "; 


    
    return 0 ; 
}