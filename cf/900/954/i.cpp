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
const int M = 'f' - 'a';

char s[N], t[N];
int n, m;
vector<int> ve[M];

int main() {
    cin >> s + 1 >> t + 1;
    n = strlen(s + 1);
    m = strlen(t + 1);
    for (int i = 0; i < M; ++i) {
        ve[i].push_back(0);
    }
    
    return 0;
}