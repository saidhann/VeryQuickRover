#pragma once

#include <istream>
#include <array>

template <typename Type, int Size>
class Vector : public std::array<Type, Size> {
private:
	template <int Index, typename Tp, typename... Args>
	void addArgument(Tp type, Args... args);

	template <int Index, typename Tp>
	void addArgument(Tp type);
public:
	template <typename... Args,
		typename = typename std::enable_if<sizeof...(Args) == Size>::type>
	Vector(Args&&... args);

	Vector& operator+=(Vector const& second);

	using std::array<Type, Size>::array;
};

template <typename Type, int Size>
Vector<Type, Size> operator*(Vector<Type, Size> const& first, Vector<Type, Size> const& second);

template <typename Type, int Size>
Vector<Type, Size> operator*(Vector<Type, Size> const& first, Type const& second);

template <typename Type, int Size>
Vector<Type, Size> operator-(Vector<Type, Size> const& first, Vector<Type, Size> const& second);

template <typename Type, int Size>
Vector<Type, Size> operator+(Vector<Type, Size> const& first, Vector<Type, Size> const& second);

template <typename Type, int Size>
std::istream& operator>>(std::istream& strm, Vector< Type,Size> &vct);

template <typename Type, int Size>
std::ostream& operator<<(std::ostream& strm, Vector<Type,Size> const& vct);

#include "vector.tt"
