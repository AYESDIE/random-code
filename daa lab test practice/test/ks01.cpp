#include <iostream>
#include <vector>

using namespace std;

int max(int a,int b){
  return (a>b)?a:b;
}

int main()
{
  vector<int> wt({10, 20, 30});
  vector<int> val({60, 100, 120});

  int totalwt = 50;

  vector<int> placeholder(totalwt+1);
  fill(placeholder.begin(), placeholder.end(), 0);
  vector<vector<int>> DP(wt.size()+1);
  fill(DP.begin(), DP.end(), placeholder);

  // DP[0-wt.size()][0-totalwt]
  for (int i = 1; i <= wt.size(); ++i) {
    for (int j = 1; j <= totalwt; ++j) {
      if(i==0 || j==0)
        DP[i][j] = 0;
      else if(wt[i-1]<=j)
        DP[i][j] = max(DP[i-1][j], val[i-1] + DP[i-1][j-wt[i-1]]);
      else
        DP[i][j] = DP[i-1][j];
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