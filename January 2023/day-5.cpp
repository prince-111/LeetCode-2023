class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
       
        if(points.size()==1) return 1;
        
        sort(points.begin(), points.end());
        
        int start = points[0][0], end=points[0][1], res=1;
        
        for(int i=1; i<points.size(); i++){
            
            if(points[i][0]<=end){
               start = max(start,points[i][0]);
                end=min(end,points[i][1]);
            }
            else{
                res++;
                start = points[i][0];
                end = points[i][1];
            }
        }
        return res;
    }


/*
452. Minimum Number of Arrows to Burst Balloons
https://leetcode.com/problems/minimum-number-of-arrows-to-burst-balloons/

There are some spherical balloons taped onto a flat wall that represents the XY-plane. 
  The balloons are represented as a 2D integer array points where points[i] = [xstart, xend] denotes a balloon whose horizontal diameter stretches between xstart and xend. 
   You do not know the exact y-coordinates of the balloons.

Arrows can be shot up directly vertically (in the positive y-direction) from different points along the x-axis. 
  A balloon with xstart and xend is burst by an arrow shot at x if xstart <= x <= xend. There is no limit to the number of arrows that can be shot. 
    A shot arrow keeps traveling up infinitely, bursting any balloons in its path.

Given the array points, return the minimum number of arrows that must be shot to burst all balloons.


Example 1:
Input: points = [[1,2],[2,3],[3,4],[4,5]]
Output: 2
Explanation: The balloons can be burst by 2 arrows:
- Shoot an arrow at x = 2, bursting the balloons [1,2] and [2,3].
- Shoot an arrow at x = 4, bursting the balloons [3,4] and [4,5].
*/