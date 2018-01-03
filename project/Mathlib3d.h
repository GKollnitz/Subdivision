//
// Created by gunkol-5 on 9/5/17.
//

#ifndef GSCEPT_LAB_ENV_MATHLIB3D_H
#define GSCEPT_LAB_ENV_MATHLIB3D_H
#pragma once
#include <math.h>
#include <iostream>

class Vector4D
{
    friend class Matrix4D;

public:

    //	|0| |x|
    //	|1| |y|
    //	|2| |z|
    //	|3| |1|
    float cooV[4];

    //Constructor
    Vector4D() { for (int i = 0; i < 3; i++) { cooV[i] = 0; } cooV[3] = 1.0f; }; //Constructor
    Vector4D(float x, float y, float z)
    {
        cooV[0] = x;
        cooV[1] = y;
        cooV[2] = z;
        cooV[3] = 1.0f;
    }

    //Functions
    void set(float x, float y, float z, float w)
    {
        cooV[0] = x;
        cooV[1] = y;
        cooV[2] = z;
        cooV[3] = w;
    };
    float operator[](int i) //Overloading the [] operator to easier access the array
    {
        return cooV[i];
    };

    Vector4D operator*(float a) //Scaling function for Vectors
    {
        Vector4D vec;
        float x = cooV[0] * a;
        float y = cooV[1] * a;
        float z = cooV[2] * a;
        vec.cooV[0] = x;
        vec.cooV[1] = y;
        vec.cooV[2] = z;
        return vec;
    };

    Vector4D norm() { //Normalize function for the Vector
        Vector4D vec;
        vec = *this;


        float div = 1.0f / this->vectorLength();
        vec = vec * div;

        return vec;
    }

    float vectorLength() //Length of the Vector (Pythagoras)
    {

        float length;
        float x = cooV[0];
        float y = cooV[1];
        float z = cooV[2];
        length = sqrt(x*x + y*y + z*z);
        return length;
    };

    float operator*(const Vector4D & b) //Dotproduct
    {
        return (cooV[0] * b.cooV[0] + cooV[1] * b.cooV[1]);
    };

    Vector4D operator^(const Vector4D &a) //Crossproduct
    {
        Vector4D vec;
        float x = cooV[1] * a.cooV[2] - cooV[2] * a.cooV[1];
        float y = cooV[2] * a.cooV[0] - cooV[0] * a.cooV[2];
        float z = cooV[0] * a.cooV[1] - cooV[1] * a.cooV[0];
        vec.cooV[0] = x;
        vec.cooV[1] = y;
        vec.cooV[2] = z;
        return vec;
    };

    Vector4D operator+ (Vector4D a) //Overloading the + operator for Vectors
    {
        Vector4D vec;
        float x = cooV[0] + a.cooV[0];
        float y = cooV[1] + a.cooV[1];
        float z = cooV[2] + a.cooV[2];
        vec.cooV[0] = x;
        vec.cooV[1] = y;
        vec.cooV[2] = z;
        return vec;
    };

    Vector4D operator- (Vector4D a) //Overloading the - operator for Vectors
    {
        Vector4D vec;
        float x = cooV[0] - a.cooV[0];
        float y = cooV[1] - a.cooV[1];
        float z = cooV[2] - a.cooV[2];
        vec.cooV[0] = x;
        vec.cooV[1] = y;
        vec.cooV[2] = z;
        return vec;
    };



};


class Matrix4D
{
    friend class Vector4D;

public:

    //	| 0,  1,  2,  3|	| x1, x2, x3, x4 |
    //	| 4,  5,  6,  7|	| y1, y2, y3, y4 |
    //	| 8,  9, 10, 11|	| z1, z2, z3, z4 |
    //	|12, 13, 14, 15|	| w1, w2, w3, w4 |

    float cooM[16];

    //Constructor
    Matrix4D()
    {
        for (int i = 0; i < 16; i++)
        {
            cooM[i] = 0.0f;
        }
        cooM[15] = 1.0f;
    };

    Matrix4D(float x1, float x2, float x3, float y1, float y2, float y3, float z1, float z2, float z3) //Constructor for the inner 3x3 matrix
    {
        cooM[0] = x1;
        cooM[1] = x2;
        cooM[2] = x3;
        cooM[4] = y1;
        cooM[5] = y2;
        cooM[6] = y3;
        cooM[8] = z1;
        cooM[9] = z2;
        cooM[10] = z3;
        cooM[11] = 0.0f;
        cooM[12] = 0.0f;
        cooM[13] = 0.0f;
        cooM[14] = 0.0f;
        cooM[15] = 1.0f;
        cooM[3] = 0.0f;
        cooM[7] = 0.0f;
    }

    Matrix4D(float x1, float x2, float x3, float y1, float y2, float y3, float z1, float z2, float z3, float x4, float y4, float z4, float w1, float w2, float w3, float w4) //Constructor for all values
    {
        cooM[0] = x1;
        cooM[1] = x2;
        cooM[2] = x3;
        cooM[4] = y1;
        cooM[5] = y2;
        cooM[6] = y3;
        cooM[8] = z1;
        cooM[9] = z2;
        cooM[10] = z3;
        cooM[11] = z4;
        cooM[12] = w1;
        cooM[13] = w2;
        cooM[14] = w3;
        cooM[15] = w4;
        cooM[3] = x4;
        cooM[7] = y4;
    }

    //Functions

    float operator[](int i)
    {
        return cooM[i];
    };

    Vector4D operator* (Vector4D vec) //Matrix * Vector = Vector
    {
        Vector4D newVec;
        newVec.cooV[0] = cooM[0] * vec.cooV[0] + cooM[1] * vec.cooV[1] + cooM[2] * vec.cooV[2];
        newVec.cooV[1] = cooM[4] * vec.cooV[0] + cooM[5] * vec.cooV[1] + cooM[6] * vec.cooV[2];
        newVec.cooV[2] = cooM[8] * vec.cooV[0] + cooM[9] * vec.cooV[1] + cooM[10] * vec.cooV[2];
        return newVec;

    };

    Matrix4D rotationMatrixX(float v, Matrix4D mat)
    {
        Matrix4D rotMat(1.0f, 0.0f, 0.0f, 0.0f, cos(v), -sin(v), 0.0f, sin(v), cos(v)); //Rotation around the X axis
        return rotMat*mat;
    };

    Matrix4D rotationMatrixY(float v, Matrix4D mat)
    {
        Matrix4D rotMat(cos(v), 0.0f, sin(v), 0.0f, 1.0f, 0.0f, -sin(v), 0.0f, cos(v)); //Rotation around the Y axis
        return rotMat*mat;
    };

    Matrix4D rotationMatrixZ(float v, Matrix4D mat)
    {
        Matrix4D rotMat(cos(v), -sin(v), 0.0f, sin(v), cos(v), 0.0f, 0.0f, 0.0f, 1.0f); //Rotation around the Z axis
        return rotMat*mat;
    };

    Vector4D rotationMatrixV(Vector4D vec, float v) //RotationMatrix for a Vector
    {
        float x = vec.cooV[0];
        float y = vec.cooV[1];
        float z = vec.cooV[2];
        float x1 = x * x + (1 - x * x) * cos(v);
        float x2 = x * y * (1 - cos(v)) - x * sin(v);
        float x3 = x * z * (1 - cos(v)) + y * sin(v);
        float y1 = x * y * (1 - cos(v)) + z * sin(v);
        float y2 = y * y + (1 - y * y) * cos(v);
        float y3 = x * z * (1 - cos(v)) - x * sin(v);
        float z1 = x * z * (1 - cos(v)) - y * sin(v);
        float z2 = y * z * (1 - cos(v)) + x * sin(v);
        float z3 = z * z + (1 - z * z)  * cos(v);

        Matrix4D rotMat(x1, x2, x3, y1, y2, y3, z1, z2, z3); //Rotation runt vektor
        return rotMat*vec;

    };

    Matrix4D inverseMatrix() //Inverse 4x4 Matrix
    {
        Matrix4D newMat;
        int determinant;
        float a11 = cooM[0];	float a12 = cooM[1];	float a13 = cooM[2];	float a14 = cooM[3]; //Changing names to make it easier on the eyes
        float a21 = cooM[4];	float a22 = cooM[5];	float a23 = cooM[6];	float a24 = cooM[7];
        float a31 = cooM[8];	float a32 = cooM[9];	float a33 = cooM[10];	float a34 = cooM[11];
        float a41 = cooM[12];	float a42 = cooM[13];	float a43 = cooM[14];	float a44 = cooM[15];

        determinant = a11*a22*a33*a44 + a11*a23*a34*a42 + a11*a24*a32*a43 //Calculating the Determinant
                      + a12*a21*a34*a43 + a12*a23*a31*a44 + a12*a24*a33*a41
                      + a13*a21*a32*a44 + a13*a22*a34*a41 + a13*a24*a31*a42
                      + a14*a21*a33*a42 + a14*a22*a31*a43 + a14*a23*a32*a41
                      - a11*a22*a34*a43 - a11*a23*a32*a44 - a11*a24*a33*a42
                      - a12*a21*a33*a44 - a12*a23*a34*a41 - a12*a24*a31*a43
                      - a13*a21*a34*a42 - a13*a22*a31*a44 - a13*a24*a32*a41
                      - a14*a21*a32*a43 - a14*a22*a33*a41 - a14*a23*a31*a42;

        newMat.cooM[0] = a22*a33*a44 + a23*a34*a42 + a24*a32*a43 - a22*a34*a43 - a23*a32*a44 - a24*a33*a42;
        newMat.cooM[1] = a12*a34*a43 + a13*a32*a44 + a14*a33*a42 - a12*a33*a44 - a13*a34*a42 - a14*a32*a43;
        newMat.cooM[2] = a12*a23*a44 + a13*a24*a42 + a14*a22*a43 - a12*a24*a43 - a13*a22*a44 - a14*a23*a42;
        newMat.cooM[3] = a12*a24*a33 + a13*a22*a34 + a14*a23*a32 - a12*a23*a34 - a13*a24*a32 - a14*a22*a33;
        newMat.cooM[4] = a21*a34*a43 + a23*a31*a44 + a24*a33*a41 - a21*a33*a44 - a23*a34*a41 - a24*a31*a43;
        newMat.cooM[5] = a11*a33*a44 + a13*a34*a41 + a14*a31*a43 - a11*a34*a43 - a13*a31*a44 - a14*a33*a41;
        newMat.cooM[6] = a11*a24*a43 + a13*a21*a44 + a14*a23*a41 - a11*a23*a44 - a13*a24*a41 - a14*a21*a43;
        newMat.cooM[7] = a11*a23*a34 + a13*a24*a31 + a14*a21*a33 - a11*a24*a33 - a13*a21*a34 - a14*a23*a31;
        newMat.cooM[8] = a21*a32*a44 + a22*a34*a41 + a24*a31*a42 - a21*a34*a42 - a22*a31*a44 - a24*a32*a41;
        newMat.cooM[9] = a11*a34*a42 + a12*a31*a44 + a14*a32*a41 - a11*a32*a44 - a12*a34*a41 - a14*a31*a42;
        newMat.cooM[10] = a11*a22*a44 + a12*a24*a41 + a14*a21*a42 - a11*a24*a42 - a12*a21*a44 - a14*a22*a41;
        newMat.cooM[11] = a11*a24*a32 + a12*a21*a34 + a14*a22*a31 - a11*a22*a34 - a12*a24*a31 - a14*a21*a32;
        newMat.cooM[12] = a21*a33*a42 + a22*a31*a43 + a23*a32*a41 - a21*a32*a43 - a22*a33*a41 - a23*a31*a42;
        newMat.cooM[13] = a11*a32*a43 + a12*a33*a41 + a13*a31*a42 - a11*a33*a42 - a12*a31*a43 - a13*a32*a41;
        newMat.cooM[14] = a11*a23*a42 + a12*a21*a43 + a13*a22*a41 - a11*a22*a43 - a12*a23*a41 - a13*a21*a42;
        newMat.cooM[15] = a11*a22*a33 + a12*a23*a31 + a13*a21*a32 - a11*a23*a32 - a12*a21*a33 - a13*a22*a31;


        if (determinant == 0)
        {
            std::cout << "determinant is zero" << std::endl;
            return newMat;
        }
        std::cout << determinant << std::endl;
        for(int i=0; i<16; i++)
        {
            newMat.cooM[i] = newMat.cooM[i] / determinant;
        }


        return newMat;
    };

    Matrix4D transposeMatrix() //Transpose function for the Matrix. "Rows and and Columns exchange values"

    {
        Matrix4D newMat;
        newMat.cooM[0] = cooM[0];
        newMat.cooM[1] = cooM[4];
        newMat.cooM[2] = cooM[8];
        newMat.cooM[3] = cooM[12];
        newMat.cooM[4] = cooM[1];
        newMat.cooM[5] = cooM[5];
        newMat.cooM[6] = cooM[9];
        newMat.cooM[7] = cooM[13];
        newMat.cooM[8] = cooM[2];
        newMat.cooM[9] = cooM[6];
        newMat.cooM[10] = cooM[10];
        newMat.cooM[11] = cooM[14];
        newMat.cooM[12] = cooM[3];
        newMat.cooM[13] = cooM[7];
        newMat.cooM[14] = cooM[11];

        return newMat;
    };

    Matrix4D operator* (Matrix4D mat) //Overloading the * operator for Matrixes
    {
        Matrix4D newMat;
        newMat.cooM[0] = cooM[0] * mat.cooM[0] + cooM[1] * mat.cooM[4] + cooM[2] * mat.cooM[8] + cooM[3] * mat.cooM[12];
        newMat.cooM[1] = cooM[0] * mat.cooM[1] + cooM[1] * mat.cooM[5] + cooM[2] * mat.cooM[9] + cooM[3] * mat.cooM[13];
        newMat.cooM[2] = cooM[0] * mat.cooM[2] + cooM[1] * mat.cooM[6] + cooM[2] * mat.cooM[10] + cooM[3] * mat.cooM[14];
        newMat.cooM[3] = cooM[0] * mat.cooM[3] + cooM[1] * mat.cooM[7] + cooM[2] * mat.cooM[11] + cooM[3] * mat.cooM[15];

        newMat.cooM[4] = cooM[4] * mat.cooM[0] + cooM[5] * mat.cooM[4] + cooM[6] * mat.cooM[8] + cooM[7] * mat.cooM[12];
        newMat.cooM[5] = cooM[4] * mat.cooM[1] + cooM[5] * mat.cooM[5] + cooM[6] * mat.cooM[9] + cooM[7] * mat.cooM[13];
        newMat.cooM[6] = cooM[4] * mat.cooM[2] + cooM[5] * mat.cooM[6] + cooM[6] * mat.cooM[10] + cooM[7] * mat.cooM[14];
        newMat.cooM[7] = cooM[4] * mat.cooM[3] + cooM[5] * mat.cooM[7] + cooM[6] * mat.cooM[11] + cooM[7] * mat.cooM[15];

        newMat.cooM[8] = cooM[8] * mat.cooM[0] + cooM[9] * mat.cooM[4] + cooM[10] * mat.cooM[8] + cooM[11] * mat.cooM[12];
        newMat.cooM[9] = cooM[8] * mat.cooM[1] + cooM[9] * mat.cooM[5] + cooM[10] * mat.cooM[9] + cooM[11] * mat.cooM[13];
        newMat.cooM[10] = cooM[8] * mat.cooM[2] + cooM[9] * mat.cooM[6] + cooM[10] * mat.cooM[10] + cooM[11] * mat.cooM[14];
        newMat.cooM[11] = cooM[0] * mat.cooM[3] + cooM[9] * mat.cooM[7] + cooM[10] * mat.cooM[11] + cooM[11] * mat.cooM[15];

        newMat.cooM[12] = cooM[12] * mat.cooM[0] + cooM[13] * mat.cooM[4] + cooM[14] * mat.cooM[8] + cooM[15] * mat.cooM[12];
        newMat.cooM[13] = cooM[12] * mat.cooM[1] + cooM[13] * mat.cooM[5] + cooM[14] * mat.cooM[9] + cooM[15] * mat.cooM[13];
        newMat.cooM[14] = cooM[12] * mat.cooM[2] + cooM[13] * mat.cooM[6] + cooM[14] * mat.cooM[10] + cooM[15] * mat.cooM[14];
        newMat.cooM[15] = cooM[12] * mat.cooM[3] + cooM[13] * mat.cooM[7] + cooM[14] * mat.cooM[11] + cooM[15] * mat.cooM[15]; //plats 15 ska vara 1
        return newMat;
    };
};




#endif //GSCEPT_LAB_ENV_MATHLIB3D_H
