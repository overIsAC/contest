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
        vector<int> a;
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == 'B') {
                continue;
            }
            int j = i;
            while (j + 1 < s.size() && s[j + 1] == 'A') {
                ++j;
            }
            a.push_back(j - i + 1);
            i = j;
        }
        int sum = accumulate(a.begin(), a.end(), 0);
        int z = 0;
        if (!(s[0] == 'A' && s.back() == 'A')) {
            z = 1;
        }
        for (int i = 1; i < s.size(); ++i) {
            if (s[i] == 'B' && s[i - 1] == 'B') {
                z = 1;
            }
        }
        if (!z) {
            sum -= *min_element(a.begin(), a.end());
        }
        cout << sum << endl;
    }
    return 0;
}