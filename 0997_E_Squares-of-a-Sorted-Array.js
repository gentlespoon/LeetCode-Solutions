// github.com/gentlespoon
// 1117 - Hard - Building H2O
// Start       2019-07-13T11:51:39-07:00
// Finish      2019-07-13T12:02:51-07:00
// Runtime: 136 ms, faster than 72.39% of JavaScript online submissions for Squares of a Sorted Array.
// Memory Usage: 44 MB, less than 5.17% of JavaScript online submissions for Squares of a Sorted Array.


/*
Given an array A of non-negative integers, return an array consisting of all the even elements of A, followed by all the odd elements of A.

You may return any answer array that satisfies this condition.

 

Example 1:

Input: [3,1,2,4]
Output: [2,4,3,1]
The outputs [4,2,3,1], [2,4,1,3], and [4,2,1,3] would also be accepted.
 

Note:

1 <= A.length <= 5000
0 <= A[i] <= 5000
*/


// fastest implementation, O(n*log(n)) comlexity,
/**
 * @param {number[]} A
 * @return {number[]}
 */
var sortedSquares = function(A) {
  return A.map(num => num = num*num).sort((x, y) => x - y);
};



// slower implementaion, O(n) complexity
/**
 * @param {number[]} A
 * @return {number[]}
 */
var sortedSquares = function(A) {
  
  //find index for last negative number
  let posIndex = 0;
  for (let i = 0; i < A.length; i++) {
    if (A[i] >= 0) {
      posIndex = i;
      break;
    }
  }

  // if only positive numbers
  if (posIndex === 0) {
    return A.map(el => el*el);
  }
  
  let i = 0;
  let res = [];
  let negIndex = posIndex - 1;
  
  while (negIndex >= 0 && posIndex < A.length) {
    let negSquare = A[negIndex] * A[negIndex];
    let posSquare = A[posIndex] * A[posIndex];

    if (negSquare < posSquare) {
      res[i++] = negSquare;
      negIndex--;
    } else {
      res[i++] = posSquare;
      posIndex++;
    }
  }
  
  while(negIndex >= 0) {
    res[i++] = A[negIndex] * A[negIndex];
    
    negIndex--;
  }
  
  while(posIndex < A.length) {
    res[i++] = A[posIndex] * A[posIndex];
    
    posIndex++;
  }
  
  return res;
};
