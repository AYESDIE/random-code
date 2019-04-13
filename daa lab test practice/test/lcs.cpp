#include <iostream>
#include <vector>

using namespace std;

int main()
{
  string a = "abcdaf";
  string b = "abcbf";
  string c ="";


  vector<int> temp(a.size() + 1);
  vector<vector<int>> DP(b.size() + 1);
  fill(temp.begin(), temp.end(), 0);
  fill(DP.begin(), DP.end(), temp);

  for (int i = 0; i < a.size(); ++i) {
    for (int j = 0; j < b.size(); ++j) {
      if (a[i]==b[j])
        DP[j+1][i+1] = DP[j][i] + 1;
      else
        DP[j+1][i+1] = (DP[j+1][i] > DP[j][i+1])?
                       DP[j+1][i] : DP[j][i+1];

    }
  }

  for (int k = 0; k < DP.size(); ++k) {
    for (int i = 0; i < DP[0].size() ; ++i) {
      cout << DP[k][i] << " ";
    }
    cout << "\n";
  }

  int i = a.size();
  int j = b.size();
  return 0;
}