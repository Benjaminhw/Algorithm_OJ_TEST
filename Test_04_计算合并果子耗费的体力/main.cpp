#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//每一次合并完了之后，都需要把合并的数重新插入这个有序队列里
int main()
{
	char NoUse[50];
	cin.getline(NoUse, 52);
	vector<int> Amount;
	int tempInt;
	while (cin >> tempInt)
	{
		Amount.push_back(tempInt);
		if (cin.get() == '\n')
		{
			break;
		}
	}
	sort(Amount.begin(), Amount.end());
	int result = 0;
	while (Amount.size() > 1)
	{
		result += Amount[0] + Amount[1];
		int tempValue = Amount[0] + Amount[1];
		for (vector<int>::iterator it = Amount.begin(); it < Amount.end(); ++it)
		{
			if (tempValue <= *it)
			{
				Amount.insert(it, tempValue);
				break;
			}
			else if (it == Amount.end() - 1)//需要判断边界
			{
				Amount.push_back(tempValue);
				break;
			}
		}
		Amount.erase(Amount.begin());
		Amount.erase(Amount.begin());
	}
	cout << result;
	return 0;
}