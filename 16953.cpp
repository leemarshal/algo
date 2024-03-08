#include <iostream>
#include <queue>

using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int a, b;
    cin >> a >> b;
    queue<int> q;
    q.push(a);
    int cnt = 1, layer = 1; // 필요한 연산인데 왜 등장한 수를 정답으로 하지?
    bool flag = false;
    while(!q.empty()) {
        long long cur = q.front(), nxt;
        q.pop();
        cnt--;

        nxt = cur * 2;
        if(nxt == b) flag = true;
        if(nxt < b) q.push(nxt);

        nxt = cur * 10 + 1;
        if(nxt == b) flag = true;
        if(nxt < b) q.push(nxt);

        if(flag) { //cnt 값 관계 없이 아래 작업 수행
            layer++;
            break;
        }
        else if(cnt == 0) {
            layer++;
            cnt = q.size();
        }
    }
    if(flag) cout << layer;
    else cout << -1;
    return 0;
}
//
// Created by 규북 on 3/9/24.
//
