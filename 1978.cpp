#include <iostream>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, temp, cnt = 0;
    cin >> N;
    bool prime[1001];

    prime[1] = false;
    for (int i = 2; i < 1001; i++) {
        prime[i] = true;
    }

    for (int i = 2; i < 1001; i++) {
        if(prime[i]) {
            for(int j = 2; i * j < 1001; j++) {
                prime[i * j] = false;
            }
        }
    }


    for (int i = 0; i < N; i++) {
        cin >> temp;
        if(prime[temp])
            cnt++;
    }

    cout << cnt;
}
//
// Created by 규북 on 2023/07/22.
//
