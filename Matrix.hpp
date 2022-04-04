//
// Created by shaul on 03/04/2022.
//
#include <vector>
#include <exception>
#include <iostream>

using namespace std;

namespace zich {
    class Matrix {

    private:
        vector<vector<double>> matrix;
    public:
        // Constructor taking a vector and a matrix size
        //not using and initializing list because we need to for by for all the values.
        Matrix(vector<double> mat,
               const int rows,
               const int cols) {
            if(rows<0 || cols <0){
                throw invalid_argument("Please enter only non negative integers");
            }
            if(rows*cols != mat.size()){
                throw invalid_argument("The size you inputted is incorrect");
            }
            for (size_t i = 0; i <rows; ++i) {
                for (size_t j = 0; j <cols; ++j) {
                    this->matrix[i][j] = mat[cols*i +j];
                }
            }
        }
        size_t row() const { //check add noniscard
            return this->matrix.size();
        }
        size_t cols() const {
            return this->matrix[0].size();
        }
        // in keeping with conventional practice I shall declare all our operator functions here and implement them in the cpp class.
        // unary operators
        Matrix operator-();
        Matrix operator+();

        //binary operators
        Matrix operator+(Matrix& other) const;
        Matrix operator-(Matrix &other) const;
        Matrix& operator+=(const Matrix& other);
        Matrix& operator-=(const Matrix& other);

        //binary multiplication operators
        Matrix operator*(double scalar) const;
        Matrix& operator*=(double scalar);

        //comparison operators
        bool operator==(const Matrix& other);
        bool operator!=(const Matrix& other);
        bool operator>(const Matrix& other);
        bool operator<(const Matrix& other);
        bool operator>=(const Matrix& other);
        bool operator<=(const Matrix& other);

        //prefix|postfix increment|decrement
        Matrix& operator++();
        void operator++(int we_are_postfixing);
        Matrix& operator--();
        void operator--(int we_are_postfixing);

        //scalar multiplication
        friend Matrix operator*(double scalar , const Matrix & m);

        //matrix multiplication
        friend Matrix operator*(const Matrix & m1 , const Matrix & m2);

        //input output
        friend std::ostream& operator<< (std::ostream& output, const Matrix& m);
        friend std::istream& operator>> (std::istream& input , Matrix& m);
    };

}