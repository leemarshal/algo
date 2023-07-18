#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

struct X {
    int value;
    int cnt;
    int originIndex;
};

bool compareByValue(const X& a, const X& b) {
    return a.value < b.value;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;
    vector<X> x(N);
    vector<int> compress(N);
    for(int i=0; i<N; i++) {
        cin >> x[i].value;
        x[i].originIndex = i;
    }
    sort(x.begin(), x.end(), compareByValue);
    x[0].cnt = 0;
    compress[x[0].originIndex] = 0;
    for(int i=1; i<N; i++) {
        if(x[i].value == x[i-1].value)
            x[i].cnt = x[i-1].cnt;
        else
            x[i].cnt = x[i-1].cnt + 1;

        compress[x[i].originIndex] = x[i].cnt;
    }

    cout << compress[0];
    for(int i=1; i<N; i++) {
        cout << " " << compress[i];
    }

    return 0;
}
//
// Created by 규북 on 2023/07/18.
//
