#include <iostream>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int max[301];
    int jumpmax[301];
    int step[301];
    bool flag[301] = {};
    int size;
    cin >> size;
    for(int i = 0; i < size; i++)
        cin >> step[i];
    if(size == 1) {
        cout << step[0];
        return 0;
    }
    if(size == 2) {
        cout << step[0] + step[1];
        return 0;
    }
    max[0] = step[0];
    max[1] = step[0] + step[1];
    jumpmax[1] = step[1];
    flag[1] = true;
    int temp;
    for(int i = 2; i < size; i++) {
        if(flag[i - 1]) temp = jumpmax[i - 1];
        else temp = max[i - 1];
        if(temp > max[i - 2]) {
            flag[i] = true;
            max[i] = temp + step[i];
        }
        else max[i] = max[i - 2] + step[i];
        jumpmax[i] = max[i - 2] + step[i];
    }
    cout << max[size - 1];
    return 0;
}
//
// Created by 규북 on 2023/08/14.
//