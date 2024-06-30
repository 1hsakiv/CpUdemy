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

struct segmentTree
{
    vi st;
    int n;

    void init(int n)
    {
        this->n = n;
        st.resize(4 * n, 0);
    }

    void build(int start, int ending, int node, vi &v)
    {

        if (start == ending)
        {
            st[node] = v[start];
            return;
        }

        int mid = (start + ending) / 2;

        // left subtree is (start, mid)
        build(start, mid, 2 * node + 1, v);

        // right subtree is (mid+1 , ending)
        build(mid + 1, ending, 2 * node + 2, v);

        // do the operation like sum , min xor etc
        st[node] = st[2 * node + 1] + st[2 * node + 2];
    }

    void build(vi &v)
    {
        build(0, v.size() - 1, 0, v);
    }

    int query(int start, int ending, int l, int r, int node)
    {
        // non overlapping case
        if (start > r || ending < l)
        {
            return 0;
        }

        // complete overlapcase
        if (start >= l && ending <= r)
        {
            return st[node];
        }

        // partial overlap conditions
        int mid = (start + ending) / 2;
        int left = query(start, mid, l, r, 2 * node + 1);
        int right = query(mid + 1, ending, l, r, 2 * node + 2);
        return left + right;
    }

    int query(int l, int r)
    {
        return query(0, n - 1, l, r, 0);
    }

    void update(int start, int ending, int node, int index, int value)
    {
        // base case -> leaf node
        if (start == ending)
        {
            st[node] = value;
            return;
        }

        int mid = (start + ending) / 2;
        if (index <= mid)
        {
            // go to left subtree
            update(start, mid, 2 * node + 1, index, value);
        }
        else
        {
            // go to right subtree
            update(mid + 1, ending, 2 * node + 2, index, value);
        }

        st[node] = st[2 * node + 1] + st[2 * node + 2];
    }

    void update(int x, int y)
    {
        update(0, n - 1, 0, x, y);
    }
};

int32_t main()
{
    IOS();
    vi v = {1, 2, 3, 4, 5, 6, 7, 80};
    segmentTree tree;
    tree.init(v.size());
    tree.build(v);
    cout << tree.query(0, 7) << endl;
    tree.update(7, 8);
    cout << tree.query(0, 7) << endl;
    return 0;
}