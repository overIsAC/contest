#include <bits/stdc++.h>
using namespace std;
using LL = long long;
using PII = pair<int, int>;

#define lson (k << 1)
#define rson (k << 1 | 1)

const int mod = 7 + 1e9;
// const int mod = 998244353;
const int N = 3 + 1e5;

int main() {
    int T;
    cin >> T;
    while (T--) {
        bool flag = false;
        int b[7];
        for (int i = 0; i < 7; ++i) {
            cin >> b[i];
        }
        for (int i = 0; i < 6 && !flag; ++i) {
            for (int j = i + 1; j < 6 && !flag; ++j) {
                for (int k = j + 1; k < 6 && !flag; ++k) {
                    set<int> s = {b[i],
                                  b[j],
                                  b[k],
                                  b[i] + b[j],
                                  b[i] + b[k],
                                  b[j] + b[k],
                                  b[i] + b[j] + b[k]};
                    set<int> ss;
                    for (auto& i : b) {
                        ss.insert(i);
                    }
                    if (ss == s) {
                        cout << b[i] << ' ' << b[j] << ' ' << b[k] << endl;
                        flag = true;
                    }
                }
            }
        }
    }
    return 0;
}