#include <iostream>
#include <deque>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m, cnt = 0, temp, tcnt, swaptemp;
    cin >> n >> m;
    deque<int> dq;
    for(int i = 1; i <= n; i++) {
        dq.push_back(i);
    }
    for(int i = 0; i < m; i++) {
        cin >> temp;
        tcnt = 0;
        for(auto it = dq.begin(); it != dq.end(); it++) {
            if(*it == temp) break;
            tcnt++;
        }
        if(tcnt <= (n - i) / 2) {
            for(int j=0; j<tcnt; j++) {
                swaptemp = dq.front();
                dq.pop_front();
                dq.push_back(swaptemp);
            }
            dq.pop_front();
            cnt += tcnt;
        }
        else {
            tcnt = 0;
            for(int j=0; j<(n - i); j++) {
                swaptemp = dq.back();
                dq.pop_back();
                dq.push_front(swaptemp);
                tcnt++;
                if(swaptemp == temp) break;
            }
            dq.pop_front();
            cnt += tcnt;
        }
    }
    cout << cnt;
    return 0;
}
//
// Created by 규북 on 2023/08/03.
//
