#include <iostream>
#include <queue>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, k;
    cin >> n >> k;
    queue<int> q;
    for(int i = 1; i <= n; i++) q.push(i);
    int temp;
    cout << "<";
    while(q.size() > 1) {
        for(int i = 0; i < k - 1; i++) {
            temp = q.front();
            q.pop();
            q.push(temp);
        }
        cout << q.front() << ", ";
        q.pop();
    }
    cout << q.front() << ">";
    return 0;
}
//
// Created by 규북 on 2023/09/15.
//
