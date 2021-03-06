class Solution
{
    private:
        bool ispalindrome(string &s, int i, int j)
        {
            while (i < j)
            {
                if (s[i] == s[j])
                {
                    i++;
                    j--;
                }
                else return false;
            }
            return true;
        }
    int helper(int i, string &s, vector<int> &dp)
    {
        int n = s.size();
        if (i >= n) return 0;
        if (dp[i] != -1) return dp[i];
        int ans = 1e9;
        for (int j = i; j < n; j++)
        {
            if (ispalindrome(s, i, j) == true)
            {
                ans = min(ans, 1 + helper(j + 1, s, dp));
            }
        }
        return dp[i] = ans;
    }
    public:
        int minCut(string s)
        {
            int n = s.size();

           	// memoization
           	// vector<int> dp(n, -1);
           	// return helper(0, s, dp) - 1;

           	// tabulation
            vector<int> dp(n + 1, 0);
            dp[n] = 0;	// base case
            for (int i = n - 1; i >= 0; i--)
            {
                int ans = 1e9;
                for (int j = i; j < n; j++)
                {
                    if (ispalindrome(s, i, j) == true)
                    {
                        ans = min(ans, 1 + dp[j + 1]);
                    }
                }
                dp[i] = ans;
            }
            return dp[0] - 1;
        }
};