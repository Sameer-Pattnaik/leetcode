class Solution {

private:
    void incr_bit_count(int bits[], int num){
        for(int i = 0; i< 31; i++){
            if(num & (1 << i)){
                bits[i]++;
            }
        }
    }
    int decr_bit_count(int bits[], int num, int orV){

        int temp = orV;
        for(int i = 0; i< 31; i++){
            if(num & (1 << i)){
                bits[i]--;
                if(bits[i] == 0){
                    temp = temp & ~(1 << i);
                }
            }
        }
        return temp;
    }


public:
    int minimumSubarrayLength(vector<int>& nums, int k) {
       
        int bits[32] = {};

        int left = 0, right = 0, n = nums.size(), orV = 0;

        int minLen = INT_MAX;

        while(right < n){
            orV |= nums[right];

            incr_bit_count(bits, nums[right]);

            while(orV >= k && left <= right){
                minLen = min(minLen, right-left+1);

                orV = decr_bit_count(bits, nums[left], orV);

                left++;
            }

            right++;
        }


        return minLen == INT_MAX ? -1 : minLen;
    }
};