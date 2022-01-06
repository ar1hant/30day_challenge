#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
  int maxProfit(int k, int n, int a[]){
    vector<vector<int>> dp(k + 1);
    int mx, x;
    for (int i = 0; i <= k; i++)
      dp[i].push_back(0);
    for (int j = 0; j < n; j++)
      dp[0].push_back(0);
    for (int i = 1; i <= k; i++){
      mx = INT_MIN;
      for (int j = 1; j < n; j++){
        mx = max(mx, dp[i - 1][j - 1] - a[j - 1]);
        dp[i].push_back(max(dp[i][j - 1], mx + a[j]));
      }
    }
    return dp[k][n - 1];
  }
};

// Time compleity of this program O(n * k)
// Extra Space compleity of this program O(n * k)

int main()
{
  int t;
  cin >> t;
  while (t--)
  {
    int N, K;
    cin >> K;
    cin >> N;
    int A[N];
    for (int i = 0; i < N; i++)
      cin >> A[i];

    Solution ob;
    cout << ob.maxProfit(K, N, A) << endl;
  }
  return 0;
}