#include <bits/stdc++.h>
#define inr long long
#define all(v) (v).begin(), (v).end()
#define rep(i, l, r) for (int i = l; i <= r; ++i)
#define repd(i, r, l) for (int i = r; i >= l; --i)
#define _unique(x) (x).resize(unique((x).begin(), (x).end()) - (x).begin());
#define sz(v) (int)(v).size()
#define fi first
#define se second
#define pii pair<int,int>
#define vii vector<int>
#define endl "\n"

using namespace std;

const int N = 1e6 + 5;
const int inf = 1e18 + 7;
const bool multitest = 0;

struct Trie {
    map<char, Trie*> cnt;
    vii labels;
    
    void Insert(const string &s, int id, int pos = 0) {
        if (pos < sz(s)) {
            char c = s[pos];
            if (!cnt.count(c)) cnt[c] = new Trie();
            cnt[c]->Insert(s, id, pos + 1);
        }
        labels.push_back(id);
    }
    
    vii Find(const string &s, int pos = 0) {
        if (pos == sz(s)) return labels;
        char c = s[pos];
        if (!cnt.count(c)) return {};
        return cnt[c]->Find(s, pos + 1);
    }
};

int n, m;
map <string, int> cnt;

void solve(void) {
    cin >> n >> m;
    cin.ignore();
    
    vector <string> s(n + 1);
    Trie preTrie, sufTrie;
    
    rep(i, 1, n) {
        getline(cin, s[i]);

        cnt[s[i]]++;
        preTrie.Insert(s[i], i);
        string rev = s[i];
        reverse(all(rev));
        sufTrie.Insert(rev, i);
    }
    
    while (m--) {
        string t; getline(cin, t);
        int pos = t.find('*');
        
        if (pos == -1) {
            cout << cnt[t] << endl;
            continue;
        }
        
        string pre = t.substr(0, pos);
        string suf = t.substr(pos + 1);
        
        if (!sz(pre) && !sz(suf)) {
            cout << n << endl;
            continue;
        }
        
        vii res;
        
        if (!sz(suf)) {
            cout << sz(preTrie.Find(pre)) << endl;
            continue ;
        } 
        if (!sz(pre)) {
            reverse(all(suf));
            cout << sz(sufTrie.Find(suf)) << endl;
            continue;
        }  
        
        res = preTrie.Find(pre);
        vii candidates;
        for (int i : res) {
            if (sz(s[i]) >= sz(pre) + sz(suf) && s[i].substr(sz(s[i]) - sz(suf)) == suf) candidates.push_back(i);
        }
        cout << sz(candidates) << endl;
    }
}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    if (multitest) {
        int t; cin >> t;
        while (t--) solve();
    } else solve();
    
    return 0;
}