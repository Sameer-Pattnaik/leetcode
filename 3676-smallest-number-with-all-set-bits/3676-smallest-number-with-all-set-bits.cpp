class Solution {
public:
    int smallestNumber(int n) {
        for(int i=0;i<n;i++)
        {
            if(pow(2,i)>n)
            {
                int ans=pow(2,i);
                return ans-1;
            }
        }
        return 1;
    }
};