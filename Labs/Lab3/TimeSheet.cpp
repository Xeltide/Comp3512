#include "TimeSheet.h"

namespace lab3
{
	TimeSheet::TimeSheet(const char* name, int maxEntries)
	{
		mEmployeeName = name;
		mMaxEntries = maxEntries;
		mTotalTime = 0;
		mEntries = 0;
	}

	TimeSheet::TimeSheet(const TimeSheet& other)
	{
		mEmployeeName = other.mEmployeeName;
		mMaxEntries = other.mMaxEntries;
		mTotalTime = other.mTotalTime;
		mEntries = other.mEntries;
	}

	TimeSheet::~TimeSheet()
	{

	}

	void TimeSheet::AddTime(float timeInHours)
	{
		if (timeInHours <= 10 && mEntries < mMaxEntries && timeInHours > 0)
		{
			mEntries++;
			mTotalTime += timeInHours;
		}
	}

	float TimeSheet::GetAverageTime() const
	{
		float output = 0;

		if (mEntries > 0)
		{
			output = mTotalTime / mEntries;
		}

		return output;
	}

	float TimeSheet::GetTotalTime() const
	{
		return mTotalTime;
	}

	const std::string& TimeSheet::GetName() const
	{
		return mEmployeeName;
	}
}