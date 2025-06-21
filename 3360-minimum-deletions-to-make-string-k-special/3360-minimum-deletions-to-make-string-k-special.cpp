class Solution {
public:
    int minimumDeletions(string word, int k) {
        vector<int> v(26,0);
        for(auto& ch:word){
            v[ch - 'a']++;
        }

        sort(begin(v), end(v));

        int l=0;
        while(v[l]==0){l++;}

        int n=v.size();
        int ans = INT_MAX;
        for(int i=l;i<n;i++){
            int range = v[i] + k;

            int tot = v[i];
            for(int j=i+1;j<n;j++){
                if(v[j] > range){ tot += range; }
                else{
                    tot += v[j];
                }
            }

            int remain = word.size() - tot;
            ans = min(ans, remain);
        }

        return ans;
    }
};