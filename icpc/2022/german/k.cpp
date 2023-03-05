#include <bits/stdc++.h>
using namespace std;
using LL = long long;

int n, k;
string s;

int main() {
    cin >> n >> k;
    cin >> s;
    int now = 0;
    for (int i = 0; i < n; ++i) {
        if (s[i] == 'L') {
            if (now) {
                --k;
            } else {
                now = 1;
            }
        } else {
            if (now) {
                now = 0;
            } else {
                --k;
            }
        }
        if (!k) {
            break;
        }
    }
    cout << k << endl;
    return 0;
}