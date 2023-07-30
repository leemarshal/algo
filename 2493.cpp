#include <iostream>
#include <array>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, temp, top = -1;
    cin >> n;
    int* arr = new int[n];
    int* index = new int[n];
    for(int i = 0; i < n; i++) {
        cin >> temp;
        while((top > -1) && (arr[top] < temp)) {
            top--;
        }
        if(top > -1)
            cout << index[top] << " ";
        else
            cout << "0 ";
        arr[++top] = temp;
        index[top] = i + 1;
    }
    delete[] arr;
    delete[] index;

}
//
// Created by 규북 on 2023/07/30.
//