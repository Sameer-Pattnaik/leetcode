class Solution {
public:
    bool isPerfectSquare(int num) {
       map<long long,long long>mp;
        for(long long i=0;i*i<=num;i++)
        {
            mp[i*i*1ll]++;
        }
       
            if(mp[num])return true;
            return false;
    }
};