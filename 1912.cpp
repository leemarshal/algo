#include <iostream>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, max;
    cin >> n;
    int* arr = new int[n];
    for(int i = 0; i < n; i++)
        cin >> arr[i];
    max = arr[0];
    for(int i = 1; i < n; i++) {
        if(arr[i - 1] > 0) arr[i] += arr[i - 1];
        if(arr[i] > max) max = arr[i];
    }
    cout << max;
    delete[] arr;
    return 0;
}
//
// Created by 규북 on 2023/08/30.
//
