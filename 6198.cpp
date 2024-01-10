#include <iostream>
#include <vector>
#include <utility>
#include <stack>

using namespace std;

int main()
{
    int n, tempHeight;
    cin >> n;
    vector<pair<int, int>> building(n, {0, 0});// height, value

    for(int i = 0; i < n; i++) {
        cin >> tempHeight;
        building[i] = {tempHeight, 0};
    }

    stack<pair<int, int>> stk;
    unsigned int result = 0;
    for(int i = n - 1; i >= 0; i--) {
        if(stk.empty()) stk.push(building[i]);
        else {
            while(building[i].first > stk.top().first) {
                result += stk.top().second;
                building[i].second += stk.top().second + 1;
                stk.pop();
                if(stk.empty()) break;
            }
            stk.push(building[i]);
        }
    }
    while(!stk.empty()) {
        result += stk.top().second;
        stk.pop();
    }

    cout << result;
}
//
// Created by 규북 on 1/11/24.
//
