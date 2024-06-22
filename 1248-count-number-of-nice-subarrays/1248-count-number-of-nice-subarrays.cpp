class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int prev = 0;
        int odd = 0;
        int res = 0;
        int i=0;
        int j =0 ;
        int n =nums.size();
        
        while(j<n){
            
            if(nums[j]%2!=0) {
                odd++;
                prev = 0;
            }
            while(odd==k){
                prev++;
                if(i<n && nums[i]%2==1){
                    odd--;
                }
                i++;
            }
            res +=prev;
            j++;
        }
        return res;
    }
};