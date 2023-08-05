#include <iostream>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++) {
        for(int j = 0; j < n - i; j++)
            cout << " ";
        for(int k = 0; k < i; k++)
            cout << "*";
        cout << "\n";
    }
    return 0;
}
//
// Created by 규북 on 2023/08/06.
//
