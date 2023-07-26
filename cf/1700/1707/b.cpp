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
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T;
    cin >> T;
    while (T--) {
        set<int> st;
        int n;
        cin >> n;
        int zero = 0, same = 0;
        while (n--) {
            int a;
            cin >> a;
            if (a == 0) {
                ++zero;
            } else if (st.count(a)) {
                ++same;
            } else {
                st.insert(a);
            }
        }
        // cout << same << ' ' << zero << endl;
        // for (auto &i : st) {
        //     cout << i << ' ';
        // }
        // cout << endl;
        while (st.size() > 1 || same) {
            set<int> s;
            int last = *st.begin();
            if (zero) {
                last = 0;
                --zero;
            }
            zero += same;
            same = 0;
            for (auto &i : st) {
                if (i != last) {
                    if (s.count(i - last)) {
                        ++same;
                    } else {
                        s.insert(i - last);
                    }
                }
                last = i;
            }
            // cout << same << ' ' << zero << endl;
            // for (auto &i : st) {
            //     cout << i << ' ';
            // }
            // cout << endl;
            swap(st, s);
        }
        cout << *st.begin() << endl;
    }
    return 0;
}