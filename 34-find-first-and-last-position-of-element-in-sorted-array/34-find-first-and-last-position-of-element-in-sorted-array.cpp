class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();
        
        // // using stl lower bound upper bound
        // int first = lower_bound(nums.begin(), nums.end(), target) - nums.begin();
        // if(first==n || nums[first]!=target) return {-1,-1};
        // int last = upper_bound(nums.begin(), nums.end(),target) - nums.begin();
        // return {first,last-1};
        
        int first = -1;
        int low = 0, high = n-1;
        while(low<=high)
        {
            int mid = low + (high - low)/2;
            if(nums[mid]>target) high = mid-1;
            else if(nums[mid]<target) low = mid+1;
            else
            {
                first= mid;
                high = mid-1;
            }
        }
        if(first == -1) return {-1,-1};
        low = 0; high = n-1;
        int last = -1;
        while(low<=high)
        {
            int mid = low + (high - low)/2;
            if(nums[mid]>target) high = mid-1;
            else if(nums[mid]<target) low = mid+1;
            else
            {
                last= mid;
                low = mid + 1;
            }
        }
        return {first,last};
    }
};