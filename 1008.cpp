#include <iostream>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    double a, b;
    cin >> a >> b;
    double result = a / b;
    cout << fixed;
    cout.precision(10);
    cout << result;
    return 0;
}
//
// Created by 규북 on 2023/08/06.
//
