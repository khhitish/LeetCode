class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        stack<int> s;
        int n=nums.size();
        vector<int> ans(n);
        for(int cnt=0;cnt<=1;cnt++)
        {
            for(int i=n-1;i>=0;i--)
            {
                while(!s.empty() && nums[i]>=s.top()) s.pop();
                if(s.empty()) ans[i]=-1;
                else ans[i]=s.top();
                s.push(nums[i]);
            }
        }
        return ans;
    }
};