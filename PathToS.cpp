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

int n, m;
vector <int> adj[N], res;
bool vis[N];

void bfs(int x) {
    queue <int> q;
    q.push(x);
    vis[x] = 1;

    while (q.size()) {
        int u = q.front(); q.pop();

        for (int v : adj[u]) if (!vis[v]) {
            vis[v] = 1;
            q.push(v);
            res.push_back(v);
        }
    }
}

void solve(void) {
    cin >> n >> m;
    rep(i, 1, m) {
        int u, v;
        cin >> u >> v;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    bfs(0);
    
    sort(all(res));
    for (auto T : res) cout << T << ' ';
}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    if (multitest) {
        int t; cin >> t;
        while (t-- ) solve();
    } else solve();

    return 0;
}