class Solution {
public:
    int maxArea(vector<int>& height) {
        int n =height.size();
        int i = 0;
        int j = n-1;
        int area = 0;
        int maxarea =INT_MIN;
        
        while(i<=j){
            area = (j-i)*min(height[i],height[j]);
            maxarea = max(area,maxarea);
            if(height[i]>height[j]){
                j--;
            }
            else i++;
        }
        return maxarea;
        
    }
};