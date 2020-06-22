#include "headers/initialize_beliefs.h"

using namespace std;

// OPTIMIZATION: pass large variables by reference
vector< vector <float> > initialize_beliefs(vector< vector <char> > &grid) {

	// OPTIMIZATION: Which of these variables are necessary?
	// OPTIMIZATION: Reserve space in memory for vectors
  	vector< vector <float> > newGrid;
    newGrid.reserve(grid.size()); 
  
	vector<float> newRow;
    newRow.reserve(grid[0].size()); 
  
	//int i, j, height, width, area;
	//float total, prob_per_cell;

	//height = grid.size();
	//width = grid[0].size();
 
	//area = height * width;

  	//prob_per_cell = 1.0 / ( (float) area) ;

  	// OPTIMIZATION: Is there a way to get the same results 	// without nested for loops?
		//newRow.clear();
		for (int j=0; j<grid[0].size(); j++) {
			newRow.push_back(1.0/ (grid.size()*grid[0].size()));
		}
  
  	for (int i=0; i<grid.size(); i++) {
		newGrid.push_back(newRow);
	}
  
	return newGrid;
}