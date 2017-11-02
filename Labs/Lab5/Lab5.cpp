#include "Lab5.h"

namespace lab5
{
	int Sum(const std::vector<int>& v)
	{
		int sum = 0;
		for (size_t i = 0; i < v.size(); i++)
		{
			sum += v[i];
		}
		return sum;
	}

	int Min(const std::vector<int>& v)
	{
		if (v.size() > 0)
		{
			int min = v[0];
			for (size_t i = 1; i < v.size(); i++)
			{
				if (min > v[i])
				{
					min = v[i];
				}
			}
			return min;
		}
		return 0;
	}

	int Max(const std::vector<int>& v)
	{
		if (v.size() > 0)
		{
			int max = v[0];
			for (size_t i = 1; i < v.size(); i++)
			{
				if (max < v[i])
				{
					max = v[i];
				}
			}
			return max;
		}
		return 0;
	}

	float Average(const std::vector<int>& v)
	{
		if (v.size() > 0)
		{
			int sum = lab5::Sum(v);
			return sum / (float)v.size();
		}
		return 0;
	}

	int NumberWithMaxOccurrence(const std::vector<int>& v)
	{
		int maxOccurrence = 0;
		int maxVal = 0;
		for (size_t i = 0; i < v.size(); i++)
		{
			int counter = 0;
			for (size_t j = i + 1; j < v.size(); j++)
			{
				if (v[j] == v[i])
				{
					counter++;
				}
			}
			if (counter > maxOccurrence)
			{
				maxVal = v[i];
				maxOccurrence = counter;
			}
		}
		return maxVal;
	}
}