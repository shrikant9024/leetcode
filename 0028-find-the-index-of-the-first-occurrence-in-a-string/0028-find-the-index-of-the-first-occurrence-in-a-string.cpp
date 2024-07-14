class Solution {
public:
    int strStr(string haystack, string needle) {
        int n1 = haystack.size();
        int n2 = needle.size();
        
        for(int i =0;i<=(n1-n2);i++){
            for(int j =0;j<n2;j++){
                if(haystack[i+j]!=needle[j]){
                    break;
                }
                if(j==n2-1){
                    return i; 
                }
            }
            
        }
        return -1;
    }
};