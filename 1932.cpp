#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>> v;
vector<int> M;
vector<vector<int>> visited; // -1: pruned, 0: !visit, 1: visited
vector<vector<int>> h;
int result, n;

void sol(pair<int, int> cur) {
    int i = cur.first, j = cur.second;
    if(i == n - 1) {
        h[i][j] = v[i][j];
        visited[i][j] = 1;
        return;
    }

    if(visited[i + 1][j] == 0)
        sol({i + 1, j});
    if(visited[i + 1][j + 1] == 0)
        sol({i + 1, j + 1});

    if(h[i + 1][j] == -1 && h[i + 1][j + 1] == -1) {
        visited[i][j] = -1;
        h[i][j] = -1;
    }
    else {
        h[i][j] = v[i][j] + (h[i + 1][j] > h[i + 1][j + 1] ? h[i + 1][j] : h[i + 1][j + 1]);
        visited[i][j] = 1;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;

    v.resize(n);
    M.resize(n, 0);
    visited.resize(n);
    result = -1;

    for(int i = 0; i < n; i++) {
        visited[i].resize(i + 1, 0);
        for(int j = 0; j <= i; j++) {
            int temp;
            cin >> temp;
            v[i].push_back(temp);
            if(temp > M[i]) M[i] = temp;
        }
    }
    for(int i = n - 2; i >= 0; i--)
        M[i] += M[i + 1];

    h.resize(n);
    for(int i = 0; i < n; i++) {
        //h[n].resize(i + 1, M[i]);
        h[i].resize(i + 1, 0);
    }

    sol({0, 0});
    cout << h[0][0];

    return 0;
}
//
// Created by 규북 on 2023/08/19.
//
