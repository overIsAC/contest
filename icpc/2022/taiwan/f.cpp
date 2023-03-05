#include <bits/stdc++.h>
using namespace std;
using LL = long long;
using PII = pair<int, int>;

const int mod = 7 + 1e9;
const int N = 1e6;

int n, a[N];
int cnt[N];
set<int> st;
int stk[N], top;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T;
    cin >> T;
    while (T--) {
        cin >> n;
        for (int i = 1; i <= 2 * n - 1; ++i) {
            cin >> a[i];
        }
        
        if (n == 1) {
            cout << 1 << endl;
            continue;
        }

        st.clear();

        for (int i = 1; i <= n; ++i) {
            st.insert(i);
            cnt[i] = 0;
        }

        if (!a[1]) {
            a[1] = 1;
        }
        if (!a[n * 2 - 1]) {
            a[n * 2 - 1] = 1;
        }

        for (int i = 1; i <= 2 * n - 1; ++i) {
            if (a[i]) {
                ++cnt[a[i]];
                if (st.count(a[i])) {
                    st.erase(a[i]);
                }
            }
        }

        top = 1;
        stk[top] = 1;
        --cnt[1];

        for (int i = 2; i <= 2 * n - 1; ++i) {
            if (a[i]) {
                if (cnt[stk[top]]) {
                    --top;
                } else {
                    stk[++top] = a[i];
                }
                --cnt[a[i]];
            } else {
                if (top) {
                    if (cnt[stk[top]] && st.size()) {
                        stk[++top] = *st.begin();
                        a[i] = stk[top];
                        st.erase(st.begin());
                    } else {
                        a[i] = stk[--top];
                    }
                }
            }
        }
        for (int i = 1; i <= 2 * n - 1; ++i) {
            cout << a[i] << ' ';
        }
        cout << endl;
    }
    return 0;
}

/*

312
2
0 2 0
*/