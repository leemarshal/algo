#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct AgeIndexName {
    int age;
    int index;
    string name;
};

bool compare(const AgeIndexName& a, const AgeIndexName& b) {
    if(a.age == b.age) {
        return a.index < b.index;
    }
    return a.age < b.age;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N;
    cin >> N;
    vector<AgeIndexName> v;
    int age;
    string name;
    struct AgeIndexName ain;
    for(int n = 0; n < N; n++) {
        cin >> age >> name;
        ain.age = age;
        ain.index = n;
        ain.name = name;
        v.push_back(ain);
    }
    sort(v.begin(), v.end(), compare);

    for(auto& ain : v) {
        cout << ain.age << " " << ain.name << "\n";
    }
    return 0;
}
//
// Created by 규북 on 5/24/24.
//
