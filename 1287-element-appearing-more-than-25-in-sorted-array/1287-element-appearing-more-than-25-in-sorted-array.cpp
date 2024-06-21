class Solution {
public:
    int findSpecialInteger(vector<int>& arr) {
        map<int,double>mp;
        for(int i=0;i<arr.size();i++)
        {
            mp[arr[i]]++;
        }
        for(auto it:mp)
        {
            if((it.second/arr.size())>0.25)
            {
                return it.first;
            }
        }
        return -1;
    }
};