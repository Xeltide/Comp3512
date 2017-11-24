#pragma once

#include <memory>

namespace assignment3
{
	template<typename T>
	class TreeNode
	{
	public:
		TreeNode(std::unique_ptr<T> data);
		TreeNode(std::shared_ptr<TreeNode<T>> parent, std::unique_ptr<T> data);

		std::unique_ptr<T> Data;
		std::shared_ptr<TreeNode<T>> Left;
		std::shared_ptr<TreeNode<T>> Right;
		std::weak_ptr<TreeNode<T>> Parent;
	};

	template <typename T>
	TreeNode<T>::TreeNode(std::unique_ptr<T> data)
	{
		Data = std::move(data);
	}

	template <typename T>
	TreeNode<T>::TreeNode(std::shared_ptr<TreeNode<T>> parent, std::unique_ptr<T> data)
		: Parent(parent)
	{
		Data = std::move(data);
	}
}
