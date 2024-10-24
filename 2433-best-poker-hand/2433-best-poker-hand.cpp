class Solution {
public:
    string bestHand(vector<int>& ranks, vector<char>& suits) {
        unordered_map<int,int>mp1;
        unordered_map<char,int>mp2;
        for(int i=0;i<ranks.size();i++)
        {
            mp1[ranks[i]]++;
        }
        for(int i=0;i<suits.size();i++)
        {
            mp2[suits[i]]++;
        }
        if(mp2.size()==1)
        {
            return "Flush";
        }
        vector<int>ans;
         for(auto it:mp1)
         {
            ans.push_back(it.second);
         }
        sort(ans.begin(),ans.end(),greater<int>());
        for(int i=0;i<ans.size();i++)
        {
            if(ans[i]>=3)
            {
                return "Three of a Kind";
            }
            else if(ans[i]==2)
            {
                return "Pair";
            }
        }
        return "High Card";

    }
};