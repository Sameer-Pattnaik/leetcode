class Solution {
public:
    int maxArea(vector<int>& height) {
       int resultantArea=0;
       int left=0;
       int right=height.size()-1;
       while(left<right)
       {
        resultantArea=max(resultantArea,(right-left)*min(height[left],height[right]));
        if(height[left]<height[right])
        {
            left++;
        }
        else
        {
            right--;
        }
       }
       return resultantArea;

    }
};