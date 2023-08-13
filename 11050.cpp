#include <iostream>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, k;
    cin >> n >> k;
    int arr[11][11];
    for(int i = 0; i < 11; i++) {
        arr[i][0] = 1;
        arr[i][i] = 1;
    }
    for(int i = 2; i < 11; i++) {
        for(int j = 1; j < i; j++) {
            arr[i][j] = arr[i - 1][j - 1] + arr[i - 1][j];
        }
    }
    cout << arr[n][k];
    return 0;
}
//
// Created by 규북 on 2023/08/13.
//
