class Solution {
public:
    string compressedString(string word) {
        int count=1;
        string ans="";
        for(int i=0;i<word.length();i++)
        {
            if(word[i]!=word[i+1])
            {
                ans+=to_string(count);
                ans+=word[i];
                count=1;
            }
            else if(count>=9)
            {
                ans+=to_string(count);
                ans+=word[i];
                count=1;
            }
            else
            {
                count++;
            }
        }
        return ans;
    }
};