#include <iostream>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    int* arr = new int[2 * n + 1];
    int head = n, tail = n;
    string s;
    int temp;
    for(int i = 0; i < n; i++) {
        cin >> s;
        if(s == "push_front") {
            cin >> temp;
            arr[--head] = temp;
        }
        else if(s == "push_back") {
            cin >> temp;
            arr[tail++] = temp;
        }
        else if(s == "pop_front") {
            if(head == tail) cout << "-1\n";
            else {
                cout << arr[head++] << "\n";
                if(head == tail) {
                    head = n;
                    tail = n;
                }
            }
        }
        else if(s == "pop_back") {
            if(head == tail) cout << "-1\n";
            else {
                cout << arr[--tail] << "\n";
                if(head == tail) {
                    head = n;
                    tail = n;
                }
            }
        }
        else if(s == "size") {
            if(head == tail) cout << "0\n";
            else cout << tail - head << "\n";
        }
        else if(s == "empty") {
            if(head == tail) cout << "1\n";
            else cout << "0\n";
        }
        else if(s == "front") {
            if(head == tail) cout << "-1\n";
            else cout << arr[head] << "\n";
        }
        else if(s == "back") {
            if(head == tail) cout << "-1\n";
            else cout << arr[tail - 1] << "\n";
        }
    }
    return 0;
}
/*
 * push_front X: 정수 X를 덱의 앞에 넣는다.
 * push_back X: 정수 X를 덱의 뒤에 넣는다.
 * pop_front: 덱의 가장 앞에 있는 수를 빼고, 그 수를 출력한다. 만약, 덱에 들어있는 정수가 없는 경우에는 -1을 출력한다.
 * pop_back: 덱의 가장 뒤에 있는 수를 빼고, 그 수를 출력한다. 만약, 덱에 들어있는 정수가 없는 경우에는 -1을 출력한다.
 * size: 덱에 들어있는 정수의 개수를 출력한다.
 * empty: 덱이 비어있으면 1을, 아니면 0을 출력한다.
 * front: 덱의 가장 앞에 있는 정수를 출력한다. 만약 덱에 들어있는 정수가 없는 경우에는 -1을 출력한다.
 * back: 덱의 가장 뒤에 있는 정수를 출력한다. 만약 덱에 들어있는 정수가 없는 경우에는 -1을 출력한다.
 */
//
// Created by 규북 on 2023/08/03.
//
