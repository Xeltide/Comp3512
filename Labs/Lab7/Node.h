#pragma once

#include <memory>

namespace lab7
{
	template <typename T>
	class Node
	{
	public:
		Node(std::unique_ptr<T> data);
		Node(std::unique_ptr<T> data, std::shared_ptr<Node<T>> prev);

		std::unique_ptr<T> Data;
		std::shared_ptr<Node<T>> Next;
		std::shared_ptr<Node<T>> Previous;
	};

	template <typename T>
	Node<T>::Node(std::unique_ptr<T> data)
	{
		Data = std::move(data);
	}

	template <typename T>
	Node<T>::Node(std::unique_ptr<T> data, std::shared_ptr<Node<T>> prev)
		: Previous(prev)
	{
		prev->Next = this;
		Data = std::move(data);
	}
}