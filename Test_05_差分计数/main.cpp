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
		else if (target > Numbers[low] && target < Numbers[mid])
		{
			high = mid;
			Search(Numbers, low, high, target, count);
		}
		else if (target > Numbers[mid] && target < Numbers[high])
		{
			low = mid;
			Search(Numbers, low, high, target, count);
		}
		else if (target == Numbers[(low + high) / 2] || target == Numbers[low] || target == Numbers[high])
		{//��low��highά�ֵ���һ�������ķ�Χ��
			return;
		}
		else
		{//û�ѵ�
			return;
		}
	}
}

int main()
{
	int Nouse = -1, width = 0;
	cin >> Nouse >> width;
	vector<int> Numbers;
	//�����س��ٽ�����һ��
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
		}//�ǿո��ֱ�ӽ�����һ��ѭ��
		int x = 0, w = 1;
		char c = tempc;//��tempc����c������Ҫ����ָ��ǰ��һ��
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
	for (int i = 0; i < Numbers.size() - 1; ++i)//���һ����������
	{
		int low = i + 1, high = Numbers.size() - 1;
		int target = Numbers[i] + width;
		Search(Numbers, low, high, target, count)
	}
	if (width == 0)//��������0����ô��Ҫ��2����Ϊֻͳ����һ��
	{
		count *= 2;
	}
	cout << count;
	return 0;
}