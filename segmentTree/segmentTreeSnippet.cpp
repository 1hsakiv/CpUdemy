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