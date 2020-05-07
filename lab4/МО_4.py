import numpy as np
import math

def spherical_matrix_norm(matrix):
    diag_sum = sum([matrix[i, i] * matrix[i, i] for i in range(len(matrix))])
    non_diag_sum = sum([matrix[i, j]*matrix[i, j] for i in range(len(matrix)) for j in range (len(matrix)) if not i ==j])
    total_sum = sum([matrix[i, j]*matrix[i, j] for i in range(len(matrix))for j in range(len(matrix))])

    return (diag_sum, non_diag_sum, total_sum)

def find_max_non_diagonal_element(matrix):
    max_i, max_j = 1, 0
    dimension = len(matrix)
    
    for i in range(dimension):
        for j in range(dimension):
            if not i == j and matrix.item((i, j)) > matrix.item((max_i, max_j)):
                max_i, max_j = i, j

    return (max_i, max_j)

def get_translation_matrix(main_matrix):
    i, j = find_max_non_diagonal_element(main_matrix)

    return get_translation_matrix_with_index(main_matrix, i, j)

def get_translation_matrix_with_index(main_matrix, i, j):
    result = np.identity(len(main_matrix))
    mu = 2 * main_matrix[i, j] / (main_matrix[i, i] - main_matrix[j, j])
    c = math.sqrt(0.5 * (1 + 1/math.sqrt(1 + mu*mu)))
    s = math.sqrt(0.5 * (1 - 1/math.sqrt(1 + mu*mu))) * math.copysign(1, mu)
    
    result[i, i] = c
    result[j, j] = c
    result[i, j] = s
    result[j, i] = -s

    return result

def main():
    A = np.matrix([[6.29, 0.97, 1.00, 1.1], 
                   [0.97, 4.13, 1.30, 0.16], 
                   [1.00, 1.30, 5.47, 2.10], 
                   [1.1, 0.16, 2.10, 6.07]])
    print(spherical_matrix_norm(A))

    for i in range(len(A) * len(A)):
        print(spherical_matrix_norm(A))
        trans = get_translation_matrix(A)
        A = trans.dot(A).dot(trans.transpose())

    print(A)
if __name__ == '__main__':
    main()






 

    



