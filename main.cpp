#include <iostream>
#include <c++/fstream>
#include <c++/iomanip>
#include "header_file.h"

using namespace std;

int main() {
    int n, R;

    cout << "Hello, Maaaan!" << endl;


    char in[80];
    cout << "Enter input file name " << endl;
    gets(in);
    ifstream input_file(in);

    char out[80];
    cout << "Enter output file name " << endl;
    gets(out);
    ofstream output_file(out);


    input_file >> n;
    if (n < 2) {
        cout << "Matrix size MUST BE > or = 2" << endl;
        exit(1);
    }
    output_file << n << "  numbers of lines" << endl;
    output_file << n << "  numbers of colomns" << endl;

    int **A = new int *[n];
    for (int i = 0; i <n ; i++)
    {
        A[i] = new int [n];
    }

    Input(n,A,input_file);
    output_file << "\nInputed Matrix  A" << endl;
    InputedMatrix(n,A,output_file);

    int **B = new int *[n];
    for (int i = 0; i <n ; i++)
    {
        B[i] = new int [n];
    }

    Input(n,B,input_file);
    output_file << "\nInputed Matrix  B" << endl;
    InputedMatrix(n,B,output_file);

    if(correct(n,A,B))
    {
        replacement(n, A, B);
        output_file << "\n\n Changed Maxtrix A" << endl;
        InputedMatrix(n, A, output_file);
    }
    else
        output_file << "\n\ncorrection isn't need" << endl;


    input_file.close();
    output_file.close();

    for (int k = 0; k < n; k++) {
        delete[] A[k];
    }
    delete[] A;

    return 0;
}