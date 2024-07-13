class Solution {
public:
    void pal (int l, int r, string s, string &res,int &len ){
        for(int i =0;i<s.size();i++){
            while(l>=0 && r<s.size() && s[l]==s[r]){
                if(r-l+1>len){
                    len = r-l+1;
                    res = s.substr(l,len);
                }
                else{
                    l--;
                    r++;
                }
            }
        }
    }
    string longestPalindrome(string s) {
        string res = "";
        int len  = 0;
        int size = s.size();
        for(int i =0;i<size;i++){
            pal(i,i,s,res,len);
            pal(i,i+1,s,res,len);
            
        }
        return res;
    }
};