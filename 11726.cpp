#include <iostream>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    int arr[1000];
    arr[0] = 1;
    arr[1] = 2;
    for(int i = 2; i < n; i++) {
        arr[i] = arr[i - 1] + arr[i - 2];
        if(arr[i] > 10006) arr[i] %= 10007;
    }
    cout << arr[n - 1];
    return 0;

}
//
// Created by 규북 on 2023/08/16.
//
