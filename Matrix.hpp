//
// Created by shaul on 03/04/2022.
//
#include <vector>
#include <exception>
#include <iostream>


namespace zich{
    class Matrix {

    private:
        std::vector<std::vector<double>> matrix;
    public:
        // Constructor taking a vector and a matrix size
        //not using an initializing list because we need to for by for all the values.
        Matrix(std::vector<double> arr,int ,int);

        size_t row() const {
            return matrix.size();
        }
        size_t cols() const {
            return matrix[0].size();
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
        bool operator==(Matrix& other);
        bool operator!=(Matrix& other);
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