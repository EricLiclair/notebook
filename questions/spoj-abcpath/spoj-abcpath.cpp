#include <bits/stdc++.h>

#define vvi vector<vector<int>>
#define vvc vector<vector<char>>
typedef long long ll;
using namespace std;
struct Solution
{
  int h, w;

  // to check if the next element is valid or not
  bool is_valid(int i, int j, const vvi &is_visited, const vvc &matrix, const int &currentChar)
  {
    return ((i < h) && (i > 0) && (j < w) && (j > 0) && (matrix[i][j] == (currentChar + 1)));
  }

  // to get all the adjacent locations
  vvi get_adjacent(int i, int j)
  {
    return vvi{
        {i - 1, j - 1},
        {i, j - 1},
        {i, j + 1},
        {i - 1, j},
        {i + 1, j},
        {i - 1, j + 1},
        {i, j + 1},
        {i + 1, j + 1},
    };
  }

  // dfs
  void dfs(const vvc &matrix, vvi &is_visited, int i, int j, int &count)
  {
    is_visited[i][j] = 1;
    printf("%c %d%d -- ", matrix[i][j], i, j);
    count += 1;
    for (auto next : get_adjacent(i, j))
    {

      if (is_valid(next[0], next[1], is_visited, matrix, matrix[i][j]))
      {
        dfs(matrix, is_visited, next[0], next[1], count);
      }
    }
    return;
  }
};

int main()
{
  while (true)
  {
    int h, w;
    cin >> h >> w;
    if (!h && !w)
      break;

    // initialize the matrix
    vvc matrix(h, vector<char>(w, 0));
    for (int i = 0; i < h; i++)
    {
      for (int j = 0; j < w; j++)
      {
        cin >> matrix[i][j];
      }
    }

    // matrix to check if visited
    vvi is_visited(h, vector<int>(w, 0));

    int max_count = INT_MIN;

    for (int i = 0; i < h; i++)
    {
      for (int j = 0; j < w; j++)
      {
        // if does not start with A: skip
        if (!(matrix[i][j] == 'A'))
          continue;

        int count = 1;
        Solution s;
        s.h = h;
        s.w = w;
        s.dfs(matrix, is_visited, i, j, count);
        if (count > max_count)
        {
          max_count = count;
        }
      }
    }
    cout << "THE MAX COUNT IS " << max_count << endl;
  }
}
