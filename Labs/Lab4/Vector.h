#pragma once

namespace lab4
{
	class Vector
	{
	public:
		Vector(float x, float y, float z);
		virtual ~Vector();

		Vector operator+(const Vector& other) const;
		Vector operator-(const Vector& other) const;
		float operator*(const Vector& other) const;
		Vector operator*(float operand) const;
		float operator[](unsigned int index) const;

		float GetX() const;
		float GetY() const;
		float GetZ() const;

		friend Vector operator*(float operand, const Vector& v);

	private:

		float mX;
		float mY;
		float mZ;
	};
}