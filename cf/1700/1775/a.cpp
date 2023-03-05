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

int main() {
    int T;
    cin >> T;
    while (T--) {
        string s;
        cin >> s;
        bool ok = false;
        for (int i = 1; i + 1 < s.size(); ++i) {
            if (s[i] == 'a') {
                ok = true;
                for (int j = 0; j < i; ++j) {
                    cout << s[j];
                }
                cout << " a ";
                for (int j = i + 1; j < s.size(); ++j) {
                    cout << s[j];
                }
                cout << endl;
                break;
            }
        }
        if (!ok) {
            for (int i = 1; i < s.size(); ++i) {
                if (s[i] == 'b') {
                    ok = true;
                    for (int j = 0; j < i; ++j) {
                        cout << s[j];
                    }
                    cout << ' ';
                    for (int j = i; j + 1 < s.size(); ++j) {
                        cout << s[j];
                    }
                    cout << ' ' << s.back() << endl;
                    break;
                }
            }
        }
        if (!ok) {
            cout << ":(" << endl;
        }
    }
    return 0;
}