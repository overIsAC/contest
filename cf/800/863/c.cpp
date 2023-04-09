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

LL k;
int a, b;
int A[33][33], B[33][33];

int main() {
    cin >> k >> a >> b;
    for (int i = 1; i <= 3; ++i) {
        for (int j = 1; j <= 3; ++j) {
            cin >> A[i][j];
        }
    }
    for (int i = 1; i <= 3; ++i) {
        for (int j = 1; j <= 3; ++j) {
            cin >> B[i][j];
        }
    }
    int scoceA = 0, scoceB = 0;
    set<PII> st;
    while (!st.count({a, b})) {
        if (a % 3 == (b + 1) % 3) {
            ++scoceA;
        }
        if ((a + 1) % 3 == b % 3) {
            ++scoceB;
        }
        --k;
        if (!k) {
            cout << scoceA << ' ' << scoceB << endl;
            return 0;
        }
        st.insert({a, b});
        int na = A[a][b], nb = B[a][b];
        a = na;
        b = nb;
    }
    LL ansA = scoceA;
    LL ansB = scoceB;
    scoceA = 0;
    scoceB = 0;
    int aa = a, bb = b;
    st.clear();
    while (!st.count({a, b})) {
        if (a % 3 == (b + 1) % 3) {
            ++scoceA;
        }
        if ((a + 1) % 3 == b % 3) {
            ++scoceB;
        }
        st.insert({a, b});
        int na = A[a][b], nb = B[a][b];
        a = na;
        b = nb;
    }

    ansA += k / st.size() * scoceA;
    ansB += k / st.size() * scoceB;
    k %= st.size();
    a = aa;
    b = bb;
    while (k--) {
        if (a % 3 == (b + 1) % 3) {
            ++ansA;
        }
        if ((a + 1) % 3 == b % 3) {
            ++ansB;
        }
        int na = A[a][b], nb = B[a][b];
        a = na;
        b = nb;
    }
    cout << ansA << ' ' << ansB << endl;
    return 0;
}