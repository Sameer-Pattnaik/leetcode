class Solution {
public:
    static const int mod=1e9+7;
    static int MSBF_pow(int nk, unsigned x){
        if (x==1) return nk;
        bitset<3> B(x);
        const int iN=31-countl_zero(x);
        long long y=nk;
        for(int i=iN-1; i>=0; i--){
            y=(y*y)*(B[i]?nk:1);
            if (y>=mod) y%mod;
        }
        return y;
    }

    static int numberOfWays(int n, int x) {
        vector<int> A;
        for(int nk=1; ; nk++){
            const int y=MSBF_pow(nk, x);
            if(y>n) break;
            A.push_back(y);
        }
        vector<int> dp(n+1, 0);
        dp[0]=1;
        for(int y: A){
            for(int sum=n; sum>=y; sum--){
                dp[sum]+=dp[sum-y];
                if (dp[sum]>=mod) dp[sum]-=mod;
            }
        }
        return dp[n];
    }
};