#include <iostream>
#include <queue>
#include <vector>

using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    priority_queue<int, vector<int>, greater<int>> pq;
    int N, temp;
    cin >> N;
    for(int i = 0; i < N; i++) {
        cin >> temp;
        if(temp != 0) {
            pq.push(temp);
            continue;
        }
        if(pq.empty()) cout << "0\n";
        else {
            cout << pq.top() << "\n";
            pq.pop();
        }
    }

    return 0;
}
//
// Created by 규북 on 5/13/24.
//
