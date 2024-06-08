class Solution {
public:
    
    int climbStairs(int n) {
    
       int prev = 1;
       int prev2 = 0;
        
        for(int i =1;i<=n;i++){
            
                int step1 = prev;
                int step2 = prev2;
                int cur = step1+step2;
            prev2 = prev;
            prev = cur;
            
            
        }
        return prev;
    }
};