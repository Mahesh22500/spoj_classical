#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e5 + 1;

int32_t
main()
{

    int tt;
    cin >> tt;

    for (int t = 0; t < tt; t++)
    {

        int n;
        cin >> n;

        if (n == 0)
        {
            cout << "Case " << t + 1 << ":" << " ";
            cout << 0 << "\n";
            continue;
        }

        vector<int> a(n);

        for (int i = 0; i < n; i++)
            cin >> a[i];

        vector<vector<int>> dp(n, vector<int>(2));

        dp[0][0] = 0;
        dp[0][1] = a[0];

        for (int i = 1; i < n; i++)
        {
            dp[i][0] = max(dp[i - 1][0], dp[i - 1][1]);
            dp[i][1] = dp[i - 1][0] + a[i];
        }
        cout << "Case " << t + 1 << ":" << " ";
        cout << max(dp[n - 1][0], dp[n - 1][1]) << "\n";
    }
}