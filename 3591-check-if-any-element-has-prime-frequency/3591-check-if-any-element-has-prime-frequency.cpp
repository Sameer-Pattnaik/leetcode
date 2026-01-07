class Solution {
public:
    bool isPrime(int n){
        int count=0;
        int i=2;
        while(i<=n){
           if(n%i==0){
            count++;
           }
           i++;
        }
        if(count==1){
           return true;
        }
        return false;
    }
    bool checkPrimeFrequency(vector<int>& nums) {
        map<int,int>mp;
        for(int i=0;i<nums.size();i++){
            mp[nums[i]]++;
        }
        for(int i=0;i<mp.size();i++){
            if(isPrime(mp[i])){
                return true;
            }
        }
        return false;
    }
};