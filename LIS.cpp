#include <bits/stdc++.h>
#define all(v) (v).begin(), (v).end()
#define int long long
#define rep(i, l, r) for (int i = l; i <= r; ++i)
#define repd(i, r, l) for (int i = r; i >= l; --i)
#define _unique(x) (x).resize(unique((x).begin(), (x).end()) - (x).begin());
#define sz(v) (int)(v).size()
#define fi first
#define se second
#define pii pair<int,int>
#define p2i pair<int,pii>
#define endl "\n"

using namespace std;

const int N = 1e6 + 5;
const int inf = 1e18 + 7;
const bool multitest = 0;

int n;
int a[N], dp[N], pre[N];
vector <int> v;

void trace(int i) {
    if (i == 0) return ;
    v.push_back(a[i]);
    trace(pre[i]);
}

void solve(void) {
    cin >> n;
    rep(i, 1, n) cin >> a[i];

    rep(i, 1, n) {
        dp[i] = 1;
        for (int j = 1; j < i; ++j) {
            if (a[i] > a[j]) {
                if (dp[i] < dp[j] + 1) {
                    dp[i] = dp[j] + 1;
                    pre[i] = j;
                }
            }
        }
    }

    int res = 0;
    rep(i, 1, n) res = max(res, dp[i]);
    cout << res << endl;

    int id = 0;
    rep(i, 1, n) if (dp[i] == res) id = i;
    trace(id);

    repd(i, sz(v) - 1, 0) cout << v[i] << ' ';
}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    if (multitest) {
        int t; cin >> t;
        while (t-- ) solve();
    } else solve();

    return 0;
}