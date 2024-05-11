#include <bits/stdc++.h>
using namespace std;

int main()
{

    int tt;
    cin >> tt;

    while (tt--)
    {

        string s;
        cin >> s;

        int n = s.size();

        int p9 = 1;

        for (int i = 0; i < n; i++)
        {
            if (s[i] != '9')
            {
                p9 = 0;
                break;
            }
        }

        if (p9)
        {
            string ans;
            for (int i = 0; i <= n; i++)
                ans.push_back('0');
            ans[0] = '1';
            ans[n] = '1';

            cout << ans << "\n";
            continue;
        }

        if (n == 1)
        {
            cout << s[0] + 1 << "\n";
            continue;
        }

        if (n % 2)
        {

            auto t = s;
            for (int i = 0; i <= n / 2; i++)
            {
                t[n / 2 + i] = t[n / 2 - i];
            }

           

            if (t > s)
            {
                cout << t << "\n";
            }
            else
            {
                int l = n / 2;
                int r = n / 2;
                auto s = t;
                while (s[l] == '9')
                    s[l] = '0', s[r] = '0', l--, r++;
                s[l] += 1;
                if (l != r)
                    s[r] += 1;
                cout << s << "\n";
            }
        }
        else
        {

            auto t = s;
            for (int i = 0; i < n / 2; i++)
            {
                t[n / 2 + i] = t[n / 2 - 1 - i];
            }

            if (t > s)
            {
                cout << t << "\n";
            }
            else
            {
                int l = n / 2 - 1;
                int r = n / 2;

                auto s = t;

                while (s[l] == '9')
                    s[l] = '0', s[r] = '0', l--, r++;
                s[l] += 1;
                s[r] += 1;
                cout << s << "\n";
            }
        }
    }
}