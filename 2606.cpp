#include <iostream>
#include <queue>
using namespace std;
typedef struct Vertex {
    int v;
    queue<int> e;
} vertex;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int V, E;
    int v1, v2;
    vertex arr[101];
    for(int i = 1; i <= V; i++) {
        arr[i - 1].v = i;
    }
    cin >> V >> E;
    for(int i = 0; i < E; i++) {
        cin >> v1 >> v2;
        arr[v1].e.push(v2);
        arr[v2].e.push(v1);
    }
    queue<int> q;
    bool visit[101] = {};
    int cnt = -1;
    q.push(1);
    visit[0] = true;
    while(!q.empty()) {
        int cur = q.front();
        int temp;
        q.pop();
        cnt++;
        while(!arr[cur].e.empty()) {
            temp = arr[cur].e.front();
            arr[cur].e.pop();
            if(visit[temp - 1]) continue;
            q.push(temp);
            visit[temp - 1] = true;
        }
    }
    cout << cnt;
    return 0;
}
//
// Created by 규북 on 2023/08/21.
//
