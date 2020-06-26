#include <iostream>
#include <vector>

using namespace std;

int main(){

    // declare a two dimensional vector of type int
    vector <vector <int> > twodvector;

    // set up a row
    vector<int> singlerow (3,2);

    //append five rows
    for (int i = 0; i <5; i++){
        twodvector.push_back(singlerow);
    }

    // print out the matrix
    for (int row = 0; row < twodvector.size(); row++){
        for (int column = 0; column < twodvector[0].size(); column++){
                cout << twodvector[row][column] << " ";
        }
        cout << endl;
    }

    return 0;
}
