/*
 *
 * 1  2
 * 3  4
 *
 */


#include <iostream>
#include <vector>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N, r, c, len = 1;
    cin >> N >> r >> c;

    for(int i = 0; i < N; i++) len *= 2;

    int result = 0, x = 0, y = 0;
    for(int i = 1; i < N; i++) {
        bool X = (r - x) % len < len / 2;//row
        bool Y = (c - y) % len < len / 2;//col
        len /= 2;
        if(X == true && Y == true) continue;//1
        else if(X == true && Y == false) {//2
            result += len * len;
            y += len;
        }
        else if(X == false && Y == true) {//3
            result += len * len * 2;
            x += len;
        }
        else {//4
            result += len * len * 3;
            x += len;
            y += len;
        }
    }
    bool X = (r - x) % len < len / 2;
    bool Y = (c - y) % len < len / 2;
    //if(X == true && Y == true) result += 1;
    if(X == true && Y == false) result += 1;//2
    else if(X == false && Y == true) result += 2;//3
    else if(X == false && Y == false) result += 3;//4

    cout << result;
    return 0;
}

//
// Created by 규북 on 5/13/24.
//
