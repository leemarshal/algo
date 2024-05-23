#include <iostream>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    /*
     * ABC = 2
     * DEF = 3
     * GHI = 4
     * JKL = 5
     * MNO = 6
     * PQRS = 7
     * TUV = 8
     * WXYZ = 9
     */
    int dial[26] = {2, 2, 2, 3, 3, 3, 4, 4, 4, 5, 5, 5, 6, 6, 6, 7, 7, 7, 7, 8, 8, 8, 9, 9, 9, 9};
    string str;
    cin >> str;
    int result = str.length();
    for(auto c : str) {
        result += dial[c - 'A'];
    }
    cout << result;
    return 0;
}
//
// Created by 규북 on 5/23/24.
//
