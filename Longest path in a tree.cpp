#include <bits/stdc++.h>
using namespace std;

int main()
{

    int n;
    cin >> n;

    vector<vector<int>> g(n + 1);

    for (int i = 0; i < n - 1; i++)
    {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    vector<int> depth(n + 1);

    function<void(int, int, int)> dfs = [&](int u, int p, int d)
    {
        depth[u] = d;

        for (auto v : g[u])
        {
            if (v == p)
                continue;

            dfs(v, u, d + 1);
        }
    };

    dfs(1, 0, 0);

    int u = 0;
    int mx = -1;

    for (int i = 1; i <= n; i++)
    {
        if (depth[i] > mx)
        {
            mx = depth[i];
            u = i;
        }
    }

    for (int i = 1; i <= n; i++)
        depth[i] = 0;

    dfs(u, 0, 0);

    cout << *max_element(depth.begin(), depth.end());
}