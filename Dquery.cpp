#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e5 + 1;

struct Query
{

    int l;
    int r;
    int idx;
};

int32_t
main()
{

    int n;
    cin >> n;

    vector<int> a(n);

    for (int i = 0; i < n; i++)
        cin >> a[i];

    int q;
    cin >> q;

    vector<Query> queries;

    for (int i = 0; i < q; i++)
    {
        int l, r;
        cin >> l >> r;
        l--, r--;

        Query q;
        q.l = l;
        q.r = r;
        q.idx = i;

        queries.push_back(q);
    }

    int K = ceil(sqrt(n));

    auto cmp = [&](Query a, Query b)
    {
        if (a.l / K == b.l / K)
            return a.r < b.r;
        else
            return a.l / K < b.l / K;
    };

    sort(queries.begin(), queries.end(), cmp);

    vector<int> cnt(1e6 + 1);

    int cur = 0;

    int l = queries[0].l, r = queries[0].r;

    auto Add = [&](int x)
    {
        cnt[x]++;
        if (cnt[x] == 1)
            cur++;
    };

    auto Subtract = [&](int x)
    {
        cnt[x]--;
        if (cnt[x] == 0)
            cur--;
    };

    for (int i = l; i <= r; i++)
    {
        Add(a[i]);
    }

    vector<int> ans(q);
    ans[queries[0].idx] = cur;

    for (int i = 1; i < q; i++)
    {

        int l1 = queries[i].l, r1 = queries[i].r;

        if (l1 < l)
        {
            while (l1 < l)
            {
                l--;
                Add(a[l]);
            }
        }
        else
        {
            while (l1 > l)
            {
                Subtract(a[l]);
                l++;
            }
        }

        if (r1 < r)
        {
            while (r1 < r)
            {
                Subtract(a[r]);
                r--;
            }
        }
        else
        {
            while (r1 > r)
            {
                r++;
                Add(a[r]);
            }
        }
        ans[queries[i].idx] = cur;
    }

    for (int i = 0; i < q; i++)
        cout << ans[i] << "\n";
}
