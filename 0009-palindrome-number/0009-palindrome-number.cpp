class Solution {
public:
    bool isPalindrome(int x) {
    long int num=x;
    long int ans=0;
    int rem=0;
    while(x)
    {
        if(x<0)
        {
            x=x*0;
        }
        rem=x%10;
        ans=ans*10+rem;
        x=x/10;
    }
if(num==ans)
{

    return true;
}
else
{
    return false;
}
    }
};