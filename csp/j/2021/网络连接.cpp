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

int valid(string s) {
    vector<int> a;
    for (int i = 0; i < s.size(); ++i) {
        if (!isdigit(s[i])) {
            a.push_back(i);
        }
    }
    if (a.size() != 4) {
        return 0;
    }
    if (s[a[0]] != '.') {
        return 0;
    }
    if (s[a[1]] != '.') {
        return 0;
    }
    if (s[a[2]] != '.') {
        return 0;
    }
    if (s[a[3]] != ':') {
        return 0;
    }
    if (a[0] == 0 || a.back() + 1 == s.size()) {
        return 0;
    }
    for (int i = 0; i + 1 < a.size(); ++i) {
        if (a[i + 1] == a[i] + 1) {
            return 0;
        }
    }
    vector<string> vv;
    vv.push_back(s.substr(0, a[0]));
    for (int i = 0; i + 1 < a.size(); ++i) {
        vv.push_back(s.substr(a[i] + 1, a[i + 1] - a[i] - 1));
    }
    vv.push_back(s.substr(a.back() + 1));
    for (auto &i : vv) {
        if (i[0] == '0' && i.size() > 1) {
            return 0;
        }
    }
    for (int i = 0; i < vv.size(); ++i) {
        if (vv[i].size() > 8) { // 坑
            return 0;
        }
        int v = stoi(vv[i]);
        if (i + 1 == vv.size()) {
            if (!(0 <= v && v <= 65535)) {
                return 0;
            }
        } else {
            if (!(0 <= v && v <= 255)) {
                return 0;
            }
        }
    }
    return 1;
}

int main() {
    int n;
    string a, b;
    cin >> n;
    map<string, int> mp;
    for (int i = 1; i <= n; ++i) {
        cin >> a >> b;
        if (!valid(b)) {
            cout << "ERR" << endl;
            continue;
        }
        if (a == "Server") {
            if (mp.count(b)) {
                cout << "FAIL" << endl;
            } else {
                cout << "OK" << endl;
                mp[b] = i;
            }
        } else {
            if (mp.count(b)) {
                cout << mp[b] << endl;
            } else {
                cout << "FAIL" << endl;
            }
        }
    }
    return 0;
}