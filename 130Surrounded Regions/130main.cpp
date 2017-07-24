#include <iostream>
#include<algorithm>
#include<queue>
#include<vector>
using namespace std;

class Solution {
public:
	void solve(vector<vector<char>>& board) {

		if (board.size() <= 2)
			return;


		for (int i = 0; i < board.size(); i++)
		{
			for (int j = 0; j < board[i].size(); j++)
			{
				if (i == 0 || i == board.size() - 1 || j == 0 || j == board[0].size() - 1)
				{
					if (board[i][j] == 'O')
					{
						bfs(i, j, board);
					
					}
					
				}
				
			}
		}

		for (int i = 0; i < board.size(); i++)
		{
			for (int j = 0; j < board[0].size(); j++)
			{
				if (board[i][j] == 'O')
					board[i][j] = 'X';
				else if (board[i][j] == '*')
					board[i][j] = 'O';
				else
					continue;
			}
		}

	
	}
	void bfs(int i, int j, vector<vector<char>> &board)
	{
		pair<int, int> t_pair;
		queue< pair<int, int> > o_s;

		t_pair = make_pair(i, j);
		o_s.push(t_pair);
		board[t_pair.first][t_pair.second] = '*';
		while (!o_s.empty())
		{
			t_pair = o_s.front();
			o_s.pop();
	//		board[t_pair.first][t_pair.second] = '*';

			i = t_pair.first;
			j = t_pair.second;

			if (i > 0 && board[i - 1][j] == 'O')
			{
				t_pair = make_pair(i-1, j);
				o_s.push(t_pair);
				board[t_pair.first][t_pair.second] = '*';
			}
			if (i+1 < board.size() && board[i+1 ][j] == 'O')
			{
				t_pair = make_pair(i+1, j);
				o_s.push(t_pair);
				board[t_pair.first][t_pair.second] = '*';
			}
			if (j > 0 && board[i ][j-1] == 'O')
			{
				t_pair = make_pair(i, j-1);
				o_s.push(t_pair);
				board[t_pair.first][t_pair.second] = '*';
			}
			if (j +1< board[0].size() && board[i ][j+1] == 'O')
			{
				t_pair = make_pair(i, j+1);
				o_s.push(t_pair);
				board[t_pair.first][t_pair.second] = '*';
			}

		}

	}

};

int main()
{



	vector<vector<char>> o_s;
	char a1[4] = { 'O', 'O', 'O', 'O' };
	char a2[4] = { 'O', 'O', 'O', 'O' };
	char a3[4] = { 'O', 'O', 'O', 'O' };
	char a4[4] = { 'O', 'O', 'O', 'O' };
	vector<char> v1(a1, a1 + 4);
	vector<char> v2(a2, a2 + 4);
	vector<char> v3(a3, a3 + 4);
	vector<char> v4(a4, a4 + 4);

	o_s.push_back(v1);
	o_s.push_back(v2);
	o_s.push_back(v3);
	o_s.push_back(v4);
	Solution so;
	so.solve(o_s);
	system("pause");
	return 0;
}