#include <iostream>
#include <vector>

using namespace std;

vector<char> lc;
vector<char> rc;

void preorder(char cur) {
    cout << cur;
    if(lc[cur - 'A'] != '.') preorder(lc[cur - 'A']);
    if(rc[cur - 'A'] != '.') preorder(rc[cur - 'A']);
}

void inorder(char cur) {
    if(lc[cur - 'A'] != '.') inorder(lc[cur - 'A']);
    cout << cur;
    if(rc[cur - 'A'] != '.') inorder(rc[cur - 'A']);
}

void postorder(char cur) {
    if(lc[cur - 'A'] != '.') postorder(lc[cur - 'A']);
    if(rc[cur - 'A'] != '.') postorder(rc[cur - 'A']);
    cout << cur;
}

int main()
{
    int n;
    cin >> n;
    lc.resize(n, 0);
    rc.resize(n, 0);
    for(int i = 0; i < n; i++) {
        char c, l, r;
        cin >> c >> l >> r;
        lc[c - 65] = l;
        rc[c - 65] = r;
    }
    preorder('A');
    cout << "\n";
    inorder('A');
    cout << "\n";
    postorder('A');
    cout << "\n";
    //'A' = 65
    //'.' = 46
    return 0;
}
//
// Created by 규북 on 1/22/24.
//
