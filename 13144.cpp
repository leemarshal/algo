#include <iostream>
#include <unordered_map>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N;
    cin >> N;
    int* arr = new int[N];

    for(int i = 0; i < N; i++)
        cin >> arr[i];

    int l = 0, r = 0, cnt = 0;
    long long ans = 0;
    unordered_map<int, int> um;
    while(l < N) {
        while(true) {
            if(r < N) {
                if(um.find(arr[r]) == um.end()) {
                    um[arr[r]] = r;
                    r++;
                }
                else {
                    ans += static_cast<long long>(r - l) * (r - l + 1) / 2
                            - static_cast<long long>(r - um[arr[r]] - 1) * (r - um[arr[r]]) / 2;
                    for(int i = l; i < um[arr[r]]; i++) {
                        um.erase(arr[i]);
                    }
                    l = um[arr[r]] + 1;
                    um.erase(arr[r]);
                    break;
                }
            }
            else {
                ans += static_cast<long long>(r - l) * (r - l + 1) / 2;
                l = N;
                break;
            }
        }
    }
    cout << ans;
    delete[] arr;
    return 0;
}
//
// Created by 규북 on 1/20/24.
//
