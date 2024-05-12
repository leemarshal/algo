#include <iostream>
#include <utility>
#include <algorithm>
#include <vector>
#define S first
#define E second

using namespace std;

bool compare(pair<int, int> a, pair<int, int> b) {
    if(a.E == b.E) return a.S < b.S;
    return a.E < b.E;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N;
    cin >> N;
    vector<pair<int, int>> meetings(N);
    int start, end;
    for(int i = 0; i < N; i++) {
        cin >> start >> end;
        meetings[i] = {start, end};
    }
    sort(meetings.begin(), meetings.end(), compare);

    int cnt = 0, last = -1;
    for(auto& m : meetings) {
        if(m.S < last) continue;
        cnt++;
        last = m.E;
    }
    cout << cnt;
    return 0;
}