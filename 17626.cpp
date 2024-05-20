#include <iostream>
#include <vector>
//#include <algorithm>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    vector<int> v(50001, 0);
    vector<int> v1(223);
    vector<int> v2;
    //vector<int> v3;
    int n, temp;
    cin >> n;
    for(int i = 1; i < 224; i++) {
        temp = i * i;
        if(temp > 50000) continue;
        if(temp == n) {
            cout << "1";
            return 0;
        }
        v[temp] = 1;
        v1[i - 1] = temp;
    }
    for(int i = 0; i < 223; i++) {
        for(int j = i; j < 223; j++) {
            temp = v1[i] + v1[j];
            if(temp > 50000) continue;
            if(temp == n) {
                cout << "2";
                return 0;
            }
            v[temp] = 2;
            v2.push_back(temp);
        }
    }
    for(auto elem1 : v1) {
        for(auto elem2 : v2) {
            //temp = elem1 + elem2;
            if(elem1 + elem2 == n) {
                cout << "3";
                return 0;
            }
            //if(temp > 50000) continue;
            //if(v[temp] != 0) continue;
            //v[temp] = 3;
        }
    }
    //sort(v2.begin(), v2.end(), greater<int>());
    //cout << v2[0] << '\n';
    cout << "4";
    return 0;
}
//
// Created by 규북 on 5/20/24.
//
