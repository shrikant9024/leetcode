class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> st;
        vector<int> res;
        for (auto it : asteroids) {
            while (!st.empty() && st.top() > 0 && it < 0) {
                int sum = it + st.top();
                
                if (sum < 0) {
                    st.pop();
                } else if (sum > 0) {
                    it = 0; 
                } else {
                    st.pop();
                    it = 0;  
                    break;
                }
            }
            if (it != 0) {
                st.push(it);
            }
        }
        while (!st.empty()) {
            res.push_back(st.top());
            st.pop();
        }
        reverse(res.begin(), res.end());
        return res;
    }
};
