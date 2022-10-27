#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <unordered_map>

using namespace std;

void Search(vector<int>Numbers, int low, int high, int target, int& count)
{
	while (low <= high)
	{
		int mid = (low + high) / 2;
		if (Numbers[mid] == target)
		{
			++count;
			int i = mid - 1;
			while (i > low && Numbers[i] == target)
			{
				++count;
				--i;
			}
			i = mid + 1;
			while (i < high && Numbers[i] == target)
			{
				++count;
				++i;
			}
			return;
		}
		else if (target > Numbers[mid])
		{
			low = mid + 1;
			Search(Numbers, low, high, target, count);
		}
		else
		{
			high = mid - 1;
			Search(Numbers, low, high, target, count);
		}
	}
	return;
}

int main()
{
	int Nouse = -1, width = 0;
	cin >> Nouse >> width;
	vector<int> Numbers;
	//读到回车再进入下一行
	while (getchar() != '\n') {}
	int MapTag = 0;
	char tempc = 0;
	//unordered_map<int, int> NumberMap;
	while (tempc != '\n')
	{
		tempc = getchar();
		if (tempc != '-' && (tempc < '0' || tempc > '9'))
		{
			continue;
		}//是空格就直接进入下一个循环
		int x = 0, w = 1;
		char c = tempc;//将tempc传给c，则不需要将流指针前置一格
		while (c < '0' || c > '9') {
			if (c == '-') w = -1;
			c = getchar();
		}
		while (c >= '0' && c <= '9') {
			x = x * 10 + (c - '0');
			c = getchar();
		}
		Numbers.push_back(x * w);
		if (c == '\n')
		{
			break;
		}
	}
	int count = 0;
	sort(Numbers.begin(), Numbers.end());
	for (int i = 0; i < Numbers.size() - 1; ++i)//最后一个不用找了
	{
		int low = i + 1, high = Numbers.size() - 1;
		int target = Numbers[i] + width;
		Search(Numbers, low, high, target, count);
	}
	if (width == 0)//如果宽度是0，那么需要乘2，因为只统计了一半
	{
		count *= 2;
	}
	cout << count;
	return 0;
}