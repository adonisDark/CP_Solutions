#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double lld;
typedef unsigned long long ull;
#define int long long int

#define send                              \
    {                                     \
        ios_base::sync_with_stdio(false); \
    }
#define help           \
    {                  \
        cin.tie(NULL); \
    }

#define allv(v) v.begin(), v.end()
#define alla(v, n) v, v + n

#define F first
#define S second
#define PB push_back
#define MP make_pair

#define repf(i, a, b) for (int i = a; i < b; i++)
#define repb(i, a, b) for (int i = a; i > b; i--)
#define repi(i, v) for (auto i = v.begin(); i != v.end(); i++)

#define in_arr(name, i, k, l)   \
    for (int i = k; i < l; i++) \
        cin >> name[i];
#define out_arr(name, i, k, l)      \
    {                               \
        for (int i = k; i < l; i++) \
            cout << name[i] << " "; \
        cout << endl;               \
    }
#define out_rev_arr(name, i, k, l)  \
    {                               \
        for (int i = k; i > l; i--) \
            cout << name[i] << " "; \
        cout << endl;               \
    }

#define in_s(s) getline(cin, s)
#define in_str(s)               \
    {                           \
        getline(cin, s);        \
        while (s.length() == 0) \
            getline(cin, s);    \
    }
#define rev(s) reverse(allv(s))

#define vl vector<ll>
#define vll vector<vector<ll>>

#define vb vector<bool>
#define vbb vector<vector<bool>>

#define vc vector<char>
#define vcc vector<vector<char>>

#define vs vector<string>
#define vss vector<vector<string>>

#define vpl vector<pair<ll, ll>>
#define vpll vector<vector<pair<ll, ll>>>
#define pl pair<ll, ll>

#define low(s) transform(allv(s), s.begin(), ::tolower)
#define up(s) transform(allv(s), s.begin(), ::toupper)

#define sz(s) s.size()
#define len(s) s.length()
#define endl '\n'

template <class T>
void swap2(T &x, T &y)
{
    T w = x;
    x = y;
    y = w;
}

template <class T>
void swap3(T &x, T &y, T &z)
{
    T w = x;
    x = y;
    y = z;
    z = w;
}

template <class T>
T max(T &x, T &y) { return (x > y) ? x : y; }

template <class T>
T max(T &x, T &y, T &z) { return max(x, max(y, z)); }

template <class T>
T min(T &x, T &y) { return (x < y) ? x : y; }

template <class T>
T min(T &x, T &y, T &z) { return min(x, min(y, z)); }

lld gcd(lld x, lld y) { return fabs(y) < 1e-4 ? x : gcd(y, fmod(x, y)); }

void print() { cout << endl; }

template <typename A>
void print(A value) { cout << value << " "; }

template <>
void print<double>(double value) { printf("%lf", value); }

template <typename A, typename B>
void print(A value1, B value2) { cout << value1 << " " << value2 << " "; }

template <typename A, typename B, typename C>
void print(A value1, B value2, C value3) { cout << value1 << " " << value2 << " " << value3 << " "; }

template <typename A, typename B, typename C, typename D>
void print(A value1, B value2, C value3, D value4)
{
    cout << value1 << " " << value2 << " " << value3 << " " << value4 << " ";
}

template <typename A>
void println(A value) { cout << value << endl; }

template <typename A, typename B>
void println(A value1, B value2) { cout << value1 << " " << value2 << endl; }

template <typename A, typename B, typename C>
void println(A value1, B value2, C value3) { cout << value1 << " " << value2 << " " << value3 << endl; }

template <typename A, typename B, typename C, typename D>
void println(A value1, B value2, C value3, D value4)
{
    cout << value1 << " " << value2 << " " << value3 << " " << value4 << endl;
}

mt19937_64 rng(std::chrono::steady_clock::now().time_since_epoch().count());
const lld pi = 3.14159265358979323846;
const ll mod = 1000000007;

ll k, l, m, n, p, q, r, x, y, z;
ll ans = 0;
string s, t;

const ll template_array_size = 1e6 + 6884;
ll a[template_array_size];
ll b[template_array_size];
ll c[template_array_size];

ll pow(ll a, ll b)
{
    a %= mod;

    ll res = 1;
    while (b > 0)
    {
        if (b & 1)
            res = res * a % mod;

        a = a * a % mod;
        b >>= 1;
    }
    return res;
}

bool isOperator(char c)
{
    return (!isalpha(c) && !isdigit(c));
}

bool isOp(char c)
{
    switch (c)
    {
    case '+':
    case '-':
    case '*':
    case '/':
        return true;
    }
    return false;
}

int getPref(char c)
{
    if (c == '^')
        return 3;
    else if (c == '*' || c == '/')
        return 2;
    else if (c == '+' || c == '-')
        return 1;

    return 0;
}

string infix(string s)
{
    rev(s);

    stack<string> st;
    for (char c : s)
    {
        if (isalpha(c) || isdigit(c))
        {
            st.push(string(1, c));
        }
        else if (isOp(c))
        {
            string c1 = st.top();
            st.pop();
            string c2 = st.top();
            st.pop();

            string temp = "(" + c1 + c + c2 + ")";
            st.push(temp);
        }
    }
    return st.top();
}

string postfix(string s)
{
    s = '(' + s + ')';

    stack<char> st;
    string res;

    for (char c : s)
    {
        if (isalpha(c) || isdigit(c))
        {
            res += c;
        }
        else if (c == '(')
        {
            st.push('(');
        }
        else if (c == ')')
        {
            while (st.top() != '(')
            {
                res += st.top();
                st.pop();
            }
            st.pop();
        }
        else
        {
            if (isOperator(c))
            {
                if (c == '^')
                {
                    while (getPref(c) <= getPref(st.top()))
                    {
                        res += st.top();
                        st.pop();
                    }
                }
                else
                {
                    while (getPref(c) < getPref(st.top()))
                    {
                        res += st.top();
                        st.pop();
                    }
                }
                st.push(c);
            }
        }
    }
    return res;
}

string prefix(string s)
{
    rev(s);

    repf(i, 0, len(s))
    {
        if (s[i] == '(')
        {
            s[i] = ')';
        }
        else if (s[i] == ')')
        {
            s[i] = '(';
        }
    }

    string res = postfix(s);
    rev(res);

    return res;
}

int appOp(int val1, int val2, char op)
{
    int ans;
    switch (op)
    {
    case '+':
        ans = val1 + val2;
        break;
    case '-':
        ans = val1 - val2;
        break;
    case '*':
        ans = val1 * val2;
        break;
    case '/':
        ans = val1 - val2;
        break;
    }
    return ans;
}

int evalPostfix(string s)
{
    stack<int> val;
    stack<char> ops;

    repf(i, 0, len(s))
    {
        if (s[i] == '(')
        {
            ops.push('(');
        }
        else if (isdigit(s[i]))
        {
            int ans = 0;

            while (i < len(s) && isdigit(s[i]))
            {
                ans = (ans * 10) + (s[i] - '0');
                i++;
            }
            val.push(ans);
            i--;
        }
        else if (s[i] == ')')
        {
            while (!ops.empty() && ops.top() != '(')
            {
                int val2 = val.top();
                val.pop();
                int val1 = val.top();
                val.pop();

                char op = ops.top();
                ops.pop();
                val.push(appOp(val1, val2, op));
            }
            if (!ops.empty())
                ops.pop();
        }
        else
        {
            while (!ops.empty() && getPref(ops.top()) >= getPref(s[i]))
            {
                int val2 = val.top();
                val.pop();
                int val1 = val.top();
                val.pop();

                char op = ops.top();
                ops.pop();
                val.push(appOp(val1, val2, op));
            }
            ops.push(s[i]);
        }
    }

    while (!ops.empty())
    {
        int val2 = val.top();
        val.pop();
        int val1 = val.top();
        val.pop();

        char op = ops.top();
        ops.pop();
        val.push(appOp(val1, val2, op));
    }
    return val.top();
}

int binary_search(int start, int end, int target)
{
    while (start <= end)
    {
        int mid = start + (end - start) / 2;
        if (a[mid] == target)
            return mid;

        else if (a[mid] < target)
            start = mid + 1;
        else
            end = mid - 1;
    }
    return -1;
}

int pivot(int start, int end)
{
    while (start <= end)
    {
        int mid = start + (end - start) / 2;

        if (mid < end && a[mid] > a[mid + 1])
            return mid;
        else if (mid > start && a[mid] < a[mid - 1])
            return mid - 1;
        else if (a[start] >= a[mid])
            end = mid - 1;
        else
            start = mid + 1;
    }
    return -1;
}

bool isPalin(int start, int end, string s)
{
    while (start < end)
    {
        if (s[start++] != s[end--])
            return false;
    }

    return true;
}

vll graph(template_array_size);
vector<vector<pair<int, int>>> weightGraph(template_array_size);

void dfsUtil(int vertex, vb &vis)
{
    vis[vertex] = true;
    print(vertex);

    for (int next : graph[vertex])
    {
        if (!vis[next])
            dfsUtil(next, vis);
    }
}

void dfs(int start, int vertices)
{
    vb vis(vertices, false);

    repf(vertex, 0, vertices)
    {
        if (vis[vertex] == false)
            dfsUtil(vertex, vis);
    }
}

void bfs(int start, int vertices)
{
    vb vis(vertices, false);

    int level[vertices];
    level[start] = 0;

    int parent[vertices];
    parent[start] = -1;

    queue<int> q;
    q.push(start);

    while (!q.empty())
    {
        int cur = q.front();
        q.pop();

        print(cur);

        vis[cur] = true;
        for (auto next : graph[cur])
        {
            if (!vis[next])
            {
                q.push(next);
                vis[next] = true;

                level[next] = level[cur] + 1;
                parent[next] = cur;
            }
        }
    }
}

void topologicalSortUtil(int cur, vb &vis, stack<int> &st)
{
    vis[cur] = true;

    for (int next : graph[cur])
    {
        if (!vis[next])
            topologicalSortUtil(next, vis, st);
    }
    st.push(cur);
}

void topologicalSort(int vertices)
{
    vb vis(vertices, false);
    stack<int> st;

    repf(vertex, 0, n)
    {
        if (!vis[vertex])
            topologicalSortUtil(vertex, vis, st);
    }

    while (!st.empty())
    {
        print(st.top());
        st.pop();
    }
}

const int inf = 2000000000;
const ll infLL = 9000000000000000000;

// using set
void dijkstra_sparse_set(int src, int vertices, int start, int end)
{
    vl dist(vertices, infLL);
    vl parent(vertices, -1);
    vb vis(vertices, false);

    dist[src] = 0;
    set<pair<int, int>> s;
    s.insert({0, src});

    while (!s.empty())
    {
        int cur = s.begin()->S;
        s.erase(s.begin());

        for (auto edge : weightGraph[cur])
        {
            int next = edge.F;
            int wt = edge.S;

            if (dist[cur] + wt < dist[next])
            {
                s.erase({dist[next], next});
                dist[next] = dist[cur] + wt;

                parent[next] = cur;
                s.insert({dist[next], next});
            }
        }
    }

    if (dist[end] == infLL)
    {
        println(-1);
        return;
    }

    vl path;
    for (int vertex = end; vertex != start; vertex = parent[vertex])
        path.PB(vertex);
    path.PB(start);
    rev(path);

    // println(dist[end]);
    repf(i, 0, sz(path)) print(path[i]);
    print();
}

// using minHeap
void dijkstra_sparse_heap(int src, int vertices, int start, int end)
{
    vl dist(vertices, infLL);
    vl parent(vertices, -1);
    vb vis(vertices, false);

    dist[src] = 0;
    using pii = pair<int, int>;

    priority_queue<pii, vector<pii>, greater<pii>> q;
    q.push({0, src});

    while (!q.empty())
    {
        int cur = q.top().S;
        int dist_cur = q.top().F;

        q.pop();
        if (dist_cur != dist[cur])
            continue;

        for (auto edge : weightGraph[cur])
        {
            int next = edge.F;
            int wt = edge.S;

            if (dist[cur] + wt < dist[next])
            {
                dist[next] = dist[cur] + wt;
                parent[next] = cur;

                q.push({dist[next], next});
            }
        }
    }

    if (dist[end] == infLL)
    {
        println(-1);
        return;
    }

    vl path;
    for (int vertex = end; vertex != start; vertex = parent[vertex])
        path.PB(vertex);
    path.PB(start);
    rev(path);

    // println(dist[end]);
    repf(i, 0, sz(path)) print(path[i]);
    print();
}

void dijkstra_dense(int src, int vertices, int start, int end)
{
    vl dist(vertices, infLL);
    vl parent(vertices, -1);
    vb vis(vertices, false);

    dist[src] = 0;
    repf(node, 0, vertices)
    {
        int cur = -1;
        repf(vertex, 0, vertices)
        {
            if (!vis[vertex] && (cur == -1 || dist[vertex] < dist[cur]))
                cur = vertex;
        }

        if (dist[cur] == infLL)
            break;
        vis[cur] = true;

        for (auto edge : weightGraph[cur])
        {
            int next = edge.F;
            int wt = edge.S;

            if (dist[cur] + wt < dist[next])
            {
                dist[next] = dist[cur] + wt;
                parent[next] = cur;
            }
        }
    }

    if (dist[end] == infLL)
    {
        println(-1);
        return;
    }

    vl path;
    for (int vertex = end; vertex != start; vertex = parent[vertex])
        path.PB(vertex);
    path.PB(start);
    rev(path);

    // println(dist[end]);
    repf(i, 0, sz(path)) print(path[i]);
    print();
}

void weighted(int vertices, int edges = 0)
{
    int n = vertices;
    repf(i, 1, vertices + 1) weightGraph[i].clear();

    repf(i, 1, n)
    {
        cin >> x >> y;

        weightGraph[i].PB({x, y});
        weightGraph[y].PB({x, k});
    }

    // repf(i, 0, n+1) {
    // 	cout << i << "->";

    // 	repf(j, 0, sz(weightGraph[i])) print(weightGraph[i][j].F);
    // 	print();
    // }

    // dijkstra_sparse_heap(1, n, 1, n-1);
}

bool valid(int n, map<int, set<int>> &graph)
{
    vb vis(n, false);
    vl parent(n, -1);
    queue<int> q;

    int vertex = a[1];
    q.push(vertex);

    if (vertex != 1)
        return 0;

    ans = 1;
    k = 2;
    while (!q.empty())
    {
        int cur = q.front();
        q.pop();

        vis[cur] = true;
        repi(node, graph[cur])
        {
            if (*node == parent[cur])
                continue;

            if (graph[cur].find(a[k]) == graph[cur].end())
            {
                return 0;
            }

            q.push(a[k]);
            vis[a[k]] = true;

            parent[a[k]] = cur;
            k++;
        }
    }

    return 1;
}

void simple(int vertices, int edges = 0)
{
    int n = vertices;
    repf(i, 1, vertices + 1) graph[i].clear();

    cin >> m;
    repf(i, 1, n - 1)
    {
        cin >> x >> y;

        graph[x].PB(y);
        graph[y].PB(x);
    }

    // while(m--) {
    // 	cin >> x >> y;
    // }

    // repf(i, 1, n) {
    // 	cout << i << "->";

    // 	repf(j, 0, sz(graph[i])) print(graph[i][j]);
    // 	print();
    // }

    // topologicalSort(n);

    // repi(it, graph) {
    // 	cout << it->F << "->";
    // 	repi(i, it->S) print(*i);
    // 	print();
    // }

    // in_arr(a, i, 1, n);
    // ans = valid(n, graph);

    // if(ans) println("YES");
    // else println("NO");
}

int randomint(int min, int max)
{
    return rand() % (max - min + 1) + min;
}

double randomdouble(double min, double max)
{
    return (rand() / (double)RAND_MAX) * (max - min) + min;
}

// bool isOperator(char c);
// bool isOp(char c);
// int getPref(char c);

// string infix(string s);
// string postfix(string s);
// string prefix(string s);

// int appOp(int val1, int val2, char op);
// int evalPostfix(string s);

// int binary_search(int start, int end, int target);
// int pivot(int start, int end);

// bool isPalin(int start, int end, string s);

// vll graph(template_array_size);
// vector<vector<pair<int, int>>> weightGraph(template_array_size);

// void dfsUtil(int vertex, vb &vis);
// void dfs(int start, int vertices);
// void bfs(int start, int vertices);

// void topologicalSortUtil(int cur, vb &vis, stack<int> &st);
// void topologicalSort(int vertices);

// void dijkstra_sparse_set (int src, int vertices, int start, int end);
// void dijkstra_sparse_heap (int src, int vertices, int start, int end);
// void dijkstra_dense (int src, int vertices, int start, int end);

// void weighted(int vertices, int edges = 0);
// bool valid(int n, map<int,set<int>> &graph);
// void simple(int vertices, int edges = 0);

void solve(int tc = 0)
{
    // cin >> n;
    cin >> n >> m;

    // simple(n + 1);
    // weighted(n,m);

    in_arr(a, i, 0, n);
    sort(alla(a, n));

    ans = 0;
    repf(i, 0, n)
    {
        if (a[i] > 0)
            ans += a[i];

        if (m && a[i] < 0)
        {
            m--;
            ans -= a[i];
        }
    }

    if (ans < 0)
    {
        println(0);
        return;
    }

    println(ans);
}

signed main()
{
#ifndef ONLINE_JUDGE
    auto begin = std::chrono::high_resolution_clock::now();
#endif

    send help

#ifndef ONLINE_JUDGE
        freopen("//home//adonis//input.txt", "r", stdin);
    freopen("//home//adonis//output.txt", "w", stdout);
#endif

    int tc = 1;
    cin >> tc;
    for (int t = 0; t < tc; t++)
        solve(t);

#ifndef ONLINE_JUDGE
    auto end = std::chrono::high_resolution_clock::now();
    cout << setprecision(4) << fixed;
    cout << "Execution time: " << std::chrono::duration_cast<std::chrono::duration<double>>(end - begin).count() << " seconds" << endl;
#endif
}