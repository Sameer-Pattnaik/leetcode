class Solution {
public:
    int longestPalindrome(string s) {
        int count=0;
        int odd=0;
        vector<int>lowercase(26,0);
        vector<int>uppercase(26,0);
        for(int i=0;i<s.length();i++)
        {
            if(s[i]>='a')
            {
                lowercase[s[i]-'a']++;
            }
            else
            {
                uppercase[s[i]-'A']++;
            }
        }
        for(int i=0;i<26;i++)
        {
            if(lowercase[i]%2==0)
            {
                count+=lowercase[i];
            }
            else
            {
                odd=1;
                count+=lowercase[i]-1;
            }
            if(uppercase[i]%2==0)
            {
                count+=uppercase[i];
            }
            else
            {
                odd=1;
                count+=uppercase[i]-1;
            }
        }
        return count+odd;
    }
};