//
//  Matrix.hpp
//  Matrix++
//
//  Created by Huncho on 23/10/2020.
//  Copyright © 2020 TIERE. All rights reserved.
//


#pragma once
#include <stdio.h>
#include <fstream> // for file access
#include <iostream>
#include <stdlib.h>
#include <sstream>
#include <string>
#include <vector>
#include <tuple>
#include <cmath>

using std::vector;
using std::tuple;
class Matrix {
private:
    unsigned m_rowSize;
    unsigned m_colSize;
    vector<vector<double> > m_matrix;
public:
    Matrix(unsigned, unsigned, double);
    Matrix(const char *);
    Matrix(const Matrix &);
    ~Matrix();
    
    // Matrix Operations
    Matrix operator+(Matrix &);
    Matrix operator-(Matrix &);
    Matrix operator*(Matrix &);
    Matrix transpose();
    
    // Scalar Operations
    Matrix operator+(double);
    Matrix operator-(double);
    Matrix operator*(double);
    Matrix operator/(double);
    
    // Aesthetic Methods
    double& operator()(const unsigned &, const unsigned &);
    void print() const;
    unsigned getRows() const;
    unsigned getCols() const;
    
    // Power Iteration
    tuple<Matrix, double, int> powerIter(unsigned, double);
    
    // Deflation
    Matrix deflation(Matrix &, double&);
    
    // create submatrices (a new matrix from a preexisting one, removing a single column and row)
    
    //create a diagonal matrix from column vector
    
    // calculate eigenvalues and eigenvectors of symmetric and non-symmetric matrices (uses algorithm from Numerical Recipes)
    
    // adjugate, determinant and inverse
    
    // count occurrences, sort elements in-place, return only unique values from a matrix
    
};
