#pragma once

namespace lab6
{
	template<class T, size_t N>
	class FixedVector
	{
	public:

		FixedVector()
			: mSize(0)
		{
			mCapacity = N;
		}

		~FixedVector()
		{
		}

		const T& Get(unsigned int index) const
		{
			return &mArray[index];
		}

		T& operator[](unsigned int index)
		{
			return mArray[index];
		}

		int GetIndex(const T& t) const
		{
			for (unsigned int i = 0; i < mCapacity; i++)
			{
				if (mArray[i] == t)
				{
					return i;
				}
			}
			return -1;
		}

		size_t GetSize() const
		{
			return mSize;
		}

		size_t GetCapacity() const
		{
			return mCapacity;
		}

		bool Add(const T& t)
		{
			if (mSize + 1 < mCapacity)
			{
				mArray[mSize] = t;
				mSize++;
				return true;
			}
			return false;
		}

		bool Remove(const T& t)
		{
			if (mSize > 0)
			{
				unsigned int i = 0;
				while (i < mSize)
				{
					if (mArray[i] == t)
					{
						break;
					}
					i++;
				}
				if (i != mSize)
				{
					for (unsigned int j = i + 1; j < mSize; j++)
					{
						mArray[j - 1] = mArray[j];
					}
					mSize--;
					return true;
				}
			}
			return false;
		}
	private:
		size_t mSize;
		size_t mCapacity;
		T mArray[N];
	};
}