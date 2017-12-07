#pragma once

namespace lab8
{
	template <typename T>
	class Storage
	{
	public:
		Storage(int length);
		Storage(const Storage& other);
		Storage(Storage&& other);

		Storage& operator=(Storage&& other);

		const T* GetData() const;
		int GetLength() const;
		virtual ~Storage();

	private:
		T* mData;
		int mLength;
	};

	template <typename T>
	Storage<T>::Storage(int length)
	{
		mData = new T[length];
		mLength = length;
	}

	template <typename T>
	Storage<T>::Storage(const Storage& other)
		: mLength(other.mLength)
	{
		mData = new T[other.mLength];
		memcpy(mData, other.mData, other.mLength);
	}

	template <typename T>
	Storage<T>::Storage(Storage&& other)
		: mData(other.mData)
		, mLength(other.mLength)
	{
		other.mData = nullptr;
		other.mLength = 0;
	}

	template <typename T>
	Storage<T>& Storage<T>::operator=(Storage&& other)
	{
		Storage output(std::move(other));
		return output;
	}

	template <typename T>
	const T* Storage<T>::GetData() const
	{
		return mData;
	}

	template <typename T>
	int Storage<T>::GetLength() const
	{
		return mLength;
	}

	template <typename T>
	Storage<T>::~Storage()
	{
		delete mData;
	}
}