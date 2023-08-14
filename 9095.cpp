#include <iostream>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, t;
    int arr[10];
    arr[0] = 1;
    arr[1] = 2;
    arr[2] = 4;
    for(int i = 3; i < 10; i++)
        arr[i] = arr[i - 1] + arr[i - 2] + arr[i - 3];
    cin >> t;
    for(int i = 0; i < t; i++) {
        cin >> n;
        cout << arr[n - 1] << "\n";
    }
    return 0;
}
//
// Created by 규북 on 2023/08/14.
//