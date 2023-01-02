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

int n;
char s[N];

int main() {
    while (~scanf("%d", &n)) {
        scanf("%s", s + 1);
        int a = 0, b = 0, c = 0, d = 0, e= 0;
        for(int i= 1; i<= n; ++i) {
            if (s[i] == 'x') {
                ++a;
            } else if (s[i] == 't') {
                if (a) {
                    --a;
                    ++b;
                }
            } else if (s[i] == 'C') {
                if (b) {
                    --b;
                    ++c;
                }
            } else if (s[i] == 'p') {
                if (c) {
                    --c;
                    ++d;
                }
            } else if (s[i] == 'c') {
                if (d) {
                    --d;
                    ++e;
                }
            }
        }
        printf("%d\n", e);
    }
    return 0;
}