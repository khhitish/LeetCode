class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int i=0,j=0, n=nums.size();
        int ans=0;
        int freq0=0;
        while(j<n)
        {
            if(nums[j]==0)
            {
                freq0++;
            }
            while(freq0>k)
            {
                if(nums[i]==0)freq0--;
                i++;
            }
            ans=max(ans,j-i+1);
            j++;
        }
        return ans;
    }
};