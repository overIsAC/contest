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

int main() {
    set<int> st;
    int n;
    cin >> n;
    while (n--) {
        int op, x;
        cin >> op >> x;
        if (op == 1) {
            if (st.count(x)) {
                cout << "Already Exist" << endl;
            } else {
                st.insert(x);
            }
        } else {
            if (st.empty()) {
                cout << "Empty" << endl;
            } else {
                auto p = st.lower_bound(x);
                auto p1 = p;
                auto p2 = p;

                if (p == st.end()) {
                    --p;
                    cout << *p << endl;
                    st.erase(p);
                    continue;
                }
                if (p == st.begin()) {
                    cout << *p << endl;
                    st.erase(p);
                    continue;
                }

                --p1;

                if (abs(*p1 - x) <= abs(*p2 - x)) {
                    cout << *p1 << endl;
                    st.erase(p1);
                }else {
                    cout << *p2 << endl;
                    st.erase(p2);
                }

            }
        }
    }
    return 0;
}