#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
	int nthSuperUglyNumber(int n, vector<int>& primes) {
		int size = primes.size();
		if ( size == 0)
			return 0;
		int * result = new int[n];
		result[0] = 1; //插入第一个 1
		int * p = new int[size];

		for (int i = 0; i< size; ++i)
		{
			p[i] = 0;
		}

		for (int i = 1; i< n; i++)
		{
			int min_point = 0;
			int min = result[p[0]] * primes[0];
			for (int j = 1; j< size; j++)
			{
				int temp = result[p[j]] * primes[j];
				if (temp < min)
				{
					min = temp;
					min_point = j;
				}
			}
			result[i] = min;
			for (int j = 0; j < size; j++)
			{
				if (result[p[j]] * primes[j] == min)
					p[j]++;
			}
			

		}

		return result[n - 1];
	}
};

int main()
{
	Solution so;
	vector<int > pri{ 2, 7, 13, 19 };
	cout<<so.nthSuperUglyNumber(12, pri)<<endl;
	system("pause");
	return 0;
}