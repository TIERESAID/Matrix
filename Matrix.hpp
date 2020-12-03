//
//  Matrix.hpp
//  Matrix++
//
//  Created by Huncho on 23/10/2020.
//  Copyright © 2020 TIERE. All rights reserved.

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

template<class T>
class Matrix {
private:
    unsigned m_row_size;
    unsigned m_col_size;
    vector<vector<T>>m_matrix;
public:
    Matrix(unsigned, unsigned , T); // parametrized constructor 

    Matrix(const char *);
    Matrix(const Matrix &); // copy constructor
    ~Matrix(); // destructor 

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
    T& operator()(const unsigned&, const unsigned&);
    
    // Aesthetic Methods
    void print() const;
    unsigned getrow() const;
    unsigned getcol() const;
    
    // Power Iteration
    tuple<Matrix, double, int> powerIter(unsigned, T);
    // Trace of the Matrix

    //Determibant of the Matrix 
    double Determinant( Matrix&, int)const;

    //Transpose of the Matrix
    Matrix  transpose(Matrix&);


    // Calcul the Inverse
    Matrix  Inverse(Matrix&);

    // Find the rank 
    int rank(const Matrix&);
    
    // Deflation
    Matrix deflation(Matrix &, double&);
    
    // create submatrices (a new matrix from a preexisting one, removing a single column and row)
    
    //create a diagonal matrix from column vector
    
    // calculate eigenvalues and eigenvectors of symmetric and non-symmetric matrices (uses algorithm from Numerical Recipes)
    
    // adjugate, determinant and inverse
    
    // count occurrences, sort elements in-place, return only unique values from a matrix
    
};


