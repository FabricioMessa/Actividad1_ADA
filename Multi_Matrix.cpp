#include<iostream>
using namespace std;

const int MAX = 100; // Ajusta esto según el tamaño máximo de tu matriz

void multiply(int n, int a[MAX][MAX], int b[MAX][MAX], int result[MAX][MAX]) {
    if (n == 1) {
        result[0][0] = a[0][0] * b[0][0];
        return;
    }

    int temp1[MAX][MAX], temp2[MAX][MAX];

    // Divide las matrices en 4 sub-matrices y realiza las operaciones necesarias
    for (int i = 0; i < n / 2; i++) {
        for (int j = 0; j < n / 2; j++) {
            int a11 = a[i][j];
            int a12 = a[i][j + n / 2];
            int a21 = a[i + n / 2][j];
            int a22 = a[i + n / 2][j + n / 2];

            int b11 = b[i][j];
            int b12 = b[i][j + n / 2];
            int b21 = b[i + n / 2][j];
            int b22 = b[i + n / 2][j + n / 2];

            // Calcula los valores intermedios
            int m1 = (a11 + a22) * (b11 + b22);
            int m2 = (a21 + a22) * b11;
            int m3 = a11 * (b12 - b22);
            int m4 = a22 * (b21 - b11);
            int m5 = (a11 + a12) * b22;
            int m6 = (a21 - a11) * (b11 + b12);
            int m7 = (a12 - a22) * (b21 + b22);

            // Calcula los valores de la matriz resultante
            result[i][j] = m1 + m4 - m5 + m7;
            result[i][j + n / 2] = m3 + m5;
            result[i + n / 2][j] = m2 + m4;
            result[i + n / 2][j + n / 2] = m1 - m2 + m3 + m6;
        }
    }
}

int main() {
    int a[MAX][MAX] = {
        {1, 2, 3, 4, 5, 6, 7, 8},
        {9, 10, 11, 12, 13, 14, 15, 16},
        {17, 18, 19, 20, 21, 22, 23, 24},
        {25, 26, 27, 28, 29, 30, 31, 32},
        {33, 34, 35, 36, 37, 38, 39, 40},
        {41, 42, 43, 44, 45, 46, 47, 48},
        {49, 50, 51, 52, 53, 54, 55, 56},
        {57, 58, 59, 60, 61, 62, 63, 64}
    };

    int b[MAX][MAX] = {
        {65, 66, 67, 68, 69, 70, 71, 72},
        {73, 74, 75, 76, 77, 78, 79, 80},
        {81, 82, 83, 84, 85, 86, 87, 88},
        {89, 90, 91, 92, 93, 94, 95, 96},
        {97, 98, 99, 100, 101, 102, 103, 104},
        {105, 106, 107, 108, 109, 110, 111, 112},
        {113, 114, 115, 116, 117, 118, 119, 120},
        {121, 122, 123, 124, 125, 126, 127, 128}
    };

    int c[MAX][MAX];

    multiply(8, a, b, c);

    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++)
            cout << c[i][j] << " ";
        cout << "\n";
    }

    return 0;
}
