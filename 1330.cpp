#include <iostream>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int a, b;
    cin >> a >> b;
    if(a < b) cout << "<";
    else if(a > b) cout << ">";
    else cout << "==";
    return 0;
}

//
// Created by 규북 on 2023/08/06.
//
