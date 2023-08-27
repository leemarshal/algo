#include <iostream>
#include <vector>
using namespace std;
void sum(vector<vector<int>>& arr, int n);
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    vector<vector<int>> arr;
    vector<int> tarr;
    for(int i = 0; i < 21; i++) tarr.push_back(-1);
    for(int i = 0; i < 91; i++) arr.push_back(tarr);
    arr[0][0] = 1;
    arr[1][0] = 1;
    arr[2][0] = 1;
    arr[3][0] = 2;
    cin >> n;
    for(int i = 4; i <= n; i++) {
        sum(arr, i);
    }
    int k = 0, cnt = 0;
    while(arr[n][k++] > -1) cnt++;
    for(int i = cnt - 1; i >= 0; i--) {
        cout << arr[n][i];
    }
    return 0;
}

void sum(vector<vector<int>>& arr, int n) {
    int i = 0, carry = 0, temp;
    while(arr[n - 2][i] > -1) {
        temp = arr[n - 1][i] + arr[n - 2][i];
        arr[n][i] = (temp + carry) % 10;
        if(temp + carry > 9) carry = 1;
        else carry = 0;
        i++;
    }
    while(arr[n - 1][i] > -1) {
        temp = arr[n - 1][i] + carry;
        arr[n][i] = temp % 10;
        if(temp > 9) carry = 1;
        else carry = 0;
        i++;
    }
    if(carry == 1) arr[n][i] = 1;
}
//
// Created by 규북 on 2023/08/27.
//
