class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        map<int,int>change;
        for(int i=0;i<bills.size();i++)
        {
            change[bills[i]]++;
            if(bills[i]==10)
            {
                if(change[5]>0)
                {
                change[5]--;
                }
                else
                {
                    return false;
                }
            }
            else if(bills[i]==20)
            {
                if(change[10]>=1 && change[5]>=1)
                {
                change[10]--;
                change[5]--;
                }
                else if(change[5]>=3)
                {
                    change[5]--;
                    change[5]--;
                    change[5]--;
                }
                else
                {
                    return false;
                }
            }
        }
        return true;
    }
};