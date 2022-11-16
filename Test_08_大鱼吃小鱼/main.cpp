#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <unordered_map>

//AC 100
using namespace std;

typedef struct FishProperties
{
	long long FishSize;
	long long FishValue;
}FishProperties, * pFishProperties;

bool MyCompare(const FishProperties a, const FishProperties b)
{
	if (a.FishValue >= 0)
	{
		if (b.FishValue >= 0)
		{
			return a.FishSize < b.FishSize;
			//if a's size smaller, then a in front;
		}
		else
		{
			return true;
			//a in front
		}
	}
	else
	{
		if (b.FishValue >= 0)
		{
			return false;
			//b in front
		}
		else
		{//a<0 && b<0
			return a.FishSize + a.FishValue > b.FishSize + b.FishValue;
		}
	}
}

int main()
{
	vector<FishProperties> Sets;
	long long  NFish, FishSize, FishValue;
	FishProperties temp;
	cin >> NFish;
	for (int i = 0; i < NFish; ++i)
	{
		cin >> temp.FishSize;
		cin >> temp.FishValue;
		Sets.emplace_back(temp);
	}
	sort(Sets.begin(), Sets.end(), MyCompare);
	//eat those fish that will make you bigger first, then consider the ones that make you smaller.
	long long result = Sets[0].FishSize;
	long long currentValue = result + Sets[0].FishValue;
	if (Sets.size() == 1)
	{
		if (currentValue <= 0)
		{
			result += 1 - currentValue;
			currentValue = 1;
		}
		cout << result;
		return 0;
	}
	for (int i = 1; i < Sets.size(); ++i)
	{
		if (currentValue < Sets[i].FishSize)
		{
			result += Sets[i].FishSize - currentValue;
			currentValue = Sets[i].FishSize;
		}
		currentValue += Sets[i].FishValue;
		if (currentValue <= 0)
		{
			result += 1 - currentValue;
			currentValue = 1;
		}
	}
	cout << result;
	return 0;
}