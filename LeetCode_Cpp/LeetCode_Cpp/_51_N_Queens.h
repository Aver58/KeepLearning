#pragma once

/*

The n-queens puzzle is the problem of placing n queens on an n×n chessboard such that no two queens attack each other.



Given an integer n, return all distinct solutions to the n-queens puzzle.

Each solution contains a distinct board configuration of the n-queens' placement, where 'Q' and '.' both indicate a queen and an empty space respectively.

Example:

Input: 4
Output: [
 [".Q..",  // Solution 1
  "...Q",
  "Q...",
  "..Q."],

 ["..Q.",  // Solution 2
  "Q...",
  "...Q",
  ".Q.."]
]
Explanation: There exist two distinct solutions to the 4-queens puzzle as shown above.

*/

#include "Global.h"

class _51_N_Queens
{
public:
	void Test() {
		_51_N_Queens::solveNQueens(4);
	}

    vector<vector<string>> solveNQueens(int n) {
        // 利用一个数组来记录每一行里皇后所在的列，

    }
};