#include <iostream>
#include <vector>
#define inf 1000000000

using namespace std;

void maxmatmul(const vector<int>& p,
               vector<vector<int>>& m,
               vector<vector<int>>& s)
{
  int n = p.size();

  // Placeholders
  vector<int> temp(n);


  // Refresh values
  fill(temp.begin(), temp.end(), 0);

  m.clear();
  s.clear();
  for (int l = 0; l < n; ++l)
  {
    m.push_back(temp);
    s.push_back(temp);
  }

  for (int l = 2; l < n ; ++l) {
    for (int i = 0; i < n-l+1; ++i) {
      int j = i+l-1;
      m[i][j] = inf;
      for (int k = i; k < j; ++k) {
        int q = m[i][k] + m[k+1][j] + p[i-1]*p[k]*p[j];
        if (q < m[i][j])
        {
          m[i][j] = q;
          s[i][j] = k;
        }
      }
    }
  }

}

void printmat(const vector<vector<int>>& s,
              int i,
              int j)
{
  if(i==j)
    cout << i;
  else
  {
    cout << "(";
    printmat(s, i, s[i + 1][j]);
    printmat(s, s[i + 1][j] + 1, j);
    cout << ")";
  }

}

int main()
{
  vector<int> p({30, 35, 15, 5, 10, 20, 25});
  vector<vector<int>> m,s;
  maxmatmul(p,m,s);

  for (int i = 0; i < m.size(); ++i) {
    for (int j = 0; j < m[0].size(); ++j) {
      cout<< s[i][j] << " , ";
    }
    cout << "\n";
  }



  return 0;
}