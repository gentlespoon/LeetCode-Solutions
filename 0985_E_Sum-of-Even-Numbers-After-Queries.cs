// github.com/gentlespoon
// 0985 - Easy - Sum of Even Numbers After Queries
// Start       2020-01-08T01:17:33-07:00
// Finish      2020-01-08T01:31:50-07:00

// Runtime: 384 ms, faster than 95.74% of C# online submissions for Sum of Even Numbers After Queries.
// Memory Usage: 48.3 MB, less than 100.00% of C# online submissions for Sum of Even Numbers After Queries.

/*
We have an array A of integers, and an array queries of queries.

For the i-th query val = queries[i][0], index = queries[i][1], we add val to A[index].  Then, the answer to the i-th query is the sum of the even values of A.

(Here, the given index = queries[i][1] is a 0-based index, and each query permanently modifies the array A.)

Return the answer to all queries.  Your answer array should have answer[i] as the answer to the i-th query.

 

Example 1:

Input: A = [1,2,3,4], queries = [[1,0],[-3,1],[-4,0],[2,3]]
Output: [8,6,2,4]
Explanation: 
At the beginning, the array is [1,2,3,4].
After adding 1 to A[0], the array is [2,2,3,4], and the sum of even values is 2 + 2 + 4 = 8.
After adding -3 to A[1], the array is [2,-1,3,4], and the sum of even values is 2 + 4 = 6.
After adding -4 to A[0], the array is [-2,-1,3,4], and the sum of even values is -2 + 4 = 2.
After adding 2 to A[3], the array is [-2,-1,3,6], and the sum of even values is -2 + 6 = 4.
 

Note:

1 <= A.length <= 10000
-10000 <= A[i] <= 10000
1 <= queries.length <= 10000
-10000 <= queries[i][0] <= 10000
0 <= queries[i][1] < A.length
*/

public class Solution {
    public int[] SumEvenAfterQueries(int[] A, int[][] queries)
    {
        int[] answer = new int[queries.Length];

        var sum = 0;
        foreach (var i in A)
        {
            sum += i % 2 == 0 ? i : 0;
        }
        
        var newValue = 0;
       
        
        for (var i = 0; i < queries.Length; i++)
        {
            if (A[queries[i][1]] % 2 == 0)
            {
                sum -= A[queries[i][1]];
            }
            newValue = A[queries[i][1]] + queries[i][0];
            A[queries[i][1]] = newValue;
            if ((newValue) % 2 == 0)
            {
                sum += newValue;
            }
            answer[i] = sum;
        }
        
        return answer;
    }
}
