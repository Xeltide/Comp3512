#include "Vector.h"

namespace lab4
{
	Vector::Vector(float x, float y, float z)
		: mX(x)
		, mY(y)
		, mZ(z)
	{
	}

	Vector::~Vector()
	{
	}

	Vector Vector::operator+(const Vector& other) const
	{
		Vector* out = new Vector(mX + other.mX, mY + other.mY, mZ + other.mZ);
		return *out;
	}

	Vector Vector::operator-(const Vector& other) const
	{
		Vector* out = new Vector(mX - other.mX, mY - other.mY, mZ - other.mZ);
		return *out;
	}

	float Vector::operator*(const Vector& other) const
	{
		return (mX * other.mX) + (mY * other.mY) + (mZ * other.mZ);
	}

	Vector Vector::operator*(float operand) const
	{
		Vector* out = new Vector(mX * operand, mY * operand, mZ * operand);
		return *out;
	}

	float Vector::operator[](unsigned int index) const
	{
		switch (index)
		{
		case 0:
			return mX;
		case 1:
			return mY;
		default:
			return mZ;
		}
	}

	float Vector::GetX() const
	{
		return mX;
	}

	float Vector::GetY() const
	{
		return mY;
	}

	float Vector::GetZ() const
	{
		return mZ;
	}

	Vector operator*(float operand, const Vector& v)
	{
		Vector* out = new Vector(v.mX * operand, v.mY * operand, v.mZ * operand);
		return *out;
	}
}