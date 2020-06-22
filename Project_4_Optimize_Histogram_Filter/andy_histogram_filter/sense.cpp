#include "headers/sense.h"

using namespace std;

vector< vector <float> > sense(char color, vector< vector <char> > grid, vector< vector <float> > beliefs,  float p_hit, float p_miss) 
{
	vector< vector <float> > newGrid;
	vector<float> row, newRow;

	float prior, p;

	char cell;

	int i, j, height, width;
	height = grid.size();
	width = grid.size();

	for (i=0; i<grid.size(); i++) {
		newRow.clear();
		for (j=0; j<grid[0].size(); j++) {
			prior = beliefs[i][j];
			cell = grid[i][j];
			if (cell == color) {
				p = prior * p_hit;
			}
			if (cell != color) {
				p = prior * p_miss;
			}
			newRow.push_back(p);
		}
		newGrid.push_back(newRow);
	}
	return newGrid;
}
