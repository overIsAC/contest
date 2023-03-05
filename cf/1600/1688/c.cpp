#include <bits/stdc++.h>
using namespace std;
using LL = long long;
using PII = pair<int, int>;

#define lson (k << 1)
#define rson (k << 1 | 1)

const int mod = 7 + 1e9;
// const int mod = 998244353;
const int N = 3 + 1e5;

int n;
string s;

int main() {
    int T;
    cin >> T;
    while (T--) {
        cin >> n;
        int cnt[133]={0};
        for (int i = 1; i <= 2 * n + 1; ++i) {
            cin >> s;
            for (auto &j : s) {
                ++cnt[j];
            }
        }
        for (char i = 'a'; i <= 'z' ; ++i) {
            if (cnt[i] & 1) {
                cout << i << endl;
            } 
        }
    }
    return 0;
}