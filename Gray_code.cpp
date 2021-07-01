// Time complexity = O(2ˆn)
// Space Complexity = O(2ˆn)
class Solution {
public:
    vector<int> grayCode(int n) {
        // answer vector
        vector<int> answer_code;
        // max value just after 2ˆn -1 using left shift
        int j = 1;
        j = j << n;
        // for loop to go through all possible interations
        for(int i = 0;  i < j ; i++){
            // As each consecutive value is adding +1 it shifts the whole value by one to the left, if 
            // we do a logical right shift as int is signed it will move all digits to the right by 
            // dividing it by 2 and by doing XOR after that we can make sure to preserve that only  
            // one bit is changed everytime.
            int Xor_mask = i >> 1;
            int ans = i ^ Xor_mask ;
            answer_code.push_back(ans);       
        }
        return answer_code;
    }
};
