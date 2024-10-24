class Solution {
public:
    int countWords(vector<string>& words1, vector<string>& words2) {
        map<string,int>mp1;
        map<string,int>mp2;
        for(int i=0;i<words1.size();i++)
        {
            mp1[words1[i]]++;
        }
        for(int i=0;i<words2.size();i++)
        {
            mp2[words2[i]]++;
        }
        set<string>st;
        for(int i=0;i<words1.size();i++)
        {
            st.insert(words1[i]);
        }
        for(int i=0;i<words2.size();i++)
        {
            st.insert(words2[i]);
        }
        vector<string>ans;
        for(auto it:st)
        {
            ans.push_back(it);
        }
        int count=0;
        for(int i=0;i<ans.size();i++)
        {
            if(mp1[ans[i]]==1 && mp2[ans[i]]==1)
            {
                count++;
            }
        }
        return count;
    }
};