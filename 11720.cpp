#include <iostream>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, sum=0;
    string str;
    cin >> n;
    cin >> str;
    for(int i=0; i<n; i++) {
        sum += str[i] - 48;
    }
    cout << sum;
}

//
// Created by 규북 on 2023/07/17.
//
