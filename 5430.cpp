#include <iostream>
#include <algorithm>
#include <sstream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    for (int i = 0; i < T; i++) {
        int left, right, len, revFlag, cnt, error;
        string s, arr, token;
        cin >> s;
        cin >> len;
        cin >> arr;
        left = 0;
        right = len - 1;
        revFlag = 0;
        cnt = 0;
        error = 0;
        if(len == 0) {
            if(s.find('D') != string::npos) {
                cout << "error\n";
                continue;
            }
            else {
                cout << "[]\n";
                continue;
            }
        }
        vector<int> x(len);
        arr = arr.substr(1, arr.size() - 2);
        stringstream ss(arr);
        while (getline(ss, token, ',')) {
            x[cnt] = stoi(token);
            cnt++;
        }
        for (int j = 0; j < s.size(); j++) {
            if (s[j] == 'R') {
                revFlag = !revFlag;
            } else if (s[j] == 'D') {
                if (left > right) {
                    error = 1;
                    break;
                }
                if (revFlag) {
                    right--;
                } else {
                    left++;
                }
            }
        }
        if (error) {
            cout << "error" << "\n";
        }
        else if (left > right) {
            cout << "[]\n";
        }
        else {
            vector<int> result(right - left + 1);
            if (revFlag) {
                reverse_copy(x.begin() + left, x.begin() + right + 1, result.begin());
            }
            else {
                copy(x.begin() + left, x.begin() + right + 1, result.begin());
            }
            cout << "[";
            int k;
            for (k = 0; k < result.size() - 1; k++) {
                cout << result[k] << ",";
            }
            cout << result[k] << "]" << "\n";
        }
    }
    return 0;
}
//
// Created by 규북 on 2023/07/20.
//
