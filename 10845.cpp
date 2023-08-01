#include <iostream>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, f = -1, e = -1, t;
    string s;
    cin >> n;
    int* arr = new int[n];
    for(int i = 0; i < n; i++) {
        cin >> s;
        if(s == "push") {
            cin >> t;
            if(f == -1) {
                f = 0;
            }
            arr[++e] = t;
        }
        else if(s == "pop") {
            if(f == -1) cout << "-1\n";
            else {
                cout << arr[f++] << "\n";
                if(f - 1 == e) {
                    f = -1;
                    e = -1;
                }
            }
        }
        else if(s == "size") {
            if(f == -1) cout << "0\n";
            else cout << e - f + 1 << "\n";
        }
        else if(s == "empty") {
            cout << (e == -1) << "\n";
        }
        else if(s == "front") {
            if(f != -1) {
                cout << arr[f] << "\n";
            }
            else cout << "-1\n";
        }
        else if(s == "back") {
            if(e != -1) {
                cout << arr[e] << "\n";
            }
            else cout << "-1\n";
        }
    }
    return 0;
}
/*
 * push X: 정수 X를 큐에 넣는 연산이다.
 * pop: 큐에서 가장 앞에 있는 정수를 빼고, 그 수를 출력한다. 만약 큐에 들어있는 정수가 없는 경우에는 -1을 출력한다.
 * size: 큐에 들어있는 정수의 개수를 출력한다.
 * empty: 큐가 비어있으면 1, 아니면 0을 출력한다.
 * front: 큐의 가장 앞에 있는 정수를 출력한다. 만약 큐에 들어있는 정수가 없는 경우에는 -1을 출력한다.
 * back: 큐의 가장 뒤에 있는 정수를 출력한다. 만약 큐에 들어있는 정수가 없는 경우에는 -1을 출력한다.
 */
//
// Created by 규북 on 2023/08/01.
//
