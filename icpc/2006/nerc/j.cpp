#include <bits/stdc++.h>
using namespace std;
using LL = long long;
using PII = pair<int, int>;

#define lson (k << 1)
#define rson (k << 1 | 1)
#if LEMON
#define db(x) cout << "function " << __FUNCTION__ << ", line " << __LINE__ << " : " << #x << " " << x << endl;
#define dbf(func) func();
#else
#define db(x)
#define dbf(func)
#endif

const int dx[] = {1, -1, 0, 0};
const int dy[] = {0, 0, 1, -1};
const int mod = 7 + 1e9;
// const int mod = 998244353;
const int N = 3 + 1e5;

int main() {
    ifstream cin("java_c.in");
    ofstream cout("java_c.out");
    string s;
    cin >> s;
    auto checkCpp = [&]() {
        bool flag = false;
        for (auto &i : s) {
            if (i == '_') {
                if (flag) {
                    return false;
                }
                flag = true;
            } else {
                flag = false;
            }
            if (isupper(i)) {
                return false;
            }
        }
        return s[0] != '_' && s.back() != '_';
    };
    auto checkJava = [&]() {
        for (auto &i : s) {
            if (i == '_') {
                return false;
            }
        }
        return (bool)islower(s[0]);
    };
    if (checkCpp()) {
        string ans;
        ans += s[0];
        bool flag = false;
        for (int i = 1; i < s.size(); ++i) {
            if (s[i] == '_') {
                flag = true;
                continue;
            }
            if (flag) {
                ans += toupper(s[i]);
                flag = false;
            } else {
                ans += s[i];
            }
        }
        cout << ans << endl;
    } else if (checkJava()) {
        string ans;
        for (auto &i : s) {
            if (isupper(i)) {
                ans += "_";
            }
            ans += tolower(i);
        }
        cout << ans << endl;
    } else {
        cout << "Error!" << endl;
    }

    return 0;
}