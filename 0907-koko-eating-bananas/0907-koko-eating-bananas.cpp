class Solution {
public:
    bool isPossible(vector<int>piles,int mid,int h)
    {
        long long hours=0;
        for(int i=0;i<piles.size();i++)
        {
            hours+=piles[i]/mid;
            piles[i]%=mid;
            if(piles[i]>0)
            {
                hours++;
            }
            if(hours>h)
            {
                return false;
            }
        }
        return true;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int maxi=INT_MIN;
        for(int i=0;i<piles.size();i++)
        {
       maxi=max(maxi,piles[i]);
        }
       int ans=0;
       
       int mini=1;
       while(mini<=maxi)
       {
        int mid=(mini+maxi)/2;
        if(isPossible(piles,mid,h))
        {
            ans=mid;
            maxi=mid-1;
        }
        else{
            mini=mid+1;
        }
       }
       return ans; 

    }
};