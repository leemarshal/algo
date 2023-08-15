#include <iostream>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, result;
    cin >> n;
    int arr[1000][3];
    for(int i = 0; i < n; i++)
        for(int j = 0; j < 3; j++)
            cin >> arr[i][j];

    arr[1][0] += (arr[0][1] < arr[0][2] ? arr[0][1] : arr[0][2]);
    arr[1][1] += (arr[0][0] < arr[0][2] ? arr[0][0] : arr[0][2]);
    arr[1][2] += (arr[0][0] < arr[0][1] ? arr[0][0] : arr[0][1]);

    for(int i = 2; i < n; i++) {
            arr[i][0] += (arr[i - 1][1] < arr[i - 1][2] ? arr[i - 1][1] : arr[i - 1][2]);
            arr[i][1] += (arr[i - 1][0] < arr[i - 1][2] ? arr[i - 1][0] : arr[i - 1][2]);
            arr[i][2] += (arr[i - 1][0] < arr[i - 1][1] ? arr[i - 1][0] : arr[i - 1][1]);
    }
    result = arr[n - 1][0];
    if(result > arr[n - 1][1]) result = arr[n - 1][1];
    if(result > arr[n - 1][2]) result = arr[n - 1][2];
    cout << result;
    return 0;
}
//
// Created by 규북 on 2023/08/15.
//