#include <iostream>
#include <queue>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, temp;
    cin >> n;
    queue<int> q;
    for(int i = 1; i <= n; i++) {
        q.push(i);
    }
    while(q.size() != 1) {
        q.pop();
        temp = q.front();
        q.pop();
        q.push(temp);
    }
    cout << q.front();
    return 0;
}
//
// Created by 규북 on 2023/08/02.
//
