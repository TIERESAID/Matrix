//
//  main.cpp
//  Matrix++
//
//  Created by Huncho on 23/10/2020.
//  Copyright © 2020 TIERE. All rights reserved.
//
#include "Matrix.hpp"

// parametrized constructor;
template<class T>
Matrix<T>::Matrix(unsigned rows , unsigned cols, T initial){
  this->m_row_size = rows;
  this->m_col_size = cols;
  // intialise    tww dimensinal vector for any matrix with vector
    this->m_matrix.resize(cols);
    for(int i=0 ; i<m_matrix.size(); i++){
        m_matrix[i].resize(m_col_size, initial);
    }
}

// destructor
template<class T>
Matrix<T>::~Matrix(){};

// print a matrix
template<class T>
void Matrix<T>::print() const{
    for (int i=0; i<m_matrix.size();i++ ) {
    for (int j=0; j<m_matrix[i].size(); j++) {
        std::cout<<m_matrix[i][j]<<" ";
        
    }
    printf("\n");
}
    printf("\n");
}
