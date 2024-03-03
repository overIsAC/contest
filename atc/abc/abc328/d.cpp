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
const int N = 3 + 3e5;

char stk[N];
int top;

void remove() {
    while (top >= 3 && stk[top] == 'C' && stk[top - 1] == 'B' &&
           stk[top - 2] == 'A') {
        top -= 3;
    }
}

int main() {
    char c;
    while (cin >> c) {
        stk[++top] = c;
        remove();
    }
    remove();
    stk[top + 1] = 0;

    cout << stk + 1;

    return 0;
}