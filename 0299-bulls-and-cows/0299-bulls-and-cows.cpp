class Solution {
public:
    string getHint(string secret, string guess) {
        vector<int>ans1(10,0);
        vector<int>ans2(10,0);
        int n=secret.size();
        int bulls=0;
        int cows=0;
        for(int i=0;i<n;i++){
            if(secret[i]-'0'==guess[i]-'0'){
                bulls++;
            }
            else{
                ans1[secret[i]-'0']++;
                ans2[guess[i]-'0']++;
            }
        }
        for(int i=0;i<10;i++){
           cows+=min(ans1[i],ans2[i]);
        }
        return to_string(bulls) + "A" + to_string(cows) + "B";
    }
};