#include <bits/stdc++.h>
using namespace std;

int main()
{

    int n, m;
    cin >> n >> m;

    vector<vector<int>> g(n + 1);

    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    int cnt = 0;
    vector<int> vis(n + 1);

    function<void(int)> dfs = [&](int u)
    {
        vis[u] = 1;

        for (auto v : g[u])
        {
            cnt++;
            if (!vis[v])
                dfs(v);
        }
    };

    int cc=0;

    for (int i = 1; i <= n; i++)
    {
        if (!vis[i])
            dfs(i),cc++;
    }

    if ((cnt / 2 == n - 1)  && (cc==1))
        cout << "YES\n";
    else
        cout << "NO\n";
}