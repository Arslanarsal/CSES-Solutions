#include <bits/stdc++.h>
using namespace std;

struct DSU
{
    vector<int> parent, size;
    DSU(int n)
    {
        parent.resize(n + 1);
        size.resize(n + 1, 1);
        iota(parent.begin(), parent.end(), 0);
    }
    int find(int x)
    {
        if (x != parent[x])
            parent[x] = find(parent[x]);
        return parent[x];
    }
    long long unite(int x, int y)
    {
        x = find(x);
        y = find(y);
        if (x == y)
            return 0;
        long long pairs = 1LL * size[x] * size[y];
        if (size[x] < size[y])
            swap(x, y);
        parent[y] = x;
        size[x] += size[y];
        return pairs;
    }
};

int main()
{
    int n;
    cin >> n;
    vector<tuple<int, int, int>> edges;
    int a, b, w;
    for (int i = 0; i < n - 1; i++)
    {
        cin >> a >> b >> w;
        edges.push_back({a, b, w});
    }
    sort(edges.begin(), edges.end(), [](auto &a, auto &b)
         { return get<2>(a) < get<2>(b); });

    DSU dsu(n);
    long long result = 0;

    for (auto &it : edges)
    {
        int u, v, w;
        u = get<0>(it);
        v = get<1>(it);
        w = get<2>(it);
        long long pairs = dsu.unite(u, v);
        result += pairs * w;
    }

    cout << result << "\n";
}
