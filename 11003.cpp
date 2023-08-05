#include <iostream>
#include <vector>
#include <deque>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    //cout.tie(nullptr);
    int n, l;
    cin >> n >> l;
    vector<int> v(n);
    deque<pair<int, int>> dq;
    for(int i = 0; i < n; i++)
        cin >> v[i];
    for(int i = 0; i < n; i++) {
        if(!dq.empty() && dq.front().second == i - l)
            dq.pop_front();
        while(!dq.empty() && dq.back().first > v[i])
            dq.pop_back();
        dq.push_back(make_pair(v[i], i));
        cout << dq.front().first << " ";
    }
    return 0;
}