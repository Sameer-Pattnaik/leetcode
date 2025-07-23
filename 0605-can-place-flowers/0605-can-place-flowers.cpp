class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int count = 0;
        int s = flowerbed.size();
        for(int i=0;i<s;i++){ 
            if(i==0){
                if(flowerbed[i]==0 && (i+1==s || flowerbed[i+1]==0)){
                    flowerbed[i]=1;
                    count++;
                }
            } else if(i==s-1){
                if(flowerbed[i]==0 && flowerbed[i-1]==0){
                    flowerbed[i]=1;
                    count++;
                }
            } else if(flowerbed[i-1]==0 && flowerbed[i+1]==0 && flowerbed[i]==0){
                flowerbed[i]=1;
                count++;
            }
        }
        if(count >= n) return true;
        return false;
    }
};