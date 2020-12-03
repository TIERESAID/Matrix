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

// return row size
template<class T>
unsigned Matrix<T>::getrow()const{
return this->m_row_size;
}

//return col size 
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

// Matrix addition
template <class T>
Matrix<T> Matrix<T>::operator+(Matrix& B){
  Matrix<T>sum(m_row_size, m_col_size, 0);
   for (int i = 0; i < m_row_size ; i++)
   {
     for (int j = 0; j < m_col_size; j++)
     {
       sum(i,j) = this->m_matrix[i][j] + B(i,j);
     }
   }
   return sum;
}

template<class T>
Matrix<T> Matrix<T>::operator-(Matrix& B){
  Matrix<T>sub(m_row_size, m_col_size,0);
  for (int i = 0; i < m_row_size; ++i)
  {
    for (int j = 0; j < m_col_size; ++j)
    {
      sub(i,j) = this->matrix[i][j] - B(i,j);
    }
  }
}

template<class T>
Matrix<T> Matrix<T>::operator*(Matrix& B){
    Matrix<T> mult(this->m_row_size, B.getcol(),0);
    for(int i=0; i<m_row_size; i++)
    {
      for (int j = 0; j < B.getcol(); ++j)
      {                  /*or B.getrow()*/
        for (int k = 0; k < m_col_size; ++k)
        {
          mult(i,j) += this->m_matrix[k][j] * B(k,j); 
        }
      }
    }
    return mult;
}


template<>
double Matrix<double>::Determinant(Matrix& A ,int n) const
{
  
  double det = 0.0;
  Matrix sub_matrix(n,n,0);

             if(n ==2)
    return ( A(0,0)*A(1,1) - A(0,1)*A(1,0) );
             else {
   for (int index_power = 0; index_power < n; ++index_power)
   {
    int subi = 0;
     for (int i = 0; i < n; ++i)
     {
      int subj = 0;
       for (int j = 0; j < n; ++j)
       {
               if(index_power == j)
               continue;
               sub_matrix(subi,subj) =  A(i,j); 
               subj++;
       }
       subi++;
     }
     det = det + (pow(-1, index_power) * A(0,index_power) * Determinant( sub_matrix,n-1));
   }
 }
   return det;
}
















