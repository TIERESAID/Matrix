//  main.cpp
//  Matrix++
//  Created by Huncho on 23/10/2020.
//  Copyright © 2020 TIERE. All rights reserved.

#include "Matrix.hpp"
// parametrized constructor;
template<class T>
Matrix<T>::Matrix(unsigned row , unsigned col, T initial){
  this->m_row_size = row;
  this->m_col_size = col;
  // intialise two dimensional vector for any matrix with vector
    this->m_matrix.resize(col);
    for(int i=0 ; i<m_matrix.size(); i++){
        m_matrix[i].resize(m_col_size, initial);
    }
}

// copy constuctor 
template<class T>
Matrix<T>::Matrix(const Matrix& copy){
  m_matrix = copy.m_matrix;
  m_row_size = copy.getrow();
  m_col_size = copy.getcol();
}
// destructor
template<class T>
Matrix<T>::~Matrix(){};

//Aesthetic Methods (A const member function cannot change the value of any data member of the class and cannot call any member function which is not constant.)
template<class T>
unsigned Matrix<T>::getrow()const{
return this->m_row_size;
}

template<class T>
unsigned Matrix<T>::getcol()const {
return this->m_col_size ;
}

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

// Scalar addition
template<>
Matrix<double> Matrix<double>::operator+(double scalar){
Matrix<double> result(m_row_size, m_col_size,0);

for (int i = 0; i < m_row_size; ++i)
{
  for (int j = 0; j < m_col_size; ++j)
  {
    result(i,j) = this->m_matrix[i][j] + scalar;  
  }
}
return result ;
}

// scalar substraction 
template<>
Matrix<double> Matrix<double>::operator-(double scalar){
Matrix<double> result(m_row_size,m_col_size,0);

for (int i = 0; i < m_row_size; ++i)
{
  for (int j = 0; j < m_col_size; ++j)
  {
    result(i,j) = this->m_matrix[i][j] - scalar; 
  }
}
return result;
}

// scalar multiplication
template<>
Matrix<double> Matrix<double>::operator*(double scalar){
  Matrix<double> result(m_row_size,m_col_size,0);
  for (int i = 0; i < m_row_size; ++i)
  {
    for (int j = 0; j < m_col_size; ++j)
    {
      result(i,j) = this->m_matrix[i][j] * scalar;
    }
  }
  return result;
}

// scalar division
template<>
Matrix<double> Matrix<double>::operator/(double scalar){
  Matrix<double> result(m_row_size,m_col_size,0);

  for (int i = 0; i < m_row_size; ++i)
  {
    for (int j = 0; j < m_col_size; ++j)
    {
      result(i,j) = this->m_matrix[i][j] / scalar;
    }
  }
  return result;
}

//overloading operator() 
//http://www.cs.technion.ac.il/users/yechiel/c++-faq/matrix-subscript-op.html
template <class T>
T& Matrix<T>::operator()(const unsigned& row_no , const unsigned& col_no){
  return this->m_matrix[row_no][col_no] ;
}
