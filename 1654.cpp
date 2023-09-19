#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool dsum(const vector<int>& v, int n, int t) {
    int sum = 0;
    for(int i = 0; i < v.size(); i++) {
        sum += v[i] / t;
    }
    if(n <= sum) return true;// 개수 같음 || 개수 과충족
    if(n > sum) return false;// 개수 부족함
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int K, N;
    cin >> K >> N;
    vector<int> v(K);
    for(int i = 0; i < K; i++) cin >> v[i];
    sort(v.begin(), v.end());
    long long l = 1;
    long long r = v[K - 1];
    long long mid;
    bool dresult;
    mid = r / 2;
    int prev;
    bool flag = true;
    while(l <= r) {
        mid = (l + r) / 2;
        dresult = dsum(v, N, mid);
        if(dresult) {//같아도 부족해지기 전까지는 크게 만들어봐야함 -> l = mid + 1;
            l = mid + 1;
            prev = mid;
            flag = true;
        }
        else {
            r = mid - 1;
            flag = false;
        }
    }
    if(flag) cout << mid;
    else cout << prev;
    return 0;
}
//
// Created by 규북 on 2023/09/19.
//
