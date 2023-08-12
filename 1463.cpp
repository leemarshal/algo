//BFS
#include <iostream>
#include <queue>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, last = 1, cnt = 0;
    bool flag = false;
    cin >> n;
    if(n == 1) {
        flag = true;
        cnt = -1;
    }
    bool visit[1000001] = {};
    queue<int> q;
    q.push(n);
    visit[n] = true;
    while(!q.empty()) {
        int cur = q.front();
        q.pop();
        last--;
        int nx;
        if(cur % 3 == 0) {
            nx = cur / 3;
            if(!visit[nx]) {
                q.push(nx);
                visit[nx] = true;
                if(nx == 1) flag = true;
            }
        }
        if(cur % 2 == 0) {
            nx = cur / 2;
            if(!visit[nx]) {
                q.push(nx);
                visit[nx] = true;
                if(nx == 1) flag = true;
            }
        }
        if(cur > 1) {
            nx = cur - 1;
            if(!visit[nx]) {
                q.push(nx);
                visit[nx] = true;
                if(nx == 1) flag = true;
            }
        }
        if(flag) {
            cnt++;
            break;
        }
        if(last == 0) {
            last = q.size();
            cnt++;
        }
    }
    cout << cnt;
}
//
// Created by 규북 on 2023/08/12.
//