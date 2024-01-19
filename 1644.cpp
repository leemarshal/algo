#include <iostream>
#include <vector>

using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    //400만 제곱근은 2000까지 에라토스테네스 체
    int number = 4000000;
    bool arr[4000001];
    for(int i = 2; i <= number; i++) {
        arr[i] = true;
    }
    arr[0] = false;
    arr[1] = false;
    for(int i = 2; i <= 2000; i++) {
        if(!arr[i]) continue;
        for(int j = 2 * i; j <= number; j += i) {
            arr[j] = false;
        }
    }
    int prime[283147];
    int index = 0;
    for(int i = 2; i <= number; i++) {
        if(arr[i]) prime[index++] = i;
    }
    int n;
    cin >> n;
    int sum = prime[0], ans = 0;
    bool flag = false;
    for(int l = 0, r = 1; prime[l] <= n; l++) {
        if(flag) break;
        while(true) {
            if(sum == n) {
                ans++;
                sum = prime[l + 1];
                r = l + 2;
                break;
            }
            else if(sum < n) {//sum이 작다면
                if(r < 283146) {//더할 소수가 남았다면
                    sum += prime[r];
                    r++;
                }
                else {//더할 소수가 없다면
                    flag = true;
                    break;
                }
            }
            else {//sum이 더 크다면
                sum -= prime[l];
                break;
            }
        }
    }
    cout << ans;
    return 0;

}
//
// Created by 규북 on 1/19/24.
//
