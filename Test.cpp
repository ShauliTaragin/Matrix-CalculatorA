//
// Created by shaul on 05/04/2022.
//
#include "Matrix.hpp"
#include "doctest.h"
#include <string>
#include <sstream>

using namespace zich;
using namespace std;
TEST_CASE ("Constructor Test Good case")
{
    //checking integers
    vector<double> vec1 = {1, 0, 0, 0, 1, 0, 0, 0, 1};
    vector<double> vec2 = {2, 2, 2, 2, 2, 2, 2, 2, 2, 2};
    vector<double> vec3 = {21, 22, 51, 15151, 72, -112, -21, -9, -16, 43, 13, 51, 52, 672, -14, 41};
            CHECK_NOTHROW(Matrix(vec1, 3, 3));
            CHECK_NOTHROW(Matrix(vec1, 9, 1));
            CHECK_NOTHROW(Matrix(vec1, 1, 9));
            CHECK_NOTHROW(Matrix(vec2, 2, 5));
            CHECK_NOTHROW(Matrix(vec2, 5, 2));
            CHECK_NOTHROW(Matrix(vec2, 10, 1));
            CHECK_NOTHROW(Matrix(vec2, 1, 10));
            CHECK_NOTHROW(Matrix(vec3, 4, 4));
            CHECK_NOTHROW(Matrix(vec3, 2, 8));
            CHECK_NOTHROW(Matrix(vec3, 8, 2));
            CHECK_NOTHROW(Matrix(vec3, 16, 1));
            CHECK_NOTHROW(Matrix(vec3, 1, 16));
    //checking floats
    vector<double> vec4 = {21.25, 22.12, 51.0, 15151.2, 72.151, -112.15, -21, -9, -16, 43, 13, 51, 52, 672.366, -14,
                           41.152};
            CHECK_NOTHROW(Matrix(vec4, 4, 4));
            CHECK_NOTHROW(Matrix(vec4, 2, 8));
            CHECK_NOTHROW(Matrix(vec4, 8, 2));
            CHECK_NOTHROW(Matrix(vec4, 16, 1));
            CHECK_NOTHROW(Matrix(vec4, 1, 16));
}

TEST_CASE ("Constructor Test Bad case")
{
    vector<double> vec1 = {1, 0, 0, 0, 1, 0, 0, 0, 1};
    vector<double> vec2 = {2, 2, 2, 2, 2, 2, 2, 2, 2, 2};
            CHECK_THROWS(Matrix(vec1, 4, 3));
            CHECK_THROWS(Matrix(vec1, 3, 5));
            CHECK_THROWS(Matrix(vec1, 4, 4));
            CHECK_THROWS(Matrix(vec1, 9, 0));
            CHECK_THROWS(Matrix(vec1, 0, 9));
            CHECK_THROWS(Matrix(vec1, 3, -3));
            CHECK_THROWS(Matrix(vec1, -3, 3));
            CHECK_THROWS(Matrix(vec1, -3, -3));
            CHECK_THROWS(Matrix(vec2, 5, 3));
            CHECK_THROWS(Matrix(vec2, 3, 5));
            CHECK_THROWS(Matrix(vec2, 4, 4));
            CHECK_THROWS(Matrix(vec2, 10, 0));
            CHECK_THROWS(Matrix(vec2, 0, 10));
            CHECK_THROWS(Matrix(vec2, 5, -2));
            CHECK_THROWS(Matrix(vec2, -2, 5));
            CHECK_THROWS(Matrix(vec2, -2, -5));

}

TEST_CASE ("Unary operators test") {
    vector<double> vec1 = {2, 2, 2, 2, 2, 2, 2, 2, 2};
    vector<double> vec1_minus = {-2, -2, -2, -2, -2, -2, -2, -2, -2};
    vector<double> vec2 = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15};
    vector<double> vec2plus = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16};
    vector<double> vec3 = {0.5, 1.5, 2.5, 3.5};
    vector<double> vec3_check = {1000.5, 1001.5, 1002.5, 1003.5};
    Matrix a(vec1, 3, 3);
    Matrix b(vec2, 4, 4);
    Matrix c(vec3, 1, 4);
    Matrix a_copy = (+a);
    Matrix a_minus(vec1_minus, 3, 3);
    Matrix a_minusss(vec1_minus, 9, 1);
    Matrix bplus(vec2plus, 4, 4);
    Matrix c_check(vec3_check, 1, 4);
            CHECK((&a_copy != &a)); //make sure its a copy
            CHECK((a_copy == a)); //but all values are the same
            CHECK((-a == a_minus));
            CHECK((-a != a));
            CHECK_THROWS(bool ans = (a_minus != a_minusss));
    b++;
            CHECK((b == bplus));
    //checking decrement
    for (int i = 0; i < 4; ++i) {
            CHECK((a != a_minus));
        a--;
    }
            CHECK((a == a_minus));
    //now let's do that same test but with big numbers
    for (int i = 0; i < 1000; ++i) {
            CHECK((c != c_check));
        c++;
    }
            CHECK((c == c_check));
}

TEST_CASE ("Binary operators test") {
    vector<double> vec1 = {2, 2, 2, 2, 2, 2, 2, 2, 2};
    vector<double> vec1_minus = {-2, -2, -2, -2, -2, -2, -2, -2, -2};
    vector<double> vec2 = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15};
    vector<double> vec2plus = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16};
    vector<double> vec3 = {1,0,0,1};
    vector<double> vec3_check = {1000.5, 1001.5, 1002.5, 1003.5};
    vector<double> vec4 = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};
    vector<double> vec5 = {1, 3, 4, -1};
    vector<double> vec6 = {7, 7, 7, 7};
    Matrix mat0(vec1, 3, 3);
    Matrix mat1(vec1_minus, 3, 3);
    Matrix mat2(vec2, 4, 4);
    Matrix mat3(vec2plus, 4, 4);
    Matrix mat4(vec3, 2, 2);
    Matrix mat5(vec3_check, 2, 2);
    Matrix mat6(vec4, 4, 4);
    Matrix mat7(vec5, 4, 1);
    Matrix mat8(vec6, 4, 1);
            CHECK((mat6 + mat2 == mat3));
            CHECK(((-1) * mat1 == mat0));
            CHECK((mat1 * (-1) == mat0));
            CHECK_NOTHROW((mat0*=-1));
            CHECK((mat1 == mat0));
            CHECK((mat3 - mat2 == mat6));
            CHECK((mat3 - mat2 == mat6));
            //test some matrix multiplication
            CHECK((mat4 * mat5 == mat5));
            CHECK((mat5 * mat4 == mat5));
            CHECK((mat4 * mat4 == mat4));
            CHECK((mat6 * mat7 == mat8));
            CHECK_THROWS(bool ans = (mat7*mat6  == mat8));
            CHECK_THROWS(bool ans = (mat4*mat6  == mat8));
            CHECK_THROWS(bool ans = (mat7*mat4  == mat8));
            CHECK_THROWS(bool ans = (mat1*mat8  == mat8));
            CHECK_THROWS(bool ans = (mat0*mat5  == mat8));
}

TEST_CASE ("comparison operators test") {
    vector<double> vec0 = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    vector<double> vec1 = {2, 2, 2, 2, 2, 2, 2, 2, 2, 2};
    vector<double> vec2 = {1, 1, 1, 1, 1, -2, -2, -2, -2, 3};
    vector<double> vec3 = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    vector<double> vec4 = {0, 1, 2, 3, 4, 5, 6, 7,};
    Matrix mat0(vec0, 5, 2);
    Matrix mat00(vec0, 5, 2);
    Matrix mat1(vec1, 5, 2);
    Matrix mat2(vec2, 5, 2);
    Matrix mat3(vec3, 5, 2);
    Matrix mat4(vec4, 4, 2);
            CHECK((mat0 == mat00));
            CHECK((mat0 >= mat2));
            CHECK((mat2 <= mat1));
            CHECK((mat3 > mat1));
            CHECK((mat3 >= mat2));
            CHECK((mat0 < mat1));
            CHECK((mat1 != mat3));
            CHECK((mat2 != mat3));
            CHECK((mat3 != mat2));
            CHECK((mat3 != mat1));
            CHECK((mat0 != mat1));
            CHECK((mat0 != mat2));
            CHECK((mat0 != mat3));
            CHECK_THROWS(bool ans = (mat4 != mat3));
            CHECK_THROWS(bool ans = (mat0 != mat4));
            CHECK_THROWS(bool ans = (mat4 == mat1));
            CHECK_THROWS(bool ans = (mat4 >= mat2));
            CHECK_THROWS(bool ans = (mat4 > mat3));


}

TEST_CASE ("Output Input Test"){
    vector<double> vec0 = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    vector<double> vec1 = {2, 2, 2, 2, 2, 2, 2, 2, 2, 2};
    Matrix mat0(vec0, 5, 2);
    Matrix mat1(vec1, 10, 1);
    stringstream s1;
    s1 << mat0;
        CHECK_EQ(s1.str() , "[0 0]\n"
                            "[0 0]\n"
                            "[0 0]\n"
                            "[0 0]\n"
                            "[0 0]\n");
    stringstream s2;
    s2 << mat1;
        CHECK_EQ(s2.str() , "[2]\n"
                            "[2]\n"
                            "[2]\n"
                            "[2]\n"
                            "[2]\n"
                            "[2]\n"
                            "[2]\n"
                            "[2]\n"
                            "[2]\n"
                            "[2]\n");
        CHECK((s1.str()!=s2.str()));
    s1.str("");
    s2.str("");

}