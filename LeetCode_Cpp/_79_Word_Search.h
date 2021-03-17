/*
Given an m x n gird of characters board and a string word, return true if word exists in the grid.
The word can be constructed from letters of sequentially adjacent cells, where adjacent cells are horizontally or vertically neighboring. The same letter cell may not be used more than once.
Note: There will be some test cases with a board or a word larger than constraints to test if your solution is using pruning.

Example 1:
Input: board = [
["A","B","C","E"],
["S","F","C","S"],
["A","D","E","E"]], word = "ABCCED"
Output: true

Example 2:
Input: board = [
["A","B","C","E"],
["S","F","C","S"],
["A","D","E","E"]], word = "SEE"
Output: true

Example 3:
Input: board = [
["A","B","C","E"],
["S","F","C","S"],
["A","D","E","E"]], word = "ABCB"
Output: false

Constraints:
·m == board.length
·n = board[i].length
·1 <= m, n <= 6
·1 <= word.length <= 15
·board and word consists of only lowercase and uppercase English letters.
*/

#pragma once

#include "Global.h"

class _79_Word_Search
{
private:
	vector<pair<int, int>> directions{ {0,  1}, {0, -1}, {1,  0}, {-1, 0} };

public:
	void Test() {
	/*	vector<vector<char>> board = { {"A", "B", "C", "E"},{"S", "F", "C", "S"},{"A", "D", "E", "E"}, };
		string word = "ABCB";
		_79_Word_Search::exist(board, word);*/
	}

	bool check(vector<vector<char>>& board, string& word, vector<vector<int>>& visited, int row, int column, int index) {
		if (board[row][column] != word[index])
			return false;
		if (index == word.length() - 1)
			return true;

		visited[row][column] = true;
		bool result = false;
		for (const auto& dir: directions)
		{
			int newRow = row + dir.first;
			int newColumn = column + dir.second;
			if (newRow >= 0 && newRow < board.size() && newColumn >= 0 && newColumn < board[0].size())
			{
				if (check(board, word, visited, newRow, newColumn, index + 1))
				{
					result = true;
					break;
				}
			}
		}
		// 回溯
		visited[row][column] = false;
		return result;
	}

	// 方法1：遍历找到字符+回溯剪枝
	bool exist(vector<vector<char>>& board, string word) {
		int row = board.size();
		int column = board[0].size();
		vector<vector<int>> visited(row, vector<int>(column));
		for (int i = 0; i < row; i++)
		{
			for (int j = 0; j < column; j++)
			{
				if (check(board,word, visited,row,column,0))
					return true;
			}
		}
		return false;
	}
};