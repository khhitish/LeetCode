class Solution
{
    public:
        int countSquares(vector<vector < int>> &matrix)
        {
            int m = matrix.size(), n = matrix[0].size();
           	// tabulation
            vector<vector < int>> dp(m, vector<int> (n));
            int ans = 0;
            for (int i = 0; i < m; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    if (i == 0 || j == 0 || matrix[i][j] == 0)
                    {
                        dp[i][j] = matrix[i][j];
                    }
                    else
                    {
                        dp[i][j] = min(dp[i - 1][j], min(dp[i - 1][j - 1], dp[i][j - 1])) + 1;
                    }
                    ans += dp[i][j];
                }
            }
            return ans;
        }
};