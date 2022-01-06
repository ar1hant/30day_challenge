#include<bits/stdc++.h>

using namespace std;

int longestMountain(int a[], int n)
{
  int c = 0;
  int ans = 0;
  for (int i = 1; i < n;)
  {
    if (a[i] == a[i - 1])
    {
      while (i < n && a[i] == a[i - 1])
      {
        c = 0;
        i++;
      }
    }
    else if (a[i] > a[i - 1])
      while (i < n && a[i] > a[i - 1])
        c++, i++;
    else if (c > 0)
    {
      while (i < n && a[i] < a[i - 1])
        c++, i++;
      ans = max(ans, c + 1);
      c = 0;
    }
    else
      i++;
  }
  return ans;
}

// Time compleity of this program O(n )
// Extra Space compleity of this program O(1)

int main(){
  int n;
  cin >> n;
  int a[n];
  for(int i = 0;i < n;i++)
    cin >> a[i];
  cout << longestMountain(a, n);
  return 0;
}