#include <bits/stdc++.h>
using namespace std;
using LL = long long;
using PII = pair<int, int>;

#define lson (k << 1)
#define rson (k << 1 | 1)

const int mod = 7 + 1e9;
// const int mod = 998244353;
const int N = 3 + 2e5;

int n, m, a[N];
int b[N];

int main() {
    int T;
    cin >> T;
    while (T--) {
        cin >> n;
        vector<int> a(n+1),b=a,vis=a;
        vector<pair<int,int>> ve;
        for(int i=1;i<=n;i++) vis[i]=i;
        auto find = [&](auto find,int x)->int{
            if(x==vis[x]) return x;
            return vis[x]=find(find,vis[x]);
        };
        auto add = [&](int x)->int{
            vis[x]=x-1;
        };
        for(int i=1;i<=n;i++){
            cin>>b[i];
            ve.push_back({b[i],i});
        }
        sort(b.begin(),b.end(),greater<pair<int,int>>());
        for(auto &i : ve){
            int x=i.first;
            int y=i.second;
            if(!x){
                int t=find(find,n);
                a[y]=t;
                vis[t]=t-1;
            }
            else{
                int r=y/x;
                int t=find(find,r);
                a[y]=t;
                vis[t]=t-1;                
            }
        }
        for(int i=1;i<=n;i++) cout<<a[i]<<" ";
        cout<<endl;
    }

    return 0;
}