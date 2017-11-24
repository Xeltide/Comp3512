#pragma once

#include <memory>
#include <vector>
#include <iostream>

namespace assignment3
{
	template<typename T>
	class TreeNode;

	template<typename T>
	class BinarySearchTree
	{
	public:
		void Insert(std::unique_ptr<T> data);
		bool Search(const T& data);
		bool Delete(const T& data);
		const std::weak_ptr<TreeNode<T>> GetRootNode() const;

		static std::vector<T> TraverseInOrder(const std::shared_ptr<TreeNode<T>> startNode);

	private:
		std::shared_ptr<TreeNode<T>> mRoot;

		// any other private members of methods can go here.
		std::shared_ptr<TreeNode<T>> SearchForNode(const T& data);
	};

	template <typename T>
	void BinarySearchTree<T>::Insert(std::unique_ptr<T> data)
	{
		if (mRoot == nullptr)
		{
			mRoot = std::make_shared<TreeNode<T>>(std::move(data));
		}
		else
		{
			std::shared_ptr<TreeNode<T>> lastVisited;
			std::shared_ptr<TreeNode<T>> node = mRoot;
			while (node != nullptr)
			{
				if (*data > *(node->Data))
				{
					lastVisited = node;
					node = node->Right;
				}
				else if (*data <= *(node->Data))
				{
					lastVisited = node;
					node = node->Left;
				}
			}

			if (*data > *(lastVisited->Data))
			{
				lastVisited->Right = std::make_shared<TreeNode<T>>(std::move(data));
				node = lastVisited->Right;
				node->Parent = lastVisited;
			}
			else if (*data <= *(lastVisited->Data))
			{
				lastVisited->Left = std::make_shared<TreeNode<T>>(std::move(data));
				node = lastVisited->Left;
				node->Parent = lastVisited;
			}
		}
	}

	template <typename T>
	std::shared_ptr<TreeNode<T>> BinarySearchTree<T>::SearchForNode(const T& data)
	{
		std::shared_ptr<TreeNode<T>> node = mRoot;
		while (node != nullptr)
		{
			if (data == *(node->Data))
			{
				break;
			}

			if (data > *(node->Data))
			{
				node = node->Right;
			}
			else if (data < *(node->Data))
			{
				node = node->Left;
			}
		}
		return node;
	}

	template <typename T>
	bool BinarySearchTree<T>::Search(const T& data)
	{
		std::shared_ptr<TreeNode<T>> node = SearchForNode(data);
		return node != nullptr;
	}

	template <typename T>
	bool BinarySearchTree<T>::Delete(const T& data)
	{
		std::shared_ptr<TreeNode<T>> node = SearchForNode(data);

		// Node found
		if (node != nullptr)
		{
			bool goRight = false;
			unsigned int goLeft = 0;
			T data = *(node->Data);
			std::shared_ptr<TreeNode<T>> parent = node->Parent.lock();
			std::shared_ptr<TreeNode<T>> left = node->Left;
			std::shared_ptr<TreeNode<T>> right = node->Right;
			// Go right if can
			if (right != nullptr)
			{
				goRight = true;
				node = right;
			}

			// Go left as far as can
			// Gets next ascending node in sequence
			while (node->Left != nullptr)
			{
				goLeft++;
				node = node->Left;
			}

			// Not root
			if (parent != nullptr)
			{
				// Delete node was on right of parent
				if (data > *(parent->Data))
				{
					// Is leaf
					if (goLeft == 0 && !goRight)
					{
						parent->Right = nullptr;
					}
					// Went left
					else if (goLeft > 0)
					{
						parent->Right = node;
						if (!(goLeft == 1 && !goRight))
						{
							node->Parent.lock()->Left.reset();
							node->Left = left;
						}
						node->Parent = parent;
						node->Right = right;
					}
					// Went right and only right
					else if (goRight)
					{
						parent->Right = node;
						node->Parent = parent;
						node->Left = left;
					}
				}
				// Delete node was on left of parent
				else
				{
					// Is leaf
					if (goLeft == 0 && !goRight)
					{
						parent->Left = nullptr;
					}
					// Went left
					else if (goLeft > 0)
					{
						parent->Left = node;
						if (!(goLeft == 1 && !goRight))
						{
							node->Parent.lock()->Left.reset();
							node->Left = left;
						}
						node->Parent = parent;
						node->Right = right;
					}
					// Went right and only right
					else if (goRight)
					{
						parent->Left = node;
						node->Parent = parent;
						node->Left = left;
					}
				}
			}
			else
			{
				// Is only node
				if (goLeft == 0 && !goRight)
				{
					mRoot = nullptr;
				}
				// Went left
				else if (goLeft > 0)
				{
					mRoot = node;
					if (!(goLeft == 1 && !goRight))
					{
						node->Parent.lock()->Left.reset();
						node->Left = left;
					}
					node->Parent.reset();
					node->Right = right;
				}
				// Went right and only right
				else if (goRight)
				{
					mRoot = node;
					node->Parent.reset();
					node->Left = left;
				}
			}
			
			return true;
		}

		return false;
	}

	template <typename T>
	const std::weak_ptr<TreeNode<T>> BinarySearchTree<T>::GetRootNode() const
	{
		std::weak_ptr<TreeNode<T>> root = mRoot;
		return root;
	}

	template <typename T>
	std::vector<T> BinarySearchTree<T>::TraverseInOrder(const std::shared_ptr<TreeNode<T>> startNode)
	{
		std::vector<T> output;
		std::vector<T> temp;

		if (startNode != nullptr)
		{
			temp = TraverseInOrder(startNode->Left);
			output.insert(output.end(), temp.begin(), temp.end());
			output.push_back(*(startNode->Data));
			temp = TraverseInOrder(startNode->Right);
			output.insert(output.end(), temp.begin(), temp.end());
		}

		return output;
	}
}
