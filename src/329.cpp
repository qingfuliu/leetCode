#include <vector>
using namespace std;
class Solution
{
    vector<vector<int>> pos = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    int rows;
    int cols;

public:
    int longestIncresasingPath(vector<vector<int>> &matrix)
    {
        return method_dfs(matrix);
    }

private:
    int method_dp(vector<vector<int>> &matrix) noexcept
    {
        
    }
    int method_dfs(vector<vector<int>> &matrix) noexcept
    {
        rows = matrix.size();
        cols = matrix[0].size();
        vector<vector<int>> mem(rows, vector<int>(cols, 0));
        int ans = 0;
        for (int i = 0; i < rows; ++i)
        {
            for (int j = 0; i < cols; ++j)
            {
                ans = std::max(ans, method_dfs(matrix, i, j, mem));
            }
        }
        return ans;
    }
    int method_dfs(const vector<vector<int>> &matrix, int i, int j, vector<vector<int>> &mem)
    {
        if (mem[i][j] == 0)
        {
            return mem[i][j];
        }
        mem[i][j] = 1;
        for (const auto &p : pos)
        {
            int cur_row = i + p[0];
            int cur_col = j + p[1];
            if (cur_col >= 0 && cur_col < cols && cur_row >= 0 && cur_row < rows && matrix[i][j] < matrix[cur_row][cur_col])
            {
                mem[i][j] = std::max(mem[i][j], method_dfs(matrix, cur_row, cur_col, mem));
            }
        }
        return mem[i][j];
    }
};