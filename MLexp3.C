import numpy as np
from fractions import Fraction

# Function to display rounded values
def display_format(my_vector, my_decimal):
    return np.round(
        np.array(my_vector, dtype=float),
        decimals=my_decimal
    )

# Initial probability value
my_dp = Fraction(1, 3)

# Transition Matrix
Mat = np.matrix([
    [0, 0, 1],
    [Fraction(1, 2), 0, 0],
    [Fraction(1, 2), 1, 0]
], dtype=object)

# Matrix with all entries = 1/3
Ex = np.zeros((3, 3), dtype=object)
Ex[:] = my_dp

# Damping factor
beta = 0.7

# Google Matrix
Al = beta * Mat + ((1 - beta) * Ex)

# Initial Rank Vector
r = np.matrix([
    [my_dp],
    [my_dp],
    [my_dp]
], dtype=object)

previous_r = r

# Iterations
for i in range(1, 10):
    r = Al * r
    print(display_format(r, 8))

    if (previous_r == r).all():
        break

    previous_r = r

# Final PageRank
print("\nFinal:")
print(display_format(r, 8))

# Sum of PageRank values
print("sum =", np.sum(np.array(r, dtype=float)))
