#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>

using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N, M;
    cin >> N >> M;
    unordered_map<string, vector<string>> groupToMember;
    unordered_map<string, string> memberToGroup;
    for(int n = 0; n < N; n++) {
        string group;
        int num;
        cin >> group >> num;
        vector<string> v;
        for(int i = 0; i < num; i++) {
            string member;
            cin >> member;
            memberToGroup[member] = group;
            v.push_back(member);
        }
        sort(v.begin(), v.end());
        groupToMember[group] = v;
    }

    for(int m = 0; m < M; m++) {
        string question;
        int questionType;
        cin >> question >> questionType;
        if(questionType == 0)
            for(auto& it : groupToMember[question])
                cout << it << "\n";
        else
            cout << memberToGroup[question] << "\n";
    }

    return 0;
}
//
// Created by 규북 on 1/14/24.
//
