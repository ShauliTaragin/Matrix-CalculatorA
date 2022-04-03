//
// Created by shaul on 03/04/2022.
//
#include <vector>
#include <exception>
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
            for (int i = 0; i <rows; ++i) {
                for (int j = 0; j <cols; ++j) {
                    this->matrix[i][j] = mat[cols*i +j];
                }
            }
        }

    };

}