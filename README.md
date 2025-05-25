# DSA Assignment6

Họ và tên: Nguyễn Đăng Khoa

Lớp: ATTN2024

MSSV: 24520825

## Longest Increasing Sequence (LIS)	
Gọi ```dp[i]``` là dãy con tăng dài nhất kết thúc tại vị trí $i$. Ta có thể dễ dàng quy hoạch động với độ phức tạp $O(n^2)$ như sau:
```C++
for (int i = 1; i <= n; ++i) {
    dp[i] = 1; // mỗi a[i] là LIS có độ dài là 1
    for (int j = 1; j < i; ++j) { // Tìm vị trí j trước đó update lại 
        if (a[i] > a[j]) {
            if (dp[i] < dp[j] + 1) {
                dp[i] = dp[j] + 1;
                pre[i] = j;
            }
        }
    }
}
```

Tiếp theo để trace lại, đầu tiên chúng ta tìm vị trí $i$ mà tại đó ```dp[i]``` là lớn nhất xong sau đó trace lại bằng mảng ```pre[i]```, với ```pre[i]``` lưu vị trí của phần tử trước đó.
```C++
void trace(int i) { 
    if (i == 0) return ;
    v.push_back(a[i]);
    trace(pre[i]);
}

trace(i) // i là vị trí dp[i] to nhất 
```

## Knapsack	

Gọi ```dp[i][j]``` là xét tới món đồ $i$, và có số cân nặng trong túi $\leq j$. 

Có 2 trường hợp là:
- Có thể nhét món đồ đó vào túi: ```dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - w[i]] + v[i])```
- Không thể: ```dp[i][j] = dp[i - 1][j]```
```C++
for (int i = 1; i <= n; ++i) {
    for (int j = 0; j <= W; ++j) {
        if (j >= w[i]) dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - w[i]] + v[i]);
        else dp[i][j] = dp[i - 1][j];
    }
}
```
## Sum of Four Values	
Bài này dùng một ```map <int, vector <pii>> m``` để lưu tổng 2 số và vị trí 2 số đó, lúc này để tìm được 4 vị trí thì chỉ cần check xem có tồn tại ```m[s - cur]``` hay chưa.
```C++
rep(i, 1, n) rep(j, 1, i - 1) {
    int cur = a[i] + a[j];
    if (cur > s) continue;

    if (m.find(s - cur) != m.end()) {
        for (auto &T : m[s - cur]) {
            if (T.fi != i && T.fi != j && T.se != i && T.se != j) {
                cout << i << ' ' << j << ' ' << T.fi << ' ' << T.se;
                return ;
            }
        }
    } else m[cur].push_back(pii(i, j));
}
cout << "IMPOSSIBLE";
```
## Meet in the midle	
Bài này $n \leq 40$ ta làm bằng cách MITM chia mảng thành 2 nửa bằng nhau rồi quay lui giải và lưu tổng từng phần lại. Gọi $a$ là tổng ở mảng 1 và $b$ là tổng sinh được là mảng 2 thì chỉ cần đếm xem có bao nhiêu cặp $a + b = s$.
```C++
void Try(int i, int sum, int a[], int n, int d[], int &id) {
    rep(j, i, n) {
        d[++id] = sum + a[j];
        if (d[id] == s) res++;
        Try(j + 1, d[id], a, n, d, id);
    }
}

Try(1, 0, a, m, s1, n1);
Try(1, 0, b, k, s2, n2);

sort(s2 + 1, s2 + 1 + n2);
for (int i = 1; i <= n1; ++i) {
    int L = lower_bound(s2+1, s2+1+n2, s-s1[i])-s2;
    if (L > n2 || s2[L] + s1[i] != s) continue;
    int R = upper_bound(s2+1, s2+1+n2, s-s1[i])-s2;
    res += (R - L);
}
cout << res;
```
## Tìm đường đi trên đồ thi (BFS)	
Bài này bfs sau đó trace lại đường đi từ u -> v
```C++
void BFS(char source, char sink) {
    map <char, bool> used;
    map <char, char> trace;
    queue <char> q;

    for (auto T : adj) used[T.first] = 0;
    
    q.push(source);
    trace[source] = '\0';

    while (q.size()) {
        char u = q.front(); q.pop();

        if (adj.find(u) != adj.end()) {
            for (char v : adj[u]) {
                if (!used[v]) {
                    used[v] = 1;
                    trace[v] = u;
                    q.push(v);

                    if (v == sink) {
                        vii path;
                        char node = sink;

                        path.push_back(sink);
                        while (trace[node] != source) {
                            node = trace[node];
                            path.push_back(node);
                        }
                        path.push_back(source);
                    
                        repd(i, sz(path) - 1, 0) cout << path[i] << ' '; cout << endl;
                        return ;
                    }
                }
            }
        }
    }
    cout << "no_path" << endl;
}
```
## Tìm đường đi trên đồ thi (DFS)	
Bài này dfs sau đó trace lại đường đi từ u -> v. Nhưng trong các đường đi thì chúng ta update chỉ lấy đường đi ngắn nhất.
```C++
void dfs(int u, int en) {
    vis[u] = 1;
    path.push_back(b[u]);

    if (u == en) {          
        // repd(i, sz(path) - 1, 0) cout << path[i] << ' '; cout << endl;
        if (sz(res) > sz(path) || sz(res) == 0) res = path;
        ok = 1;
    }
    for (int v : adj[u]) if (!vis[v]) {
        dfs(v, en);
    }

    vis[u] = 0;
    path.pop_back();
}
```
## khangtd.ConnectedComponents	
Bài này đơn giản là BFS từ đỉnh $S$ sau đó in ra size thành phần liên thông BFS từ $S$.
## Đồ thị vô hướng - Đếm số đỉnh cô lập	
Bài này check đỉnh cô lập.
```C++
int res = 0;
for (int i = 0; i < n; ++i) {
    if (sz(adj[i]) == 0) ++res;
}
```
## Đồ thị vô hướng - Đếm số thành phần liên thông	
Bài này đếm số thành phần liên thông bằng cách duyệt qua các đỉnh chưa được duyệt và bfs từ đỉnh đó.
```C++
int res = 0;
rep(i, 0, n - 1) if (!vis[i]) bfs(i), ++res;
    
cout << res;
```
## Đồ thị vô hướng - Liệt kê các đỉnh có thể tới từ đỉnh S
Bài này BFS từ đỉnh $0$ và sau đó in ra các đỉnh nằm trong thành phần liên thông của đỉnh $0$ này. 
## Đồ thị vô hướng - Kiểm tra có đường đi từ đỉnh S tới đỉnh E	
Bài này bfs từ đỉnh $0$ và in ra cạnh đỉnh nào không nằm trong thành phần liên thông của $0$.
## Wildcard	
Bài này chúng ta có dễ dàng nhìn thấy bài này sử dụng Trie do bài là đếm các xâu khớp với * là chuỗi bất kì. Nhưng ở đây chúng ta lưu thêm một vector lưu các vị trí khớp.
```C++
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
```

Tới đây có 3 trường hợp 
```C++
string t; getline(cin, t);
int pos = t.find('*');
        
// TH Không có dấu *
if (pos == -1) {
    cout << cnt[t] << endl;
    continue;
}
        
// chia ra 2 xâu con
string pre = t.substr(0, pos);
string suf = t.substr(pos + 1);
        
// TH *
if (!sz(pre) && !sz(suf)) {
    cout << n << endl;
    continue;
}
        
vii res;
       
// TH prefix *
if (!sz(suf)) {
    cout << sz(preTrie.Find(pre)) << endl;
    continue ;
} 

// TH * suf
if (!sz(pre)) {
    reverse(all(suf));
    cout << sz(sufTrie.Find(suf)) << endl;
    continue;
}  

// TH prefix * suf 
res = preTrie.Find(pre);

vii candidates;
for (int i : res) {
    if (sz(s[i]) >= sz(pre) + sz(suf) && s[i].substr(sz(s[i]) - sz(suf)) == suf) candidates.push_back(i);
}

cout << sz(candidates) << endl;
```