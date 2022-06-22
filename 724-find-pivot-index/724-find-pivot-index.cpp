class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        int currsum=0;
        for(int i=0;i<nums.size();i++)
        {
            int prefsum=currsum;
            int suffsum= sum - currsum - nums[i];
            if(prefsum==suffsum) return i;
            currsum+=nums[i];
        }
        return -1;
    }
};