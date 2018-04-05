#ifndef VECTOR_H
#define VECTOR_H

#include <iostream>
#include <string>

using namespace std;

class Vector{
  int dimension;
  double* elements;

public:
  Vector(int dimension = 0, double array_element[] = NULL): dimension(dimension){
    if(array_element){
      this->elements = new double[dimension];
      for(int i = 0; i < dimension; i++){
        this->elements[i] = array_element[i];
      }
    }
    else this->elements = nullptr;
  }

  Vector(const Vector& another){
    dimension = another.dimension;
    elements = new double[dimension];
    for(int i = 0; i < dimension; i++){
      elements[i] = another.elements[i];
    }
  }

  ~Vector(){
    delete[] elements;
  }

  const Vector operator=(const Vector& another){
    if(&another != this){
      this->dimension = another.dimension;
      delete[] this->elements;
      this->elements = new double[dimension];
      for(int i = 0; i < dimension; i++){
        this->elements[i] = another.elements[i];
      }
    }
    return *this;
  }

  const Vector& operator+=(const Vector& another){
    if(this->dimension != another.dimension){
      cout<<"Mismatch dimension, cannot add"<<endl;
      return *this;
    }
    for(int i = 0; i < dimension; i++){
      elements[i] += another.elements[i];
    }
    return *this;
  }

  const Vector& operator-=(const Vector& another){
    if(this->dimension != another.dimension){
      cout<<"Mismatch dimension, cannot add"<<endl;
      return *this;
    }
    for(int i = 0; i < dimension; i++){
      elements[i] -= another.elements[i];
    }
    return *this;
  }

  const Vector& operator*=(double scaler){
    for(int i = 0; i < dimension; i++){
      elements[i] *= scaler;
    }
    return *this;
  }

  double dot(const Vector& another){
    if(this->dimension != another.dimension){
      cout<<"mismatch dimension"<<endl;
      return 0;
    }
    double out;
    for(int i = 0; i < dimension; i++){
      out += this->elements[i]*another.elements[i];
    }
    return out;
  }

  double& operator[](int index){
    return elements[index];
  }

  double operator[](int index) const{
    return elements[index];
  }

  void print() const{
    if(dimension == 0){
      cout<<"empty vector"<<endl;
      return;
    }
    cout<<"[ ";
    for(int i = 0; i < dimension - 1; i++){
      cout<<elements[i]<<", ";
    }
    cout<<elements[dimension-1]<<" ]"<<endl;
  }

  int getDimension() const{return dimension;}
  void setDimension(int dimension){this->dimension = dimension;}

  double getElement(int index) const{return elements[index];}
  void setElement(int index, double value){elements[index] = value;}
};



Vector operator+(const Vector& v1, const Vector& v2){
  if(v1.getDimension() != v2.getDimension()){
    cout<<"Mismatch dimension, cannot be added"<<endl;
    return Vector();
  }
  double elements[v1.getDimension()];
  for(int i = 0; i < v1.getDimension(); i++){
    elements[i] = v1[i] + v2[i];
  }
  return Vector(v1.getDimension(), elements);
}

Vector operator-(const Vector& v1, const Vector& v2){
  if(v1.getDimension() != v2.getDimension()){
    cout<<"Mismatch dimension, cannot be added";
    return Vector();
  }
  double elements[v1.getDimension()];
  for(int i = 0; i < v1.getDimension(); i++){
    elements[i] = v1[i] - v2[i];
  }
  return Vector(v1.getDimension(), elements);
}

Vector operator*(const Vector& v1, const Vector& v2){
  if(v1.getDimension() != v2.getDimension()){
    cout<<"Mismatch dimension, cannot be added";
    return Vector();
  }
  double elements[v1.getDimension()];
  for(int i = 0; i < v1.getDimension(); i++){
    elements[i] = v1[i]*v2[i];
  }
  return Vector(v1.getDimension(), elements);
}

#endif
