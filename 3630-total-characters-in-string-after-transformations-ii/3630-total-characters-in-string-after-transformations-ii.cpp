class Solution 
{
    const int MOD = 1e9 + 7;
public:
    int lengthAfterTransformations(string s, int t, vector<int>& nums) 
    {
        int n = 26;
        vector<vector<long long>> T(n, vector<long long>(n, 0));
        for (int i = 0; i < n; ++i) 
        {
            int spread = nums[i];
            for (int j = 1; j <= spread; ++j) 
            {
                int next = (i + j) % 26;
                T[i][next] = (T[i][next] + 1) % MOD;
            }
        }
        vector<long long> freq(n, 0);
        for (char c : s)
        {
            freq[c - 'a']++;
        }
        auto T_pow = matrixPower(T, t);
        vector<long long> result(n, 0);
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                result[j] = (result[j] + freq[i] * T_pow[i][j]) % MOD;
            }
        }
        long long total = 0;
        for (long long val : result)
        {
            total = (total + val) % MOD;
        }
        
        return (int)total;
    }
private:
    vector<vector<long long>> matrixPower(vector<vector<long long>>& base, int exp) 
    {
        int n = base.size();
        vector<vector<long long>> result(n, vector<long long>(n, 0));
        for (int i = 0; i < n; ++i)
        {
            result[i][i] = 1;
        }

        while (exp > 0) 
        {
            if (exp & 1)
            {
                result = multiply(result, base);
            } 
            
            base = multiply(base, base);
            exp >>= 1;
        }

        return result;
    }

    vector<vector<long long>> multiply(vector<vector<long long>>& A, vector<vector<long long>>& B)
    {
        int n = A.size();
        vector<vector<long long>> res(n, vector<long long>(n, 0));
        for (int i = 0; i < n; ++i)
        {
            for (int k = 0; k < n; ++k)
            {
                if (A[i][k] != 0)
                {
                    for (int j = 0; j < n; ++j)
                    {
                        res[i][j] = (res[i][j] + A[i][k] * B[k][j]) % MOD;
                    }
                }
            }
        }
                
        return res;
    }
};