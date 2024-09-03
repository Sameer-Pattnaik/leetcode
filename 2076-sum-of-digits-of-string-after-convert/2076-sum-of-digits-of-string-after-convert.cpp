class Solution {
private:
    int transform(int t){
        int res = 0;
        while(t>0){
            res += t%10;
            t/=10;
        }
        return res;
    }
public:
    int getLucky(string s, int k) {
        int res = 0;
        for(char ch : s){
            int num = ch-'a'+1;
            if(num >= 10) res += num%10 + num/10;
            else res += num;
        } 
        while(--k>0)
            res = transform(res);

        return res;
    }
};