#include <iostream>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    for(int i = n; i > 0; i--) {
        //for(int j = n - i; j > 0; j--) cout << " ";
        for(int j = i; j > 0; j--) {
            cout << "*";
        }
        cout << "\n";
    }
    return 0;
}
//
// Created by 규북 on 2023/08/19.
//
