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
const int N = 3 + 256;

int n, m;
vector<string> a;
vector<char> seq;

vector<int> edge[256];
int du[256];

int topo(int m) {
    for (int i = 0; i < 256; ++i) {
        edge[i].clear();
        du[i] = 0;
    }
    queue<int> q;
    for (int i = 0; i < m; ++i) {
        edge[a[i][0]].push_back(a[i][2]);
        ++du[a[i][2]];
    }
    for (int i = 'A'; i <= 'A' + n - 1; ++i) {
        if (!du[i]) {
            q.push(i);
        }
    }

    int flag = 1;
    seq.clear();
    int cnt = 0;

    while (q.size()) {
        if (q.size() >= 2) {
            flag = 0;
        }

        int x = q.front();
        q.pop();

        seq.push_back(x);

        ++cnt;

        for (auto& y : edge[x]) {
            if (!--du[y]) {
                q.push(y);
            }
        }
    }

    if (!flag) {
        seq.clear();
    }
    return cnt == n;
}

int main() {
    cin >> n >> m;
    for (int i = 1; i <= m; ++i) {
        string s;
        cin >> s;
        a.push_back(s);
    }

    for (int i = 1; i <= m; ++i) {
        if (!topo(i)) {
            cout << "Inconsistency found after " << i << " relations." << endl;
            return 0;
        } else if (seq.size()) {
            cout << "Sorted sequence determined after " << i << " relations: ";
            for (auto& j : seq) {
                cout << j;
            }
            cout << ".";
            return 0;
        }
    }

    cout << "Sorted sequence cannot be determined." << endl;

    return 0;
}