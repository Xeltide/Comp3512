#pragma once

#include <memory>

namespace lab7
{
	template <typename T>
	class Node;

	template <typename T>
	class DoublyLinkedList
	{
	public:
		DoublyLinkedList();
		void Insert(std::unique_ptr<T> data);
		void Insert(std::unique_ptr<T> data, unsigned int index);
		bool Delete(const T& data);
		bool Search(const T& data) const;

		std::shared_ptr<Node<T>> operator[](unsigned int index) const;
		unsigned int GetLength() const;
	private:
		unsigned int mCount;
		std::shared_ptr<Node<T>> mRoot;
	};

	template <typename T>
	DoublyLinkedList<T>::DoublyLinkedList()
		: mCount(0)
	{

	}

	template <typename T>
	void DoublyLinkedList<T>::Insert(std::unique_ptr<T> data)
	{
		if (mRoot == nullptr)
		{
			mRoot = std::make_shared<Node<T>>(std::move(data));
		}
		else
		{
			std::shared_ptr<Node<T>> current = mRoot;
			while (current->Next != nullptr)
			{
				current = current->Next;
			}
			current->Next = std::make_shared<Node<T>>(std::move(data));
			current->Next->Previous = current;
		}
		mCount++;
	}

	template <typename T>
	void DoublyLinkedList<T>::Insert(std::unique_ptr<T> data, unsigned int index)
	{
		if (index < mCount)
		{
			std::shared_ptr<Node<T>> prev;
			std::shared_ptr<Node<T>> current = mRoot;
			for (unsigned int i = 0; i != index; i++)
			{
				current = current->Next;
			}

			// Not root
			if (current->Previous.lock() != nullptr)
			{
				prev = current->Previous.lock();
				prev->Next = std::make_shared<Node<T>>(std::move(data));
				prev->Next->Previous = prev;
				prev->Next->Next = current;
				current->Previous = prev->Next;
			}
			else
			{
				mRoot = std::make_shared<Node<T>>(std::move(data));
				mRoot->Next = current;
				current->Previous = mRoot;
			}
			mCount++;
		}
		else if (index > mCount)
		{
			this->Insert(std::move(data));
		}
		else if (index == 0)
		{
			std::shared_ptr<Node<T>> temp = mRoot;
			mRoot = mRoot = std::make_shared<Node<T>>(std::move(data));
			mRoot->Next = temp;
			mCount++;
		}
	}

	template <typename T>
	bool DoublyLinkedList<T>::Delete(const T& data)
	{
		std::shared_ptr<Node<T>> current = mRoot;
		while (current != nullptr)
		{
			if (*(current->Data) == data)
			{
				break;
			}
			current = current->Next;
		}

		if (current != nullptr)
		{
			std::shared_ptr<Node<T>> prev = current->Previous.lock();
			std::shared_ptr<Node<T>> next = current->Next;
			if (prev != nullptr && next != nullptr)
			{
				prev->Next = next;
				next->Previous = prev;
			}
			else if (prev != nullptr && next == nullptr)
			{
				prev->Next = nullptr;
			}
			else if (prev == nullptr && next != nullptr)
			{
				mRoot = current->Next;
			}
			else
			{
				mRoot = nullptr;
			}
			mCount--;
			return true;
		}
		else
		{
			return false;
		}
	}

	template <typename T>
	bool DoublyLinkedList<T>::Search(const T& data) const
	{
		std::shared_ptr<Node<T>> current = mRoot;
		while (current != nullptr)
		{
			if (*(current->Data) == data)
			{
				break;
			}
			current = current->Next;
		}

		if (current != nullptr)
		{
			return true;
		}
		return false;
	}

	template <typename T>
	std::shared_ptr<Node<T>> DoublyLinkedList<T>::operator[](unsigned int index) const
	{
		if (index < mCount)
		{
			std::shared_ptr<Node<T>> current = mRoot;
			unsigned int i = 0;
			while (i != index)
			{
				current = current->Next;
				i++;
			}
			return current;
		}
		return nullptr;
	}

	template <typename T>
	unsigned int DoublyLinkedList<T>::GetLength() const
	{
		return mCount;
	}
}