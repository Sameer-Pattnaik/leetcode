class Solution {
public:
    string mostCommonWord(string paragraph, vector<string>& banned) 
    {
        for(auto &ch:paragraph)
        {
            if(!isalpha(ch)) ch = ' ';
            ch = tolower(ch);
        }
        map<string,int>mp, band;
        for(auto s:banned) band[s]++;

        string s, ans;
        stringstream ss(paragraph);
        while(ss>>s)
            if(band[s] == 0) mp[s]++;

        int mx = INT_MIN;
        for(auto [a, b]:mp)
            if(b > mx) ans = a, mx = b;
        return ans;
    }
};