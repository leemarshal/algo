#include <iostream>
#include <cmath>

using namespace std;
int n;
char** arr;
void cpStar(int k) {
    int I = 3 * pow(2, k - 2);
    int J = 6 * pow(2, k - 2) - 1;
    for(int i = 0; i < I; i++) {
        for(int j = 0; j < J; j++) {
            arr[i + I][n - 1 - J + j] = arr[i][n - 1 - J / 2 + j];
            arr[i + I][n + j] = arr[i][n - 1 - J / 2 + j];
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n;
    int k = log2(n / 3);

    arr = new char*[n];
    for(int i = 0; i < n; i++) {
        arr[i] = new char[2 * n + 1];
        for(int j = 0; j < 2 * n; j++) {
            arr[i][j] = ' ';
        }
        arr[i][2 * n] = '\0';
    }

    arr[0][n - 1] = '*';
    arr[1][n - 2] = '*';
    arr[1][n] = '*';
    for(int j = 0; j < 5; j++) arr[2][n - 3 + j] = '*';

    for(int i = 2; i <= k + 1; i++) {
        cpStar(i);
    }

    for(int i = 0; i < n; i++) {
        cout << arr[i] << "\n";
    }

    for(int i = 0; i < n; i++)
        delete arr[i];
    delete[] arr;

    return 0;
}
//
// Created by 규북 on 3/20/24.
//
