#include <iostream>
#include <numeric>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    long long a, b;
    cin >> a >> b;

    long long g = gcd(a, b);
    long long l = (a / g) * b;

    cout << g << "\n" << l;

    return 0;
}
//
// Created by 규북 on 5/24/24.
//
