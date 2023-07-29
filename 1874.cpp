#include <iostream>

using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, temp, i = 0;
    cin >> n;
    int arr[100000];
    int top = -1;
    char answer[200000];
    int len = -1;
    cin >> temp;
    for(i = 0; i < temp; i++) {
        arr[++top] = i + 1;
        answer[++len] = '+';
    }
    top--;
    answer[++len] = '-';
    --n;
    while (n > 0) {
        cin >> temp;
        if(top > -1) {
            if(arr[top] > temp) {
                cout << "NO";
                return 0;
            }
            else if(arr[top] == temp) {
                top--;
                answer[++len] = '-';
            }
            else {
                while(i < temp) {
                    arr[++top] = ++i;
                    answer[++len] = '+';
                }
                top--;
                answer[++len] = '-';
            }
        }
        else {
            while(i < temp) {
                arr[++top] = ++i;
                answer[++len] = '+';
            }
            top--;
            answer[++len] = '-';
        }
        --n;
    }
    for (i = 0; i <= len; i++) {
        cout << answer[i] << "\n";
    }
    return 0;
}
//
// Created by 규북 on 2023/07/29.
//
