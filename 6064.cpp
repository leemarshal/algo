#include <iostream>
#include <numeric>
using namespace std;

bool hasSol(long long m, long long n,long long x,long long y) {
    return (x - y) % gcd(m, n) == 0;
}

long long solve(long long m, long long n, long long x, long long y) {
    if(!hasSol(m, n, x, y)) return -1;

    long long lcm = m / gcd(m, n) * n;
    if(m == x && n == y) return lcm;
    y %= n;
    for(long long k = 0; k < lcm / m; k++) {
        long long ans = k * m + x;
        if(ans % n == y) return ans;
    }
    return -1;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    long long m, n, x, y;
    int T;
    cin >> T;
    for(int t = 0; t < T; t++) {
        cin >> m >> n >> x >> y;
        cout << solve(m, n, x, y) << "\n";
    }

    return 0;
}
//
// Created by 규북 on 5/22/24.
//
