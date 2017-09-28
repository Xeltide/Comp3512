#pragma once

#include <string>

namespace lab3
{
	class TimeSheet
	{
	public:
		TimeSheet(const char* employeeName, int maxEntries);
		TimeSheet(const TimeSheet& other);
		~TimeSheet();

		void AddTime(float hours);
		float GetTotalTime() const;
		float GetAverageTime() const;
		const std::string& GetName() const;

	private:
		std::string mEmployeeName;
		int mMaxEntries;
		float mTotalTime;
		int mEntries;
	};
}
