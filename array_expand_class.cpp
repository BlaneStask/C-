//Description: This program creates an array based off of the size entered and resizes the array.

#include <iostream>
#include <fstream>
using namespace std;

double** ReadMatrix(char* filepath, int& rows, int& cols){
    fstream infile;
    infile.open(filepath);//Opens text files from directory - A.txt, B.txt, C.txt
    double **mat = new double * [rows];//Uses the dynamic memory X to create matrix
    for(int i = 0; i < rows; i++){
        mat[i] = new double[cols];
    }
    //row
    for(int j = 0; j < rows; j++){
        //cols
        for(int k = 0; k < cols; k++){
            infile >> mat[j][k];//Outputs the value into the matrix
        }
    }
    infile.close();
    return mat;
}

double** MatrixProduct(double** A, int A_rows, int A_cols, double** B, int B_rows, int B_cols, int& rows, int& cols){
    rows = A_rows;
    cols = B_cols;
    double **matrix = new double * [rows];//Makes the MatrixProd
    for(int x = 0; x < rows; x++){
        matrix[x] = new double[cols];
    }
    for(int i = 0; i < rows; i++){
        for(int j = 0; j < cols; j++){
            double matrix = 0;
            for(int k = 0; k < A_cols; k++){
                matrix += A[i][k]*B[j][k];
            }//This for loop performs the summation of the matrices
            matrix = 0;
        }
    }
    return matrix;
}

void WriteMatrix(double** A, int rows, int cols){
    if(A == NULL)
        return;
    cout << rows << " " << cols << endl;//Displays the matrix to console
    for(int i = 0; i < rows; i++){//This for loop runs though all matrix rows
        for(int j = 0; j < cols; j++){//This for loop runs through all matrix columns
            cout << A[i][j] << " ";
            cout << endl;
        }//This for loop writes out the rows and columns of the matrices
    }
}

void Empty(double **matrix, int rows, int cols){
    for(int i = 0; i < rows; i++){
        delete matrix[i];
        delete matrix;
    }
}//This for loop deletes the memory of the matrices after the program finishes

int main(int argc, char* argv[]){
    if(argc == 1){
        return 0;
    }//Integer columns and rows
    else if(argc == 2){
        int rows1, cols1;
        double **A = ReadMatrix(argv[1], rows1, cols1);
        WriteMatrix(A, rows1, cols1);//Constructs functions body
        delete(A);//Sends memory to the Void Empty function for deletion
    }//Returns the matrix
    else if(argc == 3){
        int rows1, cols1, rows2, cols2, rows, cols;
        double **A = ReadMatrix(argv[1], rows1, cols1);
        double **B = ReadMatrix(argv[2], rows2, cols2);
        double **C = MatrixProduct(A, rows1, cols1, B, rows2, cols2, rows, cols);
        WriteMatrix(C, rows, cols);//Constucts functions body
        delete(A);
        delete(B);
        delete(C);//sends memory to the Void Empty function for deletion
    }//Returns the matrix
    else if(argc >= 4){
        int rows1, cols1, rows2, cols2, rows3, cols3, rows, cols, rowsC, colsC;
        double **A = ReadMatrix(argv[1], rows1, cols1);
        double **C = ReadMatrix(argv[2], rows2, cols2);
        double **B = ReadMatrix(argv[3], rows3, cols3);;
        double **X = MatrixProduct(A, rows1, cols1, B, rows2, cols2, rows, cols);
        double **X1 = MatrixProduct(X, rows, cols, C, rows3, cols3, rowsC, colsC);
        WriteMatrix(X1, rowsC, colsC);//Constructs functions body
        delete(A);
        delete(B);
        delete(C);
        delete(X);
        delete(X1);//sends memory to the Void Empty function for deletion
    }//Returns the matrix
    return 0;
}
