class Solution {
public:
    int countPoints(string rings) {
        unordered_map<char,unordered_set<char>>hm;
        for(int i=0;i<rings.length()-1;i+=2){
            char ring=rings[i];
            char rod=rings[i+1];
            hm[rod].insert(ring);
        }
        int cnt=0;
        for(auto it:hm){
            if(it.second.size()==3){
                cnt++;
            }
        }
        return cnt;
    }
};