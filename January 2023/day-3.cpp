/*
944. Delete Columns to Make Sorted
https://leetcode.com/problems/delete-columns-to-make-sorted/

Input: strs = ["cba","daf","ghi"]
Output: 1
Explanation: The grid looks as follows:
  cba
  daf
  ghi
Columns 0 and 2 are sorted, but column 1 is not, so you only need to delete 1 column.

*/


class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        
        int deleteCount=0;
        
        for(int col=0; col<strs[0].size(); col++){
            for(int row=1; row<strs.size(); row++){
                
                if(strs[row][col] < strs[row-1][col]){
                    deleteCount++;
                    break;
                }
            }
        }
        return deleteCount;
    }
};