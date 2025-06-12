#include <bits/stdc++.h>
using namespace std;

int32_t main()
{
    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> adj;
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        if (a < b)
            adj.push_back({b, a});
        else
            adj.push_back({a, b});
    }
    for (auto &&it : adj)
        cout << it.first << " " << it.second << "\n";

    return 0;
}
