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

const lld pi = 3.14159265358979323846;
const ll mod = 1000000007;

ll k, l, m, n, p, q, r, x, y, z;
ll ans = 0;
string s, t;

const ll template_array_size = 1e6 + 6884;
ll a[template_array_size];
ll b[template_array_size];
ll c[template_array_size];

ll binpow(ll a, ll b)
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

int randomint(int min, int max)
{
    return rand() % (max - min + 1) + min;
}

double randomdouble(double min, double max)
{
    return (rand() / (double)RAND_MAX) * (max - min) + min;
}

void solve(int tc = 0)
{
    cin >> n;
    in_arr(a, i, 0, n);
    in_arr(b, i, 0, n);

    vl state(n, -1);
    for (int msb = 1 << 29; msb > 0; msb >>= 1)
    {
        bool poss = true;
        repf(i, 0, n)
        {
            if (state[i] == 0 && !(a[i] & msb))
                poss = false;
            else if (state[i] == 1 && !(b[i] & msb))
                poss = false;
            else if (!(a[i] & msb) && !(b[i] & msb))
                poss = false;

            if (!poss)
                break;
        }

        if (!poss)
            continue;

        repf(i, 0, n)
        {
            if (state[i] != -1)
                continue;
            else if (!(a[i] & msb))
                state[i] = 1;
            else if (!(b[i] & msb))
                state[i] = 0;
        }
    }

    ans = (1 << 30) - 1;
    int total = 0;

    repf(i, 0, n)
    {
        if (state[i] == 1)
            ans &= b[i], total++;
        else
            ans &= a[i];
    }

    println(ans, total);
}

signed main()
{
    send help

    int tc = 1;
    cin >> tc;
    for (int t = 0; t < tc; t++)
        solve(t);
}