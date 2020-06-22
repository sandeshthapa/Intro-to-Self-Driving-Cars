import math
from math import sqrt
import numbers

def zeroes(height, width):
        """
        Creates a matrix of zeroes.
        """
        g = [[0.0 for _ in range(width)] for __ in range(height)]
        return Matrix(g)

def identity(n):
        """
        Creates a n x n identity matrix.
        """
        I = zeroes(n, n)
        for i in range(n):
            I.g[i][i] = 1.0
        return I

class Matrix(object):

    # Constructor
    def __init__(self, grid):
        self.g = grid
        self.h = len(grid)
        self.w = len(grid[0])

    #
    # Primary matrix math methods
    #############################
 
    def determinant(self):
        """
        Calculates the determinant of a 1x1 or 2x2 matrix.
        """
        if not self.is_square():
            raise(ValueError, "Cannot calculate determinant of non-square matrix.")
        if self.h > 2:
            raise(NotImplementedError, "Calculating determinant not implemented for matrices largerer than 2x2.")
        
        # TODO - your code here
        height = len(self.g)
        width = len(self.g[0])
        det = 0
        
        if height == 1:
            det = self.g
        elif height == 2:
        # If the matrix is 2x2, check that the matrix is invertible
            if self.g[0][0] * self.g[1][1] == self.g[0][1] * self.g[1][0]:
                raise ValueError('The matrix is not invertible.')
            else:
                # Calculate the inverse of the square 1x1 or 2x2 matrix.
                a = self.g[0][0]
                b = self.g[0][1]
                c = self.g[1][0]
                d = self.g[1][1]
                det = (a * d - b * c)
           
        return det 
       

    def trace(self):
        """
        Calculates the trace of a matrix (sum of diagonal entries).
        """
        
        if not self.is_square():
            raise ValueError ('Cannot calculate the trace of a non-square matrix.')

        # TODO - your code here
        height = len(self.g)
        width  = len(self.g[0])
        tr = 0
        
        if height == 1:
            tr = self.g[0][0]
        else:
            for i in range(height): 
                for j in range(width): 
                    if i == j:
                        tr += self.g[i][j]
                        
                        
        return tr
           


    def inverse(self):
        """
        Calculates the inverse of a 1x1 or 2x2 Matrix.
        """
        if not self.is_square():
            raise(ValueError, "Non-square Matrix does not have an inverse.")
        if self.h > 2:
            raise(NotImplementedError, "inversion not implemented for matrices larger than 2x2.")

        # TODO - your code here
        height = len(self.g)
        width = len(self.g[0])
        inv = []

        if height == 1:
            inv.append([1 / self.g[0][0]])
        elif height == 2:
        # If the matrix is 2x2, check that the matrix is invertible
            if self.g[0][0] * self.g[1][1] == self.g[0][1] * self.g[1][0]:
                raise ValueError('The matrix is not invertible.')
            else:
                # Calculate the inverse of the square 1x1 or 2x2 matrix.
                a = self.g[0][0]
                b = self.g[0][1]
                c = self.g[1][0]
                d = self.g[1][1]
                
                factor = 1 / (a * d - b * c)

                inv = [[d, -b],[-c, a]]
            
                for i in range(len(inv)):
                    for j in range(len(inv[0])):
                        inv[i][j] = factor * inv[i][j]
                        
        return Matrix(inv)
    
    def T(self):
        """
        Returns a transposed copy of this Matrix.
        """
        # TODO - your code here
        matrix_transpose = []
        for i in range(len(self.g[0])):
            trans_row = []
            for j in range(len(self.g)):
                crr = self.g[j][i]
                trans_row.append(crr)
            matrix_transpose.append(trans_row)
            
        return Matrix(matrix_transpose)

    def is_square(self):
        return self.h == self.w

    #
    # Begin Operator Overloading
    ############################
    def __getitem__(self,idx):
        """
        Defines the behavior of using square brackets [] on instances
        of this class.

        Example:

        > my_matrix = Matrix([ [1, 2], [3, 4] ])
        > my_matrix[0]
          [1, 2]

        > my_matrix[0][0]
          1
        """
        return self.g[idx]

    def __repr__(self):
        """
        Defines the behavior of calling print on an instance of this class.
        """
        s = ""
        for row in self.g:
            s += " ".join(["{} ".format(x) for x in row])
            s += "\n"
        return s

    def __add__(self,other):
        """
        Defines the behavior of the + operator
        """
        if self.h != other.h or self.w != other.w:
            raise(ValueError, "Matrices can only be added if the dimensions are the same") 
        #   
        # TODO - your code here
        #
        height = len(self.g)
        width = len(self.g[0])
        new_add = []
        
        for i in range(height): 
            new_row = []
            for j in range(width): 
                curr_sum = self.g[i][j] + other.g[i][j]
                new_row.append(curr_sum)
            new_add.append(new_row)
                    
        return Matrix(new_add)

    def __neg__(self):
        """
        Defines the behavior of - operator (NOT subtraction)

        Example:

        > my_matrix = Matrix([ [1, 2], [3, 4] ])
        > negative  = -my_matrix
        > print(negative)
          -1.0  -2.0
          -3.0  -4.0
        """
        #   
        # TODO - your code here
        #
        height = len(self.g)
        width = len(self.g[0])
        new_neg = []
        
        if height == 1: 
            new_neg.append(float(-self.g[0][0]) )
        else: 
            for i in range(height): 
                new_row = []
                for j in range(width): 
                    curr_neg = float(-self.g[i][j]) 
                    new_row.append(curr_neg)
                new_neg.append(new_row)  
            
        return Matrix(new_neg)

    def __sub__(self, other):
        """
        Defines the behavior of - operator (as subtraction)
        """
        #   
        # TODO - your code here
        #
        if self.h != other.h or self.w != other.w:
             raise(ValueError, "Matrices can only be subtracted if the dimensions are the same") 
            
        height = len(self.g)
        width = len(self.g[0])
        new_sub = []
        
        for i in range(height): 
            new_row = []
            for j in range(width): 
                curr_sub = self.g[i][j] - other.g[i][j]
                new_row.append(curr_sub)
            new_sub.append(new_row)

        return Matrix(new_sub)

    def __mul__(self, other):
        """
        Defines the behavior of * operator (matrix multiplication)
        """
        #   
        # TODO - your code here
        #
           
        height = len(self.g)
        width = len(self.g[0])
        product = [] # Matriz.zeros(height, width)
       
        trans_B = Matrix.T(other)
        print(trans_B)

        for i in range(len(self.g)):
            product_row = []
            for j in range(len(other.g[0])):
                curr_dot = Matrix.dot_product(self.g[i], trans_B[j])
                product_row.append(curr_dot)
            product.append(product_row)
        
        return Matrix(product)

    def __rmul__(self, other):
        """
        Called when the thing on the left of the * is not a matrix.

        Example:

        > identity = Matrix([ [1,0], [0,1] ])
        > doubled  = 2 * identity
        > print(doubled)
          2.0  0.0
          0.0  2.0
        """
        if isinstance(other, numbers.Number):
            #pass
            #   
            # TODO - your code here
            #
            height = len(self.g)
            width = len(self.g[0])
            new_prdt = []
            
            for a in range(height):
                new_row = []
                for b in range(width): 
                     new_row.append(float(other*self.g[a][b]))
                new_prdt.append(new_row)
                            
        return Matrix(new_prdt)
            
    def dot_product(vector_one, vector_two):
        result = 0
        for i in range(len(vector_one)):
            v1_i =  vector_one[i] 
            v2_i =  vector_two[i]
            result += v1_i * v2_i
        
        return result
    
    #def get_row(matrix, row):
    #    return Matrix(matrix[row])

    
    #def get_column(matrix, column_number):
    #    column = []
    #    for i in range(len(matrix)):
    #        ith_row = matrix[i]
    #        column_in = ith_row[column_number]
    #    column.append(column_in)
      
    #    return Matrix(column)
   
        

