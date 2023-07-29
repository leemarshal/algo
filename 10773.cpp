#include <iostream>

using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, temp, top=-1;
    int arr[100000];
    cin >> n;
    while(n > 0) {
        cin >> temp;
        if(temp)
            arr[++top] = temp;
        else
            --top;
        --n;
    }
    temp = 0;
    while(top > -1) {
        temp += arr[top--];
    }
    cout << temp;
    return 0;
}
//
// Created by 규북 on 2023/07/29.
//
