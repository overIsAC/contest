#include <bits/stdc++.h>
using namespace std;
using LL = long long;
using PII = pair<int, int>;

#define lson (k << 1)
#define rson (k << 1 | 1)

const int mod = 7 + 1e9;
// const int mod = 998244353;
const int N = 3 + 2e5;

char s[N];
int pre[N][26];

int main() {
    int T;
    cin >> T;
    while (T--) {
        cin >> s + 1;
        int n = strlen(s + 1);
        set<int> st;
        vector<int> ve[26];
        for (int i = 1; i <= n; ++i) {
            memcpy(pre[i], pre[i - 1], sizeof(pre[i]));
            ++pre[i][s[i] - 'a'];
            st.insert(s[i] - 'a');
            ve[s[i] - 'a'].push_back(i);
        }
        bool ok = true;
        for (int i = 0; i < 26; ++i) {
            for (int j = 1; j < ve[i].size(); ++j) {
                for (auto& k : st) {
                    if (pre[ve[i][j]][k] - pre[ve[i][j - 1]][k] == 0) {
                        ok = false;
                        break;
                    }
                }
                if (!ok) {
                    break;
                }
            }
            if (!ok) {
                break;
            }
        }
        if (ok)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}