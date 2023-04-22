#include <bits/stdc++.h>
using namespace std;
using LL = long long;
using PII = pair<int, int>;

#define lson (k << 1)
#define rson (k << 1 | 1)
#if LEMON
#define db(x) cout << "function " << __FUNCTION__ << ", line " << __LINE__ << " : " << #x << " " << x << endl;
#else
#define db(x)
#endif

const int mod = 7 + 1e9;
// const int mod = 998244353;
const int N = 3 + 1e5;

string s[22];

vector<string> ve = {
    "dong", "xi", "nan", "bei", "fa", "zhong", "bai",
    "1s", "9s", "1p", "9p", "1w", "9w"};

int main() {
    while (cin >> s[0]) {
        for (int i = 1; i < 14; ++i) {
            cin >> s[i];
        }
        bool same = true;
        for (int i = 1; i < 14; ++i) {
            if (s[i][1] != s[i - 1][1]) {
                same = false;
            }
        }
        if (same) {
            map<char, int> mp;
            for (int i = 0; i < 14; ++i) {
                ++mp[s[i][0]];
            }
            if (mp.size() == 9 && mp['1'] >= 3 && mp['9'] >= 3) {
                cout << "jiulianbaodeng!" << endl;
            } else {
                cout << "I dont know!" << endl;
            }
        } else {
            map<string, int> mp;
            for (int i = 0; i < 14; ++i) {
                ++mp[s[i]];
            }
            bool ok = true;
            for (auto &i : ve) {
                if (!mp[i]) {
                    ok = false;
                    break;
                }
            }
            if (ok) {
                cout << "shisanyao!" << endl;
            } else {
                cout << "I dont know!" << endl;
            }
        }
    }
    return 0;
}