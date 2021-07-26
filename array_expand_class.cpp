#include <iostream>
#include <fstream>
using namespace std;

/**
 * This function reads a Matrix from file input.
 *
 * @param filepath    Input file path
 * @param rows        Number of rows
 * @param cols        Number of columns
 */
double** ReadMatrix(char* filepath, int& rows, int& cols){
    fstream infile;
    infile.open(filepath);
    
    double **mat = new double * [rows];
    for(int i = 0; i < rows; i++){
        mat[i] = new double[cols];
    }
    
    for(int j = 0; j < rows; j++){
        for(int k = 0; k < cols; k++){
            infile >> mat[j][k];
        }
    }
    
    infile.close();
    return mat;
}

/**
 * This function performs the summation of the matrix
 *
 * @param A         First Matrix
 * @param A_rows    Number of rows for First Matrix
 * @param A_cols    Number of columns for First Matrix
 * @param B         Second Matrix
 * @param B_rows    Number of rows for Second Matrix
 * @param B_cols    Number of columns for Second Matrix
 * @param rows      Empty Number of rows
 * @param cols      Empty Number of columns
 */
double** MatrixProduct(double** A, int A_rows, int A_cols, double** B, int B_rows, int B_cols, int& rows, int& cols){
    rows = A_rows;
    cols = B_cols;
    double **matrix = new double * [rows];
    for(int x = 0; x < rows; x++){
        matrix[x] = new double[cols];
    }
    for(int i = 0; i < rows; i++){
        for(int j = 0; j < cols; j++){
            double matrix = 0;
            for(int k = 0; k < A_cols; k++){
                matrix += A[i][k]*B[j][k];
            }
            matrix = 0;
        }
    }
    return matrix;
}

/**
 * This function prints out the matrix
 *
 * @param A       Current Matrix
 * @param rows    Number of rows
 * @param cols    Number of columns
 */
void WriteMatrix(double** A, int rows, int cols){
    if(A == NULL)
        return;
    cout << rows << " " << cols << endl;
    for(int i = 0; i < rows; i++){
        for(int j = 0; j < cols; j++){
            cout << A[i][j] << " ";
            cout << endl;
        }
    }
}

/**
 * This function deletes the memory of the matrix
 *
 * @param matrix   Current Matrix
 * @param rows     Number of rows
 * @param cols     Number of columns
 */
void Empty(double **matrix, int rows, int cols){
    for(int i = 0; i < rows; i++){
        delete matrix[i];
        delete matrix;
    }
}

/**
 * This function is the main/driver method.
 * This program creates an array based off of the size entered and resizes the array.
 *
 * @param argc    input values
 * @param argv    input values
 */
int main(int argc, char* argv[]){
    if(argc == 1){
        return 0;
    }
    else if(argc == 2){
        int rows1, cols1;
        
        double **A = ReadMatrix(argv[1], rows1, cols1);
        WriteMatrix(A, rows1, cols1);
        delete(A);
    }
    else if(argc == 3){
        int rows1, cols1, rows2, cols2, rows, cols;
        
        double **A = ReadMatrix(argv[1], rows1, cols1);
        double **B = ReadMatrix(argv[2], rows2, cols2);
        double **C = MatrixProduct(A, rows1, cols1, B, rows2, cols2, rows, cols);
        
        WriteMatrix(C, rows, cols);
        
        delete(A);
        delete(B);
        delete(C);
    }
    else if(argc >= 4){
        int rows1, cols1, rows2, cols2, rows3, cols3, rows, cols, rowsC, colsC;
        
        double **A = ReadMatrix(argv[1], rows1, cols1);
        double **C = ReadMatrix(argv[2], rows2, cols2);
        double **B = ReadMatrix(argv[3], rows3, cols3);;
        double **X = MatrixProduct(A, rows1, cols1, B, rows2, cols2, rows, cols);
        double **X1 = MatrixProduct(X, rows, cols, C, rows3, cols3, rowsC, colsC);
        
        WriteMatrix(X1, rowsC, colsC);
        
        delete(A);
        delete(B);
        delete(C);
        delete(X);
        delete(X1);
    }
    return 0;
}
