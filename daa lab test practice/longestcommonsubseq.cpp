#include <iostream>
#include <vector>
#include <string>
#include <algorithm>


using namespace std;

int main()
{
  string a,b,ans;
  a = "abcdaf";
  b = "abcaf";
  ans = "";

  vector<vector<int>> DP(b.size() + 1);
  vector<int> temp(a.size() + 1);

  // initialize DP
  fill(temp.begin(), temp.end(), 0);
  fill(DP.begin(), DP.end(), temp);

  for (int i = 0; i < b.size(); ++i) {
    for (int j = 0; j < a.size() ; ++j) {
      if (a[j] == b[i])
        DP[i+1][j+1] = DP[i][j] + 1;
      else
        DP[i+1][j+1] = (DP[i+1][j] > DP[i][j+1]) ?
                        DP[i+1][j] : DP[i][j+1];
    }
  }

  for (int k = 0; k < DP.size(); ++k) {
    for (int i = 0; i < DP[0].size() ; ++i) {
      cout << DP[k][i] << " ";
    }
    cout << "\n";
  }

  int i = DP.size() - 1;
  int j = DP[0].size() - 1;
  int traverser;
  while (DP[i][j]!=0)
  {
    if(DP[i-1][j] == DP[i][j])
      i--;
    else if(DP[i][j-1]==DP[i][j])
      j--;
    else
    {
      ans += b[i - 1];
      i--;
      j--;
    }
  }

  reverse(ans.begin(), ans.end());
  cout << ans;

  return 0;
}

