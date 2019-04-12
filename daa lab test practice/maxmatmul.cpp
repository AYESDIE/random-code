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
  vector<int> temp(n - 1);


  // Refresh values
  fill(temp.begin(), temp.end(), 0);

  m.clear();
  s.clear();
  for (int l = 0; l < n; ++l)
  {
    m.push_back(temp);
    s.push_back(temp);
  }

  int cn = 1;
  for (int l = 1; l < n; ++l) {
    for (int i = l; i < n-1; ++i) {

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
    printmat(s, i, s[i][j]);
    printmat(s, s[i][j] + 1, j);
    cout << ")";
  }

}

int main()
{
  vector<int> p({1, 2, 3, 4});
  vector<vector<int>> m,s;
  maxmatmul(p,m,s);

  for (int i = 0; i < m.size(); ++i) {
    for (int j = 0; j < m[0].size(); ++j) {
      cout<< m[i][j] << " , ";
    }
    cout << "\n";
  }

  return 0;
}