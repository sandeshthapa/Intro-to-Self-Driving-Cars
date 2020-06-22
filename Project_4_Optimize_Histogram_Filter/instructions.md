INSTRUCTIONS:

This workspace contains two folders:
- andy_histogram_filter_code: Andy's Histogram filter code translated from Python into C++. 
- optimized_code: This folder also contains Andy's Histogram filter code. You will optimize the code in these files to see how fast you can get main.cpp to run.

There are eight C++ files and seven header files. Each file other than main.cpp contains a function that carries out a specific part of a histogram filter. 

main.cpp - prints out how long it takes to run each function

initialize_beliefs.cpp - converts a 2D char vector to a 2D float vector containing initial probabilities

sense.cpp - the robot senses the color of the current grid point and calculates the resulting beliefs

blur.cpp - blur the resulting 2D vector

normalize.cpp - normalize the results to represent a probability

move.cpp - move the robot by (x,y) and calculate the new beliefs

zeros.cpp - outputs a 2D vector with zero for all elements

print.cpp - contains two different functions for printing out a 2D vector. 

If you open main.cpp, you will see that the program runs each of the histogram filter functions ten-thousand times and then prints out the time taken to run each function. Main.cpp starts off with a 2D char vector representing a discrete color grid. Then the  code: 
- initializes the belief matrix
- senses the color grid
- blurs the results
- normalizes the results to calculate probabilities
- moves the robot

Your task is to:
1. Run the code in the Andy_Histogram_Filter folder. You can use these commands in a terminal window:

cd andy_histogram_filter

g++ -std=c++11 main.cpp blur.cpp initialize_beliefs.cpp move.cpp normalize.cpp print.cpp sense.cpp zeros.cpp

./a.out

The -std=c++11 option tells the compiler to use version 11 of C++. Version 11 introduced some 2D vector initialization features that you might want to use in your code. For example, 

std::vector<int> v = {1, 2, 3, 4}; 
  
would both declare and define a vector simultaneously.

2. Read through and understand the code in the andy_histogram_filter folder.

3. Optimize the code in the Optimized_Code folder. Use the techniques discussed in the lesson. You can test your results in the terminal using the same commands given previously. But make sure to first change directories in the terminal so that you are inside the optimized_code folder:

cd  /home/workspace/optimized_code

g++ -std=c++11 main.cpp blur.cpp initialize_beliefs.cpp move.cpp normalize.cpp print.cpp sense.cpp zeros.cpp

./a.out

In the optimized_code folder, you will find some hints about what could make each of the histogram filter functions run faster. Reading the hints file is optional. Try optimzing the code first without the hints!