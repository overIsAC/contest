#include <bits/stdc++.h>
using namespace std;
using LL = long long;
using PII = pair<int, int>;

#define lson (k << 1)
#define rson (k << 1 | 1)
#if LEMON
#define db(x)                                                             \
    cout << "function " << __FUNCTION__ << ", line " << __LINE__ << " : " \
         << #x << " " << x << endl;
#else
#define db(x)
#endif

const int mod = 7 + 1e9;
// const int mod = 998244353;
const int N = 3 + 1e5;

int a[10][10];

int main() {
    for (int i = 0; i < 9; ++i) {
        for (int j = 0; j < 9; ++j) {
            cin >> a[i][j];
        }
    }

    for (int i = 0; i < 9; ++i) {
        set<int> st;
        for (int j = 0; j < 9; ++j) {
            st.insert(a[i][j]);
        }
        if (st.size() != 9) {
            cout << "No" << endl;
            return 0;
        }
    }

    for (int j = 0; j < 9; ++j) {
        set<int> st;
        for (int i = 0; i < 9; ++i) {
            st.insert(a[i][j]);
        }
        if (st.size() != 9) {
            cout << "No" << endl;
            return 0;
        }
    }

    for (int i = 0; i < 9; i += 3) {
        for (int j = 0; j < 9; j += 3) {
            set<int> st;
            for (int q = 0; q < 3; ++q) {
                for (int w = 0; w < 3; ++w) {
                    st.insert(a[i + q][j + w]);
                }
            }
            if (st.size() != 9) {
                cout << "No" << endl;
                return 0;
            }
        }
    }

    cout << "Yes" << endl;
    return 0;
}