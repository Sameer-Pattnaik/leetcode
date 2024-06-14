class Solution {
public:
    int reverse(int x) {
        int rem=0;
        int ans=0;
        
        while(x)
        {
            if(ans>INT_MAX/10 || ans<INT_MIN/10)
        {
            return 0;
        }
            rem=x%10;
            ans=ans*10+rem;
            x=x/10;
        }
        
        return ans;
    }
};