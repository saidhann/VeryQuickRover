#pragma once
#include "vector.h"
#include <fstream>
#include <array>

template <typename Type, int Size>
class Matrix : public std::array<Vector<Type, Size>, Size> {
private:
	template <int Index, typename Tp, typename... Args>
	void addArgument(Tp type, Args... args);

	template <int Index, typename Tp>
	void addArgument(Tp type);
public:
	template <typename... Args, typename = typename std::enable_if<sizeof...(Args) == Size>::type>
	Matrix(Args&&... args);

	Type calculateDeterminant(void) const;

	void transposeMatrix(void);

	Vector<Type, Size> operator* (Vector<Type, Size> const& vec) const;
};

template <typename Type, int Size>
std::istream& operator >>(std::istream& strm, Matrix<Type,Size> &mtx);

#include "matrix.tt"
