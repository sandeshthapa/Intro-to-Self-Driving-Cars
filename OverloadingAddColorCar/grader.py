import numpy as np
import color

def check_vals(value1, value2):
    return value1 == value2

def test_two_colors(c1, c2):
    '''
    Feed in the rgb values of color one,
    then the rgb values of color two (as lists).
    Adds these two together.
    '''
    color1 = color.Color(c1[0], c1[1], c1[2])
    color2 = color.Color(c2[0], c2[1], c2[2])
    new_color = color1 + color2
    
    return (check_vals(new_color.r, (color1.r + color2.r) / 2) and
            check_vals(new_color.g, (color1.g + color2.g) / 2) and
            check_vals(new_color.b, (color1.b + color2.b) / 2))

def test_add_colors():
    if (test_two_colors([250, 0, 0], [0, 50, 200]) and
        test_two_colors([180, 70, 30], [10, 20, 250])):
        print('Nice work! Your colors add as expected.')
    else:
        print('Oops! Something went wrong. Make sure you are averaging the colors.')