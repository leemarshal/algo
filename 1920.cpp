#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
bool binSearch(const vector<int>& v, int t) {
    int left = 0;
    int right = v.size() - 1;
    while(left <= right) {
        int mid = (left + right) / 2;
        if(v[mid] == t) return true;
        else if(v[mid] > t) right = mid - 1;
        else left = mid + 1;
    }
    return false;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    vector<int> v;
    int n;
    cin >> n;
    int temp;
    for(int i = 0; i < n; i++) {
        cin >> temp;
        v.push_back(temp);
    }
    sort(v.begin(), v.end());
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> temp;
        if(binSearch(v, temp)) cout << "1\n";
        else cout << "0\n";
    }
    return 0;
}