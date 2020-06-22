#include <iostream>
#include <cstdio>
#include <ctime>
#include <vector>

#include "headers/initialize_beliefs.h"
#include "headers/sense.h"
#include "headers/blur.h"
#include "headers/normalize.h"
#include "headers/move.h"
#include "headers/print.h"

using namespace std;

int main() {

	// number of iterations 
	int iterations = 10000;

	std::clock_t start;
	double duration;

	vector < vector <char> > grid { {'r', 'g', 'r', 'r', 'r'}, {'g', 'r', 'r', 'g', 'r'}, {'r', 'g', 'r', 'r', 'r'} };
	vector< vector <float> > beliefs;

	cout << "number of iterations: " << iterations << " " << "\n";

	// test initialize_beliefs
	start = std::clock();
	for (int i = 0; i < iterations; i++) {
		beliefs = initialize_beliefs(grid);
	}
	duration = ( std::clock() - start ) / (double) CLOCKS_PER_SEC;
	std::cout << "duration milliseconds initialize beliefs " << 1000 * duration << '\n';

	// test sense
	start = std::clock();
	for (int i = 0; i < iterations; i++) {
		beliefs = sense('g', grid, beliefs, .7, .2);
	}
	duration = ( std::clock() - start ) / (double) CLOCKS_PER_SEC;
	std::cout << "duration milliseconds sense " << 1000 * duration << '\n';

	// test blur
	start = std::clock();
	for (int i = 0; i < iterations; i++) {
		beliefs = blur(beliefs, .12);
	}
	duration = ( std::clock() - start ) / (double) CLOCKS_PER_SEC;
	std::cout << "duration milliseconds blur " << 1000 * duration << '\n';

	// test normalize
	start = std::clock();
	for (int i = 0; i < iterations; i++) {
		beliefs = normalize(beliefs);
	}
	duration = ( std::clock() - start ) / (double) CLOCKS_PER_SEC;
	std::cout << "duration milliseconds normalize " << 1000 * duration << '\n';

	// test move
	start = std::clock();
	for (int i = 0; i < iterations; i++) {
		beliefs = move(3, 2, beliefs);
	}
	duration = ( std::clock() - start ) / (double) CLOCKS_PER_SEC;
	std::cout << "duration milliseconds move " << 1000 * duration << '\n';

}