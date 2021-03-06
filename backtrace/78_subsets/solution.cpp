/*
Given a set of distinct integers, nums, return all possible subsets.

Note:
Elements in a subset must be in non-descending order.
The solution set must not contain duplicate subsets.
For example,
If nums = [1,2,3], a solution is:

[
  [3],
  [1],
  [2],
  [1,2,3],
  [1,3],
  [2,3],
  [1,2],
  []
]
*/

// Thanks http://algorithm.yuanbin.me/backtracking/subsets.html
// Thanks http://fisherlei.blogspot.com/2013/01/leetcode-subsets.html

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int> >resultSet;
        if(nums.empty()){
            return resultSet;
        }
        
        sort(nums.begin(), nums.end());
        vector<int> aSubset;
        resultSet.push_back(aSubset);
        backTrack(nums, 0, aSubset, resultSet);
        return resultSet;
    }
private:
    void backTrack(vector<int>& oriSet, int pos, vector<int>& aSubset, vector<vector<int> >& resultSet){
        // for each element in the oriSet starting from pos
        for(int i = pos; i < oriSet.size(); i++){
            // add it to the list
            aSubset.push_back(oriSet[i]);
            // push this result set.
            resultSet.push_back(aSubset);
            // process the remaing element in the oriSet.
            backTrack(oriSet, i+1, aSubset, resultSet);
            // assume have itereate this case with oriSet[i], now pop out(exculde) this element and add the next element;
            aSubset.pop_back();
        }
    }
};