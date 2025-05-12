class Solution {
public:
    vector<int> findEvenNumbers(vector<int>& digits) {
        vector<int> freq(10, 0);
        for(int digit : digits) freq[digit]++;
        vector<int> ans;
        for(int i=1; i<10; i++) {
            if(freq[i] == 0) continue;
            int num = i;
            freq[i]--; 
            for(int j=0; j<10; j++) {
                if(freq[j] == 0) continue;
                freq[j]--; 
                for(int k=0; k<10; k+=2) {
                    if(freq[k] == 0) continue;
                    int newNum = (num*10 + j)*10 + k;
                    ans.push_back(newNum);
                }
                freq[j]++; 
            }
            freq[i]++; 
        }
        return ans;
    }
};