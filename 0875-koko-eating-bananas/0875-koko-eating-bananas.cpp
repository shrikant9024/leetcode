class Solution {
public:
    
    int maxElement(const vector<int>& piles) {
        int maxi = INT_MIN;
        for(auto it : piles) {
            maxi = max(maxi, it);
        }
        return maxi;
    }
        
    long long totalhours(const vector<int>& piles, int speed) {
        long long totalh = 0;  
        for(int i = 0; i < piles.size(); i++) {
            totalh += (piles[i] + speed - 1) / speed;
        }
        return totalh;
    }
    
    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1;
        int high = maxElement(piles);
        
        while(low <= high) {
            int mid = low + (high - low) / 2;
            long long totalh = totalhours(piles, mid);  
            if(totalh <= h) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        
        return low;
    }
};
