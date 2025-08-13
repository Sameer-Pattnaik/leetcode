class Solution {
public:
    bool isPowerOfThree(int n) {
        if(n==0)
        {
            return false;
        }
        if(n==1)
        {
            return true;
        }
        while(n)
        {
            if(n%3!=0)
            {
                return false;
            }
            
            n=n/3;
            if(n==1)
            {
                break;
            }
        }
        return true;
    }
};