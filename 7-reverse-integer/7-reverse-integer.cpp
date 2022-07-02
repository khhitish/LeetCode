class Solution {
public:
    int reverse(int x) {
        bool isnegative=false;
        int ans=0;
        while(x!=0)
        {
            int digit= x%10;
            cout<<digit<<" ";
            if(ans > INT_MAX/10 || (ans==INT_MAX/10 && digit > INT_MAX%10)
              || ans < INT_MIN/10 || (ans==INT_MIN/10 && digit < INT_MIN%10)) return 0;
            ans=ans*10 + digit;
            x/=10;
        }
        return ans;
    }
};