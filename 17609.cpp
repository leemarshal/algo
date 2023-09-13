#include <iostream>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    for(int i = 0; i < t; i++) {
        string s;
        int left, right;
        cin >> s;
        left = 0;
        right = s.length() - 1;
        bool life = true;
        bool answer = true;
        int ltemp, rtemp;
        while(left < right) {
            if(s[left] == s[right]) {
                left++;
                right--;
                continue;
            }
            else if(life) {
                ltemp = left;
                rtemp = right;
                left++;
                life = false;
            }
            else {
                answer = false;
                break;
            }
        }
        bool flag = false;
        if(answer && life) cout << "0\n";
        else if(answer && !life) cout << "1\n";
        else if(!life) {
            rtemp--;
            while(ltemp < rtemp) {
                if(s[ltemp] == s[rtemp]) {
                    ltemp++;
                    rtemp--;
                    continue;
                }
                else {
                    flag = true;
                    break;
                }
            }
            if(!flag) cout << "1\n";
            else cout << "2\n";
        }
        else cout << "2\n";
    }
    return 0;
}
//
// Created by 규북 on 2023/09/13.
//
