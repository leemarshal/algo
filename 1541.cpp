#include <iostream>
#include <regex>

using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    string expr;
    cin >> expr;
    regex pattern(R"([-+]?\d+)");

    auto words_begin = sregex_iterator(expr.begin(), expr.end(), pattern);
    auto words_end = sregex_iterator();

    int result = 0, temp;
    bool isMinusOn = false;
    for(sregex_iterator it = words_begin; it != words_end; it++) {
        smatch match = *it;
        temp = stoi(match.str());
        if(temp < 0) {
            isMinusOn = true;
            result += temp;
            continue;
        }
        if(isMinusOn) result -= temp;
        else result += temp;
    }
    cout << result;
    return 0;
}

//
// Created by 규북 on 5/24/24.
//
