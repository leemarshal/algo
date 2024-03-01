#include <iostream>
using namespace std;
unsigned int a, b, c;
long long sol(int n) {
    if(n == 1) return a % c;

    long long ret = sol(n / 2);
    ret = (ret * ret) % c;
    if(n % 2 == 1) ret = (ret * (a % c)) % c;

    return ret;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> a >> b >> c;

    cout << sol(b);
}
//
// Created by 규북 on 3/1/24.
//
