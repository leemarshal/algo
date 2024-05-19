#include <iostream>
#include <vector>
#define INF 1000
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N, temp;
    cin >> N;
    vector<vector<int>> adj(N, vector<int>(N));
    vector<vector<int>> dist(N, vector<int>(N, INF));
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            cin >> temp;
            adj[i][j] = temp;
            if(temp == 1) dist[i][j] = temp;
        }
    }

    for(int m = 0; m < N; m++) {
        for(int s = 0; s < N; s++) {
            for(int e = 0; e < N; e++) {
                if(dist[s][e] > dist[s][m] + dist[m][e]) {
                    dist[s][e] = dist[s][m] + dist[m][e];
                }
            }
        }
    }

    for(auto& dst : dist) {
        for(auto d : dst) {
            if(d == INF) cout << "0 ";
            else cout << "1 ";
        }
        cout << "\n";
    }

    return 0;
}
//
// Created by 규북 on 5/20/24.
//
