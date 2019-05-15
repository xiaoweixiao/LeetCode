//双指针
class Solution {
public:
    int maxArea(vector<int>& height) {
        int maxarea=0;
        size_t i=0,j=height.size()-1;
        while(i<j){
            int area=min(height[i],height[j])*(j-i);
            maxarea=max(maxarea,area);
            if(height[i]<height[j])
                i++;
            else
                j--;
        }
        return maxarea;
    }
};
