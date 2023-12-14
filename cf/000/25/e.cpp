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

char s[3][N];
int ne[3][N];
int len[3];
vector<int> p;

void kmp(int n, char* s, int* ne) {
    for (int i = 2, j = 0; i <= n; ++i) {
        while (j && s[j + 1] != s[i]) {
            j = ne[j];
        }
        if (s[j + 1] == s[i]) {
            ++j;
        }
        ne[i] = j;
    }
}

int contain(int x, int y) {
    for (int i = 1, j = 0; i <= len[x]; ++i) {
        while (j && s[y][j + 1] != s[x][i]) {
            j = ne[y][j];
        }
        if (s[y][j + 1] == s[x][i]) {
            ++j;
        }
        if (j == len[y]) {
            return 1;
        }
    }
    return 0;
}

int main() {
    for (int i = 0; i < 3; ++i) {
        cin >> s[i] + 1;
        len[i] = strlen(s[i] + 1);
        kmp(len[i], s[i], ne[i]);
    }
    for (int i = 0; i < 3; ++i) {
        int erase = 0;
        for (int j = (int)p.size() - 1; j >= 0; --j) {
            if (len[p[j]] >= len[i]) {
                if (contain(p[j], i)) {
                    erase = 1;
                }
            } else {
                if (contain(i, p[j])) {
                    p.erase(p.begin() + j);
                }
            }
        }
        if (!erase) {
            p.push_back(i);
        }
    }

    int ans = 1e9;

    do {
        int cnt = 0;
        for (auto& i : p) {
            cnt += len[i];
        }

        auto calc = [&](int x, int y) {
            int i = 1, j = 0;
            for (; i <= len[x]; ++i) {
                while (j && s[y][j + 1] != s[x][i]) {
                    j = ne[y][j];
                }
                if (s[y][j + 1] == s[x][i]) {
                    ++j;
                }
            }
            return j;
        };

        for (int i = 1; i < p.size(); ++i) {
            cnt -= calc(p[i - 1], p[i]);
        }
        ans = min(ans, cnt);
    } while (next_permutation(p.begin(), p.end()));
    cout << ans << endl;

    return 0;
}