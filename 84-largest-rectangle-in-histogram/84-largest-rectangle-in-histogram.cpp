class Solution {
public:
    int largestRectangleArea(vector<int>& h) {
        stack<int> s;
        int ans=0, n=h.size();
        for(int i=0;i<n;i++)
        {
            while(!s.empty() && h[s.top()]>=h[i])
            {
                int j=s.top();s.pop();
                int k = s.empty() ? -1 : s.top();
                int temp = h[j]*(i-k-1);
                ans=max(ans,temp);
            }
            s.push(i);
        }
        while(!s.empty())
        {
            int j=s.top();s.pop();
            int k = s.empty() ? -1 : s.top();
            int temp = h[j]*(n-k-1);
            ans=max(ans,temp);
        }
        return ans;
    }
};