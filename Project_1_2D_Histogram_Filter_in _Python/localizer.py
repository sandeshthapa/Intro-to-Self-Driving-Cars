#import pdb
from helpers import normalize, blur

def initialize_beliefs(grid):
    height = len(grid)
    width = len(grid[0])
    area = height * width
    belief_per_cell = 1.0 / area
    beliefs = []
    for i in range(height):
        row = []
        for j in range(width):
            row.append(belief_per_cell)
        beliefs.append(row)
    return beliefs

def sense(color, grid, beliefs, p_hit, p_miss):
    new_beliefs = []
    #
    # TODO - implement this in part 2
    #
    sum_row = 0
    sum_roww = 0
    height = len(grid)
    width = len(grid[0])
    for i in range(height):
        row = []
        for j in range(width):
            hit = (color == grid[i][j])
            p_test = (beliefs[i][j]* (hit * p_hit + (1-hit) * p_miss))
            row.append(p_test) 
        
        sum_row = sum(row) 
        sum_roww = sum_roww + sum_row
        new_beliefs.append(row)
     
    #print('sum row:', sum_roww)      
    for i in range(height): 
        for j in range(width): 
            new_beliefs[i][j] = new_beliefs[i][j]/sum_roww
                
    return new_beliefs

def move(dy, dx, beliefs, blurring):
    height = len(beliefs)
    width = len(beliefs[0])
    #print('height', height)
    #print('width', width)
    new_G = [[0.0 for i in range(width)] for j in range(height)]
    #print('new_G', new_G)
    for i, row in enumerate(beliefs):
        new_i = 0
        for j, cell in enumerate(row):
            new_i = (i + dy ) % height
            new_j = (j + dx ) % width
            #pdb.set_trace()
            #print('new_i', new_i, 'new_j', new_j, 'dy', dy, 'dx', dx)
            new_G[int(new_i)][int(new_j)] = beliefs[i][j]
    return blur(new_G, blurring)