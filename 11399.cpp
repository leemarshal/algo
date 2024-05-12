#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N;
    cin >> N;
    vector<int> v(N);
    for(auto& elem : v) {
        cin >> elem;
    }
    sort(v.begin(), v.end());

    int result = 0;
    for(int i = 0; i < v.size(); i++) {
        result += v[i] * (v.size() - i);
    }

    cout << result;
    return 0;
}

//
// Created by 규북 on 5/12/24.
//
