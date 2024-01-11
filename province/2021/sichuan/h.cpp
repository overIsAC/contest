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
const int N = 3 + 2e5;

map<string, string> mp;

void solve() {
    string s;
    cin >> s;

    auto endWith = [&](string t) -> int {
        if (s.size() < t.size()) {
            return 0;
        }
        return s.substr(s.size() - t.size()) == t;
    };

    auto f = [&](string t) {
        return s.substr(0, s.size() - t.size());
    };

    if (endWith("chimasu")) {
        cout << f("chimasu") << "tte" << endl;
    } else if (endWith("rimasu")) {
        cout << f("rimasu") << "tte" << endl;
    } else if (endWith("mimasu")) {
        cout << f("mimasu") << "nde" << endl;
    } else if (endWith("bimasu")) {
        cout << f("bimasu") << "nde" << endl;
    } else if (endWith("nimasu")) {
        cout << f("nimasu") << "nde" << endl;
    } else if (endWith("kimasu")) {
        if (s == "ikimasu") {
            cout << "itte" << endl;
        } else {
            cout << f("kimasu") << "ite" << endl;
        }
    } else if (endWith("gimasu")) {
        cout << f("gimasu") << "ide" << endl;

    } else if (endWith("shimasu")) {
        cout << f("shimasu") << "shite" << endl;
    } else if (endWith("imasu")) {
        cout << f("imasu") << "tte" << endl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}