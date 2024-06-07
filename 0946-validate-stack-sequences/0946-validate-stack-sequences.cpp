class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        int n = pushed.size();
        int m = popped.size();
        int i = 0;
        int j = 0;
        stack<int> st;
        
        while(i<n && j<m){
            st.push(pushed[i]);
            while(!st.empty() && popped[j]==st.top()){
                st.pop();
                j++;
            }

             i++;
            
            
        }
        return st.empty();
    }
};