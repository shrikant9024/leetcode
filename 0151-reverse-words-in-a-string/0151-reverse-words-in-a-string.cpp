class Solution {
public:
    string reverseWords(string s) {
        stack<string> st;
        string word = "";
        
        for(auto c : s){
            if(c== ' '){
                if(!word.empty()){
                    st.push(word);
                    word = "";
                }
            } else{
                word +=c;
            }
        }
        if(!word.empty()){
            st.push(word);
        }
        
        word  = "";
        
        while(!st.empty()){
            word+=st.top();
            st.pop();
            if(!st.empty()){
                word += " ";
            }
        }
        
        return word;
    }
};