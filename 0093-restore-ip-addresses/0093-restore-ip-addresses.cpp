class Solution {
public:
    bool checkValid(string str)
    {
        int n=str.length();
        if(n==1)
        {
            return true;
        }
        if(n>3 || str[0]=='0')
        {
            return false;
        }
        int value=stoi(str);
        if(value>255)
        {
            return false;
        }
        return true;
    }
    vector<string> restoreIpAddresses(string s) {
     vector<string>res;
     int n=s.length();
     if(n<4 && n>12)
     {
        return res;
     }   
     for(int i=1;i<=3;i++)
     {
        for(int j=1;j<=3;j++)
        {
            for(int k=1;k<=3;k++)
            {
                if(i+j+k<n && i+j+k>=n-3)
                {
                    string str1=s.substr(0,i);
                    string str2=s.substr(i,j);
                    string str3=s.substr(i+j,k);
                    string str4=s.substr(i+j+k);
                    if(checkValid(str1) && checkValid(str2) && checkValid(str3) && checkValid(str4))
                    {
                        res.push_back(str1+"."+str2+"."+str3+"."+str4);
                    }
                }
            }
        }
     }
     return res;
    }
};