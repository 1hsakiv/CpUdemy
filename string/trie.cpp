#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;

#define int long long
#define mp make_pair
#define pii pair<int, int>
#define vi vector<int>
#define mii map<int, int>
#define pqb priority_queue<int>
#define pqs priority_queue<int, vi, greater<int>>
#define setbits(x) __builtin_popcountll(x)
#define zerobits(x) __builtin_ctzll(x)
#define inf 1e18
#define ps(x, y) fixed << setprecision(y) << x
#define mk(arr, n, type) type *arr = new type[n];
#define w(t)  \
    int t;    \
    cin >> t; \
    while (t--)
#define sp << " " <<
#define ms(a, value) memset(a, value, sizeof(a))
#define pb push_back
#define fi first
#define se second
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define repA(i, a, n) for (int i = a; i <= (n); ++i)
#define repD(i, a, n) for (int i = a; i >= (n); --i)
#define trav(a, x) for (auto &a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
#define N 20000000
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
class Triplet
{
public:
    int x, y, z;
};
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> indexed_set;

const int dx[4] = {0, 0, 1, -1};
const int dy[4] = {1, -1, 0, 0};
const int mod = 1e9 + 7;
string str;
map<int, int> freq;
const double PI = 3.1415926535897;

void IOS()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}

struct node
{
    node *nxt[26];
    bool is_end;
    node()
    {
        for (int i = 0; i < 26; i++)
            nxt[i] = NULL;
        is_end = false;
    }
};

node *root;

void insert_trie(string s)
{
    node *cur = root;
    for (int i = 0; i < s.size(); i++)
    {
        int imap = s[i] - 'a';
        // new node
        if (cur->nxt[imap] == NULL)
        {
            cur->nxt[imap] = new node();
        }
        // goto that node
        cur = cur->nxt[imap];
    }
    // cur -> last node
    cur->is_end = true;
}

// O(|s|)
bool search_trie(string s)
{
    node *cur = root;
    for (int i = 0; i < s.size(); i++)
    {
        int imap = s[i] - 'a';
        if (cur->nxt[imap] == NULL)
            return false;
        cur = cur->nxt[imap];
    }
    return cur->is_end;
}

int32_t main()
{
    IOS();

    root = new node();

    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        insert_trie(s);
    }

    cin >> str;

    if (search_trie(str))
    {
        cout << "Found";
    }
    else
    {
        cout << "Not Found";
    }

    return 0;
}