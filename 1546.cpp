#include <iostream>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, temp, sum=0, max=0;
    cin >> n;

    for(int i=0; i<n; i++) {
        cin >> temp;
        sum += temp;
        if(temp > max)
            max = temp;
    }
    cout << (100 * static_cast<float>(sum) / max) / n;

}
//
// Created by 규북 on 2023/07/25.
//
