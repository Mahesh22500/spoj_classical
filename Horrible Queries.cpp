#include <bits/stdc++.h>
using namespace std;
#define int long long

int32_t main()
{

    int tt;
    cin >> tt;

    while (tt--)
    {
        int n, q;
        cin >> n >> q;

        vector<int> st(4 * n + 5), lazy(4 * n + 5);

        function<void(int, int, int, int, int, int)> update = [&](int si, int l, int r, int ql, int qr, int x)
        {
            if (lazy[si])
            {

                st[si] += lazy[si] * (r - l + 1);
                if (l != r)
                {
                    lazy[2 * si + 1] += lazy[si];
                    lazy[2 * si + 2] += lazy[si];
                }
                lazy[si] = 0;
            }

            if (ql > r || qr < l)
                return;

            if (l >= ql && r <= qr)
            {

                st[si] += x * (r - l + 1);
                if (l != r)
                {
                    lazy[2 * si + 1] += x;
                    lazy[2 * si + 2] += x;
                }
                return;
            }

            int m = (l + r) / 2;

            update(2 * si + 1, l, m, ql, qr, x);
            update(2 * si + 2, m + 1, r, ql, qr, x);

            st[si] = st[2 * si + 1] + st[2 * si + 2];
        };

        function<int(int, int, int, int, int)> query = [&](int si, int l, int r, int ql, int qr)
        {
            if (lazy[si])
            {

                st[si] += lazy[si] * (r - l + 1);

                if (l != r)
                {
                    lazy[2 * si + 1] += lazy[si];
                    lazy[2 * si + 2] += lazy[si];
                }
                lazy[si] = 0;
            }

            if (l > qr || r < ql)
                return 0LL;

            if (l >= ql && r <= qr)
                return st[si];

            int m = (l + r) / 2;

            int left = query(2 * si + 1, l, m, ql, qr);
            int right = query(2 * si + 2, m + 1, r, ql, qr);

            return left + right;
        };

        while (q--)
        {

            int c;
            cin >> c;

            if (c == 0)
            {

                int l, r, x;
                cin >> l >> r >> x;
                l--, r--;
                update(0, 0, n - 1, l, r, x);
            }
            else
            {

                int l, r;
                cin >> l >> r;
                l--, r--;
                int ans = query(0, 0, n - 1, l, r);
                cout << ans << "\n";
            }
        }
    }
}