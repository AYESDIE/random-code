#include <vector>
#include <iostream>
#define inf 10000000

using namespace std;

void matmx(const vector<int>& p,
           vector<vector<int>>& m,
           vector<vector<int>>& s){
  // allocate size
  m.clear();
  s.clear();

  // refresh
  vector<int> temp(p.size());
  fill(temp.begin(), temp.end(), 0);
  for (int n = 0; n < p.size() + 1; ++n) {
    m.push_back(temp);
    s.push_back(temp);
  }

  for (int l = 2; l < p.size(); ++l) {
    for (int i = 1; i < p.size() - l + 1; ++i) {
      int j = i + l - 1;
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

int main()
{
  vector<int> p({30, 35, 15, 5, 10, 20, 25});
  vector<vector<int>> m,s;
  matmx(p,m,s);

  for (int i = 0; i < m.size(); ++i) {
    for (int j = 0; j < m[0].size(); ++j) {
      cout<< m[i][j] << " , ";
    }
    cout << "\n";
  }



  return 0;
}