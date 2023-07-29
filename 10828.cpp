#include <iostream>

using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, v, top = -1, temp;
    cin >> n;
    int arr[10000];
    string s;
    while(n > 0) {
        cin >> s;
        if(s.compare("push") == 0) {
            cin >> temp;
            top++;
            arr[top] = temp;
        }
        else if(s.compare("pop") == 0) {
            if(top > -1) {
                cout << arr[top] << "\n";
                top--;
            }
            else
                cout << "-1\n";
        }
        else if(s.compare("size") == 0) {
            cout << (top + 1) << "\n";
        }
        else if(s.compare("empty") == 0) {
            if(top == -1)
                cout << "1\n";
            else
                cout << "0\n";
        }
        else if(s.compare("top") == 0) {
            if(top > -1)
                cout << arr[top] << "\n";
            else
                cout << "-1\n";
        }
        --n;
    }
    return 0;
}
//
// Created by 규북 on 2023/07/29.
//