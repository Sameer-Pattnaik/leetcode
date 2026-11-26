class Solution {
public:
    bool canAliceWin(int n) {
        int ans=n;
        int cnt=10;
        bool turn=false;
    
        while(ans>0){
            ans-=cnt;
            if(ans>=0){
            turn=!turn;
            }
            cnt--;
        }
        return turn;
    }
};