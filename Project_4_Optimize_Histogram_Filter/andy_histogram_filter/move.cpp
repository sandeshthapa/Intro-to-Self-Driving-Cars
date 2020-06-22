#include "headers/move.h"
#include "headers/zeros.h"

using namespace std;

vector< vector <float> > move(int dy, int dx, 
	vector < vector <float> > beliefs) 
{
	int height, width;
	height = beliefs.size();
	width = beliefs[0].size();

	float belief;
	vector < vector <float> > newGrid;
	newGrid = zeros(height, width);

	vector <float> row, newRow;

	int i, j, new_i, new_j;
	for (i=0; i<height; i++) {
		for (j=0; j<width; j++) {
			new_i = (i + dy + height) % height;
			new_j = (j + dx + width)  % width;
			belief = beliefs[i][j];

			newGrid[new_i][new_j] = belief;
		}
	}
	return newGrid;
}
