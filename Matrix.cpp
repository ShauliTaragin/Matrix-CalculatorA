//
// Created by shaul on 03/04/2022.
//

#include "Matrix.hpp"

namespace zich {

    //i know i need to return a new matrix that is minus matrix
    Matrix Matrix::operator-() {
        std::vector<double> arr;
        for (int i = 0; i < this->row() * this->cols(); ++i) {
            arr[i] = - this->matrix[i/cols()][i%cols()];
        }
        return Matrix(arr , this->row() , this->cols());
    }

    Matrix Matrix::operator+() {
        std::vector<double> arr;
        for (int i = 0; i < this->row() * this->cols(); ++i) {
            arr[i] = this->matrix[i/cols()][i%cols()];
        }
        return Matrix(arr , this->row() , this->cols());
    }

    /**
     * 
     * @param other matrix which we add each entry to our matrix
     * @return A copy of our matrix added with the other matrix
     */
    Matrix Matrix::operator+(Matrix &other) const {
        if (other.row() != this->row() || other.cols() != this->cols()) { // check that row() and cols() works
            throw invalid_argument("Both matrices need to be the same size");
        }
        std::vector<double> arr;
        for (int i = 0; i < other.row() * other.cols(); ++i) {
            arr[i] = other.matrix[i/cols()][i%cols()] + this->matrix[i/cols()][i%cols()];
        }
        return Matrix(arr , this->row() , this->cols());
    }
    /**
     *
     * @param other matrix which we subtract each entry from our matrix
     * @return A copy of our other matrix subtracted from our matrix
     */
    Matrix Matrix::operator-(Matrix &other) const {
        if (other.row() != this->row() || other.cols() != this->cols()) { // check that row() and cols() works
            throw invalid_argument("Both matrices need to be the same size");
        }
        std::vector<double> arr;
        for (int i = 0; i < other.row() * other.cols(); ++i) {
            arr[i] = this->matrix[i/cols()][i%cols()] - other.matrix[i/cols()][i%cols()] ;
        }
        return Matrix(arr , this->row() , this->cols());
    }

    /**
     * Notice we are working with the reference of our matrix
     * @param other matrix which we add each entry to our matrix
     * @return Our matrix added with the other matrix
     */
    Matrix &Matrix::operator+=(const Matrix &other) {
        if (other.row() != this->row() || other.cols() != this->cols()) {
            throw invalid_argument("Both matrices need to be the same size");
        }
        for (int i = 0; i < row(); ++i) {
            for (int j = 0; j <cols(); ++j) {
                this->matrix[i][j] += other.matrix[i][j];
            }
        }
        return *this;
    }
    /**
    * Notice we are working with the reference of our matrix
     * @param other matrix which we add subtract from each entry of our matrix
    * @return Our matrix minus the other matrix
    */
    Matrix &Matrix::operator-=(const Matrix &other) {
        if (other.row() != this->row() || other.cols() != this->cols()) {
            throw invalid_argument("Both matrices need to be the same size");
        }
        for (int i = 0; i < row(); ++i) {
            for (int j = 0; j <cols(); ++j) {
                this->matrix[i][j] -= other.matrix[i][j];
            }
        }
        return *this;
    }
    /**
     * Simply checking if each entry in other matrix is similar then ours
     * @param other matrix for which we test if our matrix equals it
     * @return true if they are identical false otherwise
     */
    bool Matrix::operator==(const Matrix &other) {
        if (other.row() != this->row() || other.cols() != this->cols()) {
            throw invalid_argument("Both matrices need to be the same size");
        }
        for (int i = 0; i < row(); ++i) {
            for (int j = 0; j <cols(); ++j) {
                if(this->matrix[i][j] != other.matrix[i][j])
                    return false;
            }
        }
        return true;
    }
    /**
    * Simply checking if one single entry in other matrix is different then ours
    * @param other matrix for which we test if our matrix doesn't equal it
    * @return false if they are identical true otherwise
    */
    bool Matrix::operator!=(const Matrix &other) {
        if (other.row() != this->row() || other.cols() != this->cols()) {
            throw invalid_argument("Both matrices need to be the same size");
        }
        for (int i = 0; i < row(); ++i) {
            for (int j = 0; j <cols(); ++j) {
                if(this->matrix[i][j] != other.matrix[i][j])
                    return true;
            }
        }
        return false;
    }
    /**
     * Checking if this matrix is greater then other matrix
     * @param other matrix for which we test if this matrix is greater then it
     * @return true if sum of this matrix is greater then sum of other matrix false otherwise
     */
    bool Matrix::operator>(const Matrix &other) {
        if (other.row() != this->row() || other.cols() != this->cols()) {
            throw invalid_argument("Both matrices need to be the same size");
        }
        double sum_me =0 ;
        double sum_other = 0;
        for (int i = 0; i < row(); ++i) {
            for (int j = 0; j <cols(); ++j) {
                sum_me+=this->matrix[i][j];
                sum_other+=other.matrix[i][j];
            }
        }
        return sum_me>sum_other;
    }
    /**
 * Checking if this matrix is smaller then other matrix
 * @param other matrix for which we test if this matrix is smaller then it
 * @return true if sum of this matrix is smaller then sum of other matrix false otherwise
 */
    bool Matrix::operator<(const Matrix &other) {
        if (other.row() != this->row() || other.cols() != this->cols()) {
            throw invalid_argument("Both matrices need to be the same size");
        }
        double sum_me =0 ;
        double sum_other = 0;
        for (int i = 0; i < row(); ++i) {
            for (int j = 0; j <cols(); ++j) {
                sum_me+=this->matrix[i][j];
                sum_other+=other.matrix[i][j];
            }
        }
        return sum_me<sum_other;
    }
    /**
 * Checking if this matrix is greater or equal to other matrix
 * @param other matrix for which we test if this matrix is greater or equal to it
 * @return true if sum of this matrix is greater or equal then the sum of other matrix false otherwise
 */
    bool Matrix::operator>=(const Matrix &other) {
        if (other.row() != this->row() || other.cols() != this->cols()) {
            throw invalid_argument("Both matrices need to be the same size");
        }
        double sum_me =0 ;
        double sum_other = 0;
        for (int i = 0; i < row(); ++i) {
            for (int j = 0; j <cols(); ++j) {
                sum_me+=this->matrix[i][j];
                sum_other+=other.matrix[i][j];
            }
        }
        return sum_me>=sum_other;
    }
    /**
    * Checking if this matrix is smaller or equal to other matrix
    * @param other matrix for which we test if this matrix is smaller or equal to it
    * @return true if sum of this matrix is smaller or equal then the sum of other matrix false otherwise
    */
    bool Matrix::operator<=(const Matrix &other) {
        if (other.row() != this->row() || other.cols() != this->cols()) {
            throw invalid_argument("Both matrices need to be the same size");
        }
        double sum_me =0 ;
        double sum_other = 0;
        for (int i = 0; i < row(); ++i) {
            for (int j = 0; j <cols(); ++j) {
                sum_me+=this->matrix[i][j];
                sum_other+=other.matrix[i][j];
            }
        }
        return sum_me<=sum_other;
    }
    /**
     * Adding 1 to each entry in this matrix prefix.
     * @return this matrix with each entry incremented by 1
     */
    Matrix &Matrix::operator++() {
        for (int i = 0; i < row(); ++i) {
            for (int j = 0; j <cols(); ++j) {
                this->matrix[i][j]++;
            }
        }
        return *this;
    }
    /**
    * Subtracting 1 to each entry in this matrix postfix.
    * @return this matrix with each entry decremented by 1
    */
    void Matrix::operator++(int we_are_postfixing){
        for (int i = 0; i < row(); ++i) {
            for (int j = 0; j <cols(); ++j) {
                this->matrix[i][j]++;
            }
        }
    }
    /**
 * Subtracting 1 to each entry in this matrix prefix.
 * @return this matrix with each entry decremented by 1
 */
    Matrix &Matrix::operator--() {
        for (int i = 0; i < row(); ++i) {
            for (int j = 0; j <cols(); ++j) {
                this->matrix[i][j]--;
            }
        }
        return *this;
    }
    /**
    * Subtracting 1 to each entry in this matrix postfix.
    * @return this matrix with each entry decremented by 1
    */
    void Matrix::operator--(int we_are_postfixing){
        for (int i = 0; i < row(); ++i) {
            for (int j = 0; j <cols(); ++j) {
                this->matrix[i][j]--;
            }
        }
    }
}