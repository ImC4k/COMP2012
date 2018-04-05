#ifndef MATRIX_H
#define MATRIX_H

#include "vector.h"

class Matrix{
  int row;
  int col;
  double** elements;

public:
  Matrix(int row = 0, int col = 0, double** elements = nullptr): row(row), col(col), elements(elements){
    if(elements)
    if(row && col && !elements){
      prompt_input(row, col);
    }

  }
  ~Matrix(){
    for(int i = 0; i < row; i++){
      delete elements[i];
    }
    delete[] elements;
  }

  Matrix(const Matrix& another){
    elements = nullptr;
    *this = another;
  }

  const Matrix& operator=(const Matrix& another){
    if(this != &another){
      for(int i = 0; i < row; i++){ // delete original elements[][] in *this
        delete elements[i];
      }
      delete[] elements;

      this->row = another.row;
      this->col = another.col;
      this->elements = new double*[this->row];
      for(int i = 0; i < row; i++){
        this->elements[i] = new double[this->col];
      }
      for(int i = 0; i < row; i++){
        for(int j = 0; j < col; j++){
          this->elements[i][j] = another.elements[i][j];
        }
      }
    }
    return *this;
  }

  const Matrix& operator+=(const Matrix& another){
    if(this->row != another.row || this->col != another.col){
      cout<<"Mismatch dimension"<<endl;
      return *this;
    }
    for(int i = 0; i < row; i++){
      for(int j = 0; j < col; j++){
        this->elements[i][j] += another.elements[i][j];
      }
    }
    return *this;
  }

  const Matrix& operator-=(const Matrix& another){
    if(this->row != another.row || this->col != another.col){
      cout<<"Mismatch dimension"<<endl;
      return *this;
    }
    for(int i = 0; i < row; i++){
      for(int j = 0; j < col; j++){
        this->elements[i][j] -= another.elements[i][j];
      }
    }
    return *this;
  }

  void prompt_input(int row, int col){
    elements = new double*[row];
    for(int i = 0; i < row; i++){
      elements[i] = new double[col];
    }
    for(int i = 0; i < col; i++){
      for(int j = 0; j < row; i++){
        double input;
        cout<<endl<<"Please input value for matrix["<<j<<"]["<<i<<"]: ";
        cin>>input;
        elements[j][i] = input;
      }
    }
  }

  double* operator[](int index) const{
    return elements[index];
  }

  Matrix dot(const Matrix& another){
    if(this->col == another.row){
      double** elements = new double*[this->row];
      for(int i = 0; i < this->row; i++){
        elements[i] = new double[another.col];
      }
      for(int i = 0; i < this->row; i++){ // real multiply part
        for(int j = 0; j < this->row; j++){
          for(int k = 0; k < another.col; k++){
            elements[i][k] += a[i][j]*b[j][k];
          }
        }
      }
      return Matrix(this->row, another.col, elements);
    }
    return Matrix();
  }
};

#endif
