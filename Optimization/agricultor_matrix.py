from cvxopt import matrix, solvers
import numpy as np

A = matrix( [ [1.0, 3.0, 1.0, 0.0], [1.0, 2.0, 0.0, 1.0] ] )
b = matrix( [100.0, 240.0, 60.0, 80.0])
c = matrix( [-600.0, -800.0 ])

sol = solvers.lp(c, A, b)
print(sol['x'])