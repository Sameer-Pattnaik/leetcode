class Solution {
public:
    void lcs(string needle,vector<int>&lps)
    {
        int prefix=0;
        int suffix=1;
        while(suffix<needle.length())
        {
            if(needle[prefix]==needle[suffix])
            {
                lps[suffix]=prefix+1;
                prefix++;
                suffix++;
            }
            else
            {
                if(prefix==0)
                {
                    lps[suffix]=0;
                    suffix++;
                }
                else
                {
                    prefix=lps[prefix-1];
                }
            }
        }
    }
    int strStr(string haystack, string needle) {
       vector<int>lps(needle.length(),0);
       lcs(needle,lps);
       int first=0;
       int second=0;
       while(first<haystack.length() && second<needle.length())
       {
          if(haystack[first]==needle[second])
          {
            first++;
            second++;

          }
          else
          {
            if(second==0)
            {
                first++;
            }
            else
            {
                second=lps[second-1];
            }
          }

       }
       if(second==needle.length())
       {
        return (first-second);
       }
       return -1;
    }
};