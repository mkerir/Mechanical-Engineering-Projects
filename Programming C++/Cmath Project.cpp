#include <cmath>
#include <iostream>

using namespace std;

const int columns = 5;
const int rows = 4;

/*Let's declare a function to calculate the desired values using the given formula */
void compute(double angle_θ, double A[rows][columns]){
    for (int j = 0; j < rows; ++j){
        for (int i = 0; i < columns; ++i){
            A[j][i] = 25 * sin((angle_θ * i) / 23) + pow(-1, j) * 25 * sqrt((angle_θ * j) / 23);
        }
    }
}
/*This function allows us to construst and later display our matrix with the computed values */
void matrix(double A[rows][columns]){
    for (int j = 0; j < rows; ++j){
        for (int i = 0; i < columns; ++i){
            cout << A[j][i] << "  |  ";
        }
        cout << endl;
    }
}
/*We'll be using a swap function from the std lib to swap the values of columns 1 and 2 one at a time */
void change_columns(double A[rows][columns]){
    for (int j = 0; j < rows; ++j){
        swap(A[j][0], A[j][1]);
    }
}

int main() {
    double angle_θ;
    cout << "1. Input the angle theta in radians that you wish to compute : ";
    cin >> angle_θ;

    /*Calling the matrix and declaring it's elements, we print the results, and then call the swap function right after */
    double A[rows][columns];
    compute(angle_θ, A);
    cout << "\n2. Here are the values of matrix A in regular order : " << endl;
    matrix (A);
    change_columns(A);

    /*Let's determine the max value of row #3 */
    double max_value_row3 = A[2][0];
    for (int i = 1; i < columns; ++i){
        if (A[2][i] > max_value_row3){
            max_value_row3 = A[2][i];
        }
    }

    /*Let's determine the min value in column #4 */
    double min_value_col4 = A[0][3];
    for (int j = 1; j < rows; ++j){
        if (A[j][3] < min_value_col4){
            min_value_col4 = A[j][3];
        }
    }

    /*Calculating the sum of the matrix A */
    double sum_A = 0.0;
    for (int j = 0; j < rows; ++j) {
        for (int i = 0; i < columns; ++i) {
            sum_A += A[j][i];
        }
    }

    /*And finally we can print the matrix and the results of all our functions */
    cout << "\n3. Here are the values of matrix A after swapping columns 1 and 2 : " << endl;
    matrix(A);
    cout << endl;
    cout << "4.a) The maximum value in row 3 = " << max_value_row3;
    cout << "\n4.b) The minimum value in column 4 = " << min_value_col4;
    cout << "\n4.c) The sum of the matrix A = " << sum_A<< endl;
    return 0;
}