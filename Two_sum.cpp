#include <iostream>
#include <iterator>
#include <unordered_map>

// time complexity O(n)
//Space complexity O(n)
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
    
    // stores pair of index to give the sum
    vector<int> Answer;
    
    // hash table used
    unordered_map<int, int > map_struct;
        
    for(int i = 0; i < nums.size(); i++) {
        // gets the other value we need to get the target value
        // from the vector 
        int complement = target - nums[i];
        // checks if such a value exists in our hashmap
        // as we check for .end in a map, where .end is the value
        // which is oen afterr the last key in the hashmap
        if (map_struct.find(complement) != map_struct.end()){  
        Answer.push_back(map_struct[complement]);
        Answer.push_back(i);
        return Answer;
        }
        
        // stores nums[i] as key and i as value to get the 
        // as the previous values in the vector as the hashmap
        map_struct[nums[i]] = i;
        
    }
        
    return Answer;
        
    }
};
