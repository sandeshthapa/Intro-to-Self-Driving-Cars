#include "headers/normalize.h"
using namespace std;

vector< vector<float> > normalize(vector< vector <float> > grid) {

	float total = 0.0;
	int i;
	int j;
	vector<float> row;
	vector<float> newRow;
	float oldProb;
	for (i = 0; i < grid.size(); i++)
	{
		row = grid[i];
		for (j=0; j< row.size(); j++)
		{
			oldProb = row[j];
			total += oldProb;
		}
	}

	vector< vector<float> > newGrid;

	for (i = 0; i < grid.size(); i++) {
		vector<float> row = grid[i];
		newRow.clear();
		for (j=0; j< row.size(); j++) {
			float oldProb = row[j];
			float newProb = oldProb / total;
			newRow.push_back(newProb);
		}
		newGrid.push_back(newRow);
	}

	return newGrid;
}
