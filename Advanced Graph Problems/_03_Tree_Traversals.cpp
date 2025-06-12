#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'

vector<int> pre, in;
int a[100005];
int x = 0, n;
void post(int l = 0, int h = n - 1)
{
    if (l > h)
    {
        x--;
        return;
    }
    int i = a[pre[x]];
    ++x;
    post(l, i - 1);
    ++x;
    post(i + 1, h);
    cout << in[i] << ' ';
}
signed main()
{

    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        pre.push_back(x);
    }
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        in.push_back(x);
        a[x] = i;
    }
    post();
}