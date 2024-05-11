#include <bits/stdc++.h>
using namespace std;
#define int long long 
const int N = 1e5 + 1;

int a[4*N+5];
struct T
{
    int sum;
    int prefix;
    int suffix;
    int subarray;
};

T st[4*N+5];

T combine(T &a, T &b)
{
    T res;
    res.prefix = max(a.prefix, a.sum + b.prefix);
    res.suffix = max(b.suffix, b.sum + a.suffix);
    res.sum = a.sum + b.sum;
    res.subarray = max(res.prefix, max(res.suffix, a.suffix + b.prefix));
    return res;
}

void build(int si, int l, int r)
{
    if (l == r)
    {

        T t;
        t.sum = a[l];
        t.prefix = a[l];
        t.suffix = a[l];
        t.subarray = a[l];
        st[si] = t;

        return;
    }

    int m = (l + r) / 2;

    build(2 * si + 1, l, m);
    build(2 * si + 2, m + 1, r);

    st[si] = combine(st[2 * si + 1], st[2 * si + 2]);
}

T query(int si, int l, int r, int ql, int qr)
{
    if (ql > r || qr < l)
    {
        T res;
        res.sum = 0;
        res.prefix = (long long)-1e12;
        res.suffix = (long long)-1e12;
        res.subarray = INT_MIN;
        return res;
    }

    if (ql <= l && qr >= r)
    {

        return st[si];
    }

    int m = (l + r) / 2;

    T left = query(2 * si + 1, l, m, ql, qr);
    T right = query(2 * si + 2, m + 1, r, ql, qr);

    T res = combine(left, right);
    return res;
}

int32_t main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        cin >> a[i];

    build(0, 0, n - 1);

    int m;
    cin >> m;

    while (m--)
    {

        int l, r;
        cin >> l >> r;
        l--, r--;

        T res = query(0, 0, n - 1, l, r);

        cout << res.subarray;
        cout << "\n";
    }
}