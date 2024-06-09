class Solution {
public:
int number(char c)
{
    if(c=='I')
    {
        return 1;
    }
    else if(c=='V')
    {
        return 5;
    }
    else if(c=='X')
    {
        return 10;
    }
    else if(c=='L')
    {
        return 50;
    }
    else if(c=='C')
    {
        return 100;
    }
    else if(c=='D')
    {
        return 500;
    }
    else
    {
        return 1000;
    }
}
    int romanToInt(string s) {
       int sum=0;
       int i=0;
       while(i<s.length()-1)
       {
        if(number(s[i])<number(s[i+1]))
        {
            sum-=number(s[i]);
        }
        else
        {
            sum+=number(s[i]);
        }
        i++;
       } 
       sum+=number(s[s.length()-1]);
       return sum;
    }
};