/*
 * 28. ���� ������� A �� N ����� � N ��������. ����� ������� �, ���� ������� � ������ �� �������.
���� ��� ���� i,j ����������� ����������� �ij+�ij>0, �������� �������� ������� �������� �������
�, ������� ������ ���������������� �������� ������� �, ��������� ����� �������� ������� �.
 */

#ifndef LABA6_VAR28_HEADER_FILE_H
#define LABA6_VAR28_HEADER_FILE_H

#include <iostream>
#include <c++/fstream>
#include <c++/iomanip>

using namespace std;

void  Input(int n, int **A, ifstream& input_file) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            input_file >> A[i][j];
        }
    }
}


void InputedMatrix(int n,int **A, ofstream& output_file)
{
    for (int i = 0; i < n; i++) {
        output_file << endl;
        for (int j = 0; j < n; j++) {
            output_file << setw(5) << A[i][j];

        }
    }
}


bool correct(int n,int** A, int **B)
{
    int k=0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if(A[i][j] + B[i][j] > 0)
            {
                k++;
            }
        }
    }

    if(k == n*n)
        return true;
    else
        return false;
}

void replacement(int n,int** A, int** B)
{
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if( A[i][j] < B[i][j] )
            {
                A[i][j] = B[i][j];
            }
        }
    }
}
#endif //LABA6_VAR28_HEADER_FILE_H
