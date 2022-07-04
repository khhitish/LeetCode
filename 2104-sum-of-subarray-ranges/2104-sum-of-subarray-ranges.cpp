class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
        long long ans=0;
        int n=nums.size();
        for(int i=0;i<n;i++)
        {
            int maxi=nums[i], mini=nums[i];
            for(int j=i+1;j<n;j++)
            {
                maxi=max(maxi,nums[j]);
                mini=min(mini,nums[j]);
                ans+=(maxi-mini);
            }
        }
        return ans;
    }
};