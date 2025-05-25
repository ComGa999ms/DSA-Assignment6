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

## Tìm đường đi trên đồ thi (DFS)	
## khangtd.ConnectedComponents	
## Đồ thị vô hướng - Đếm số đỉnh cô lập	
## Đồ thị vô hướng - Đếm số thành phần liên thông	
## Đồ thị vô hướng - Liệt kê các đỉnh có thể tới từ đỉnh S
## Đồ thị vô hướng - Kiểm tra có đường đi từ đỉnh S tới đỉnh E	
## Wildcard	
