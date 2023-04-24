#include <bits/stdc++.h>

using namespace std;

#define V vector

typedef long long LL;
typedef pair<int, int> pii;

typedef V<int> vi;
typedef V<string> vs;
typedef V<LL> vl;
typedef V<double> vd;

#define forup(i, a, b) for (int i = (a); i < (b); ++i)
#define fordn(i, a, b) for (int i = (a); i > (b); --i)
#define rep(i, a) for (int i = 0; i < (a); ++i)
#define fov(i, a) rep(i, (a).size())
#define foreach(i, X) for (__typeof((X).begin()) i = (X).begin(); i != (X).end(); i++)

#define gi(x) scanf("%d", &x)
#define gl(x) scanf("%I64d", &x)
#define gd(x) scanf("%lf", &x)
#define gs(x) cin >> x

#define pi(x) printf("%d", x)
#define pin(x) printf("%d\n", x)
#define pl(x) printf("%I6d", x)
#define pln(x) printf("%I64d\n", x)
#define ps(s) cout << s;
#define psn(s) cout << s << "\n"
#define pn printf("\n")
#define spc printf(" ")
#define prec(x) cout << fixed << setprecision(x)

#define all(x) (x).begin(), (x).end()

#define fs first
#define sc second

#define pb push_back
#define mp make_pair

#define fr freopen("input.in", "r", stdin)
#define fw freopen("output.out", "w", stdout)

const int inf = numeric_limits<int>::max();
const LL linf = numeric_limits<LL>::max();
const double EPS = 1e-7;

const int MAXN = 1000000;
const int LOGMAXN = log2(MAXN) + 3;

inline char toChar(int i)
{
    return static_cast<char>('a' + i);
}

struct trie
{
    trie *a[26];
    int weight;

    trie()
    {
        rep(i, 26) a[i] = NULL;
        weight = 0;
    }
};

trie *insert(const string &s, int wt, int idx, trie *root)
{
    int cur = s[idx] - 'a';
    if (!root->a[cur])
        root->a[cur] = new trie();
    root->a[cur]->weight = max(root->a[cur]->weight, wt);
    if (idx + 1 != s.size())
    {
        root->a[cur] = insert(s, wt, idx + 1, root->a[cur]);
    }
    return root;
}

int searchBest(const string &s, trie *root)
{
    int idx = 0, n = s.size(), cur, bestWt = -1;
    while (idx < n)
    {
        cur = s[idx] - 'a';
        if (!root->a[cur])
            return -1;
        bestWt = root->a[cur]->weight;
        root = root->a[cur];
        ++idx;
    }
    return bestWt;
}

void print(string s, trie *root)
{
    rep(i, 26) if (root->a[i]) print(s + toChar(i), root->a[i]);
    psn(s);
    pi(root->weight);
}

int main()
{
    // fr; fw;
    int n, w, q, tot = 0, cnt = 0;
    string s, t;
    gi(n);
    gi(q);
    assert(n <= MAXN);
    trie *root = new trie();
    while (n--)
    {
        gs(s);
        gi(w);
        tot += s.size();
        root = insert(s, w, 0, root);
    }
    assert(tot <= MAXN);
    tot = 0;
    // print("", root);
    while (gs(s))
    {
        // gs(s);
        ++cnt;
        tot += s.size();
        pin(searchBest(s, root));
    }
    assert(tot <= MAXN);
    assert(cnt == q);
    return 0;
}
