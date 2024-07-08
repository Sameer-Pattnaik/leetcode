class Solution {
public:
    int passThePillow(int n, int time) {
        int ans=time/(n-1);
        if(ans%2==0)
        {
            return 1+(time%(n-1));
        }
    
            return (n-(time%(n-1)));
        
    }
};