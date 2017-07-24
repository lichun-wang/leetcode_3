#include <iostream>
#include <vector>

using namespace std;

class NumArray {
public:
	vector<int > nums;
	vector<int > sums;
	int lowBit(int x){
		return x&(-x);
	}

	void change(int i, int val)
	{
		int size = nums.size();
		while (i <= size)
		{
			sums[i] += val;
			i += lowBit(i);
		}
	}

	int sum(int n)
	{
		int sumRes = 0;
		while (n>0)
		{
			sumRes += sums[n];
			n -= lowBit(n);
		}
		return sumRes;
	}


	NumArray(vector<int> nums) {
		this->nums = nums;
		sums = vector<int>(nums.size() + 1, 0);
		for (int i = 0; i< nums.size(); i++)
		{
			change(i + 1, nums[i]);
		}
	}

	void update(int i, int val) {
		
		int c = val - nums[i];
		nums[i] = val;
		change(i + 1, c);
	}

	int sumRange(int i, int j) {

		return sum(j + 1) - sum(i);
	}
};

int main()
{
	vector<int> a = { 7, 2, 7, 2, 0 };
	NumArray so(a);



	so.update(4, 6);
	so.update(0, 2);
	so.update(0, 9);
	cout<<so.sumRange(4, 4)<<endl;
	so.update(3, 8);
	cout << so.sumRange(0, 4) << endl;
	so.update(4, 1);
	cout << so.sumRange(0, 3) << endl;
	cout << so.sumRange(0, 4) << endl;
	so.update(0, 4);

	int c;
	cin >> c;

	return 0;
	
}