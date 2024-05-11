#include <bits/stdc++.h>
using namespace std;

int main()
{

    while (1)
    {
        int n;
        cin >> n;
        if (n == 0)
            break;

        vector<int> a(n);

        for (int i = 0; i < n; i++)
            cin >> a[i];

        int cur = 1;

        vector<int> b;

        for (int i = 0; i < n; i++)
        {

            while (!b.empty() && b.back() == cur)
                cur++, b.pop_back();

            if (a[i] == cur)
            {
                cur++;
            }
            else
            {
                b.push_back(a[i]);
            }
        }

        while (!b.empty() && b.back() == cur)
            cur++, b.pop_back();

        if (cur == n + 1)
            cout << "yes\n";
        else
            cout << "no\n";
    }
}
// n => 2(n+n-1+..1) + n-1+..1 => n*(n+1) + n*(n-1)/2 =>n*(n+1 + (n-1)/2)=>n*(3*n+1)/2