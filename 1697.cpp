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
    int visit[100002] = {};
    visit[n] = true;
    //visit[k] = true;
    q.push(n);
    int last = 1, cnt = 0;
    if(n == k) {
        cout << 0;
        return 0;
    }
    while(!q.empty()) {
        int cur = q.front();
        q.pop();
        last--;
        int nx;
        nx = cur + 1;
        if(!(nx > 100000 || visit[nx])) {
            q.push(nx);
            visit[nx] = true;
            if(nx == k) break;
        }
        nx = cur - 1;
        if(!(nx < 0 || visit[nx])) {
            q.push(nx);
            visit[nx] = true;
            if(nx == k) break;
        }
        nx = cur * 2;
        if(!(nx > 100000 || visit[nx])) {
            q.push(nx);
            visit[nx] = true;
            if(nx == k) break;
        }
        if(last == 0) {
            cnt++;
            last = q.size();
        }
    }
    if(!q.empty())
        cout << cnt + 1;
    return 0;
}
//
// Created by 규북 on 2023/08/10.
//
