#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, x;
    cin >> n >> x;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    

    vector<int> dp(x + 1, 0);
    dp[0] = 1;
    int mod = 1e9 + 7;
    for (int i = 1; i <= x; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i >= arr[j])
            {
                dp[i] = (dp[i] + 0LL + dp[i - arr[j]]) % mod;
            }
        }
    }
    cout << dp[x] << "\n";

    return 0;
}
