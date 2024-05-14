#include <iostream>
#include <vector>
#include <algorithm>

#define INF 1000000
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N, M;
    cin >> N >> M;
    vector<vector<int>> dist(N + 1, vector<int>(N + 1, INF));
    for(int i = 1; i <= N; i++) {
        dist[i][i] = 0;
    }
    int a, b;
    for(int i = 0; i < M; i++) {
        cin >> a >> b;
        dist[a][b] = 1;
        dist[b][a] = 1;
    }
    
    for(int m = 1; m <= N; m++) {
        for(int s = 1; s <= N; s++) {
            for(int e = 1; e <= N; e++) {
                if(dist[s][e] > dist[s][m] + dist[m][e])
                    dist[s][e] = dist[s][m] + dist[m][e];
            }
        }
    }
    vector<pair<int, int>> result(N + 1);
    result[0] = {INF, 0};
    for(int i = 1; i <= N; i++) {
        result[i] = {0, i};
        for(int j = 1; j <= N; j++) {
            if(i == j) continue;
            result[i].first += dist[i][j];
        }
    }
    sort(result.begin(), result.end());

    cout << result[0].second;
    return 0;
}

//
// Created by 규북 on 5/14/24.
//
