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
    int n, k;
    string s;
    cin >> n >> k >> s;
    for (char i = 'a'; i <= 'z' && k; ++i) {
        string ss;
        for (auto& j : s) {
            if (j == i && k) {
                --k;
            } else {
                ss += j;
            }
        }
        s = ss;
    }
    cout << s << endl;
    return 0;
}