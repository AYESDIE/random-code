#include <iostream>
#include <vector>

using namespace std;

inline int max(int a, int b) {
  return (a > b)? a : b;
}

int main()
{
  vector<int> wt({10, 20, 30});
  vector<int> val({60, 100, 120});

  int totalwt = 50;

  vector<vector<int>> DP(val.size() + 1);
  vector<int> placeholder(totalwt + 1);
  fill(placeholder.begin(), placeholder.end(), 0);
  fill(DP.begin(), DP.end(), placeholder);

  for (int i = 0; i < DP.size(); ++i)
  {
    for (int w = 0; w < totalwt + 1; ++w)
    {
      if(i==0 || w==0)
        DP[i][w] = 0;
      else if(wt[i - 1] <= w){
        cout << max(val[i - 1] + DP[i - 1][w - wt[i - 1]], DP[i-1][w]) <<"\n";
        DP[i][w] = max(val[i - 1] + DP[i - 1][w - wt[i - 1]], DP[i-1][w]);
      }
      else
        DP[i][w] = DP[i-1][w];
    }
  }

  for (int i = 0; i < DP.size(); ++i) {
    for (int j = 0; j < DP[0].size(); ++j) {
      cout << DP[i][j] << " ";
    }
    cout << "\n";
  }

  return 0;
}