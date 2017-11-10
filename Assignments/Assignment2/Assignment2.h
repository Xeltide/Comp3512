#pragma once

#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

namespace assignment2
{
	template <typename K, class V>
	std::map<K, V> ConvertVectorsToMap(const std::vector<K>& keys, const std::vector<V>& data)
	{
		std::map<K, V> output;

		size_t minSize = keys.size() < data.size() ? keys.size() : data.size();
		for (size_t i = 0; i < minSize; ++i)
		{
			output.insert(std::pair<K, V>(keys[i], data[i]));
		}

		return output;
	}

	template <typename K, class V>
	std::vector<K> GetKeys(const std::map<K, V>& m)
	{
		std::vector<K> output;

		for (typename std::map<K, V>::const_iterator it = m.begin(); it != m.end(); ++it)
		{
			output.push_back(it->first);
		}

		return output;
	}

	template <typename K, class V>
	std::vector<V> GetValues(const std::map<K, V>& m)
	{
		std::vector<V> output;

		for (typename std::map<K, V>::const_iterator it = m.begin(); it != m.end(); ++it)
		{
			output.push_back(it->second);
		}

		return output;
	}

	template <typename T>
	std::vector<T> Reverse(const std::vector<T>& v)
	{
		std::vector<T> output;

		for (size_t i = v.size(); i > 0; --i)
		{
			output.push_back(v[i - 1]);
		}

		return output;
	}
}

template <typename T>
std::vector<T> operator+(const std::vector<T>& v1, const std::vector<T>& v2)
{
	std::vector<T> output;

	for (size_t i = 0; i < v1.size(); ++i)
	{
		if (std::find(output.begin(), output.end(), v1[i]) == output.end())
		{
			output.push_back(v1[i]);
		}
	}

	for (size_t j = 0; j < v2.size(); ++j)
	{
		if (std::find(output.begin(), output.end(), v2[j]) == output.end())
		{
			output.push_back(v2[j]);
		}
	}

	return output;
}

template <typename K, class V>
std::map<K, V> operator+(const std::map<K, V>& m1, const std::map<K, V>& m2)
{
	std::map<K, V> output;

	output.insert(m1.begin(), m1.end());
	output.insert(m2.begin(), m2.end());

	return output;
}

template <typename T>
std::ostream& operator<<(std::ostream& os, const std::vector<T>& v)
{
	for (size_t i = 0; i < v.size(); ++i)
	{
		os << v[i];
		if (i + 1 != v.size())
		{
			os << ", ";
		}
	}

	return os;
}

template <typename K, class V>
std::ostream& operator<<(std::ostream& os, const std::map<K, V>& m)
{

	for (typename std::map<K, V>::const_iterator it = m.begin(); it != m.end(); ++it)
	{
		os << "{ " << it->first << ", " << it->second << " }" << std::endl;
	}

	return os;
}