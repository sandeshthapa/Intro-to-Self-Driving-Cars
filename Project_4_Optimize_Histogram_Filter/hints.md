# Ideas for optimizing each of the functions 

zeros.cpp
- reserve space in memory newGrid and newRow
- avoid the nested for loop. The newRow variable always contains zeros, so you only need to define that variable once. In the current code, the newRow is redefined for every row in the matrix

initialize_beliefs.cpp
- Pass the grid variable in by reference. Or alternatively, you don't actually need the grid variable; instead, the inputs to the function can be the matrix width and height.
- remove intermediate variables like "area"
- reserve space in memory for vectors like newGrid and newRow
- For newGrid, you don't need nested for loops. Every value in the matrix is the same, so you only need to define the row variable once.

sense.cpp
- pass large variable like grid and beliefs by reference
- the newGrid variable isn't needed. You can update the beliefs variable directly without affecting any of the calculations
- there are extra intermediate variables like "prior" and "cell" that aren't needed

blur.cpp
- pass larger variables, such as  grid, by reference
- The window, DX and DY vectors always have the same values every time the function runs. Declare and define these variables on a single line using the static const operators. To see how to define a vector on a single line, go back to the lesson on const and static.
- Use the optimized zeros function to define the newGrid variable rather than the nested for loop.

normalize.cpp
- pass the grid variable by reference
- avoid declaring unecessary variables especially a new 2D matrix called newGrid. You can just update grid directly.

move.cpp
- pass beliefs variable by reference
- use improved zeros function for newGrid
- avoid declaring and defining intermediate variables like the belief variable. See if the code runs faster.