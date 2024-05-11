#include <bits/stdc++.h>
using namespace std;

int main()
{

    auto solve = [&](string &s)
    {
        int n = s.size();

        vector<int> pi(n);
        pi[0] = 0;

        for (int i = 1; i < n; i++)
        {

            int j = pi[i - 1];

            while (j > 0 && s[i] != s[j])
            {
                j = pi[j - 1];
            }

            if (s[i] == s[j])
                j++;

            pi[i] = j;
        }

        return pi;
    };

    while (1)
    {

        int m = -1;
        cin >> m;

        if (m == -1)
            break;

        string sub;
        cin >> sub;

        string s;
        cin >> s;

        string S = sub + "#" + s;

    

        vector<int> p = solve(S);

        int n = S.size();

   

        vector<int> ans;

        for (int i = m + 1; i < n; i++)
        {
            if (p[i] == m)
            {
                ans.push_back(i - 2 * m);
            }
        }

        for (auto x : ans)
            cout << x << "\n";
        cout << "\n";
    }
}