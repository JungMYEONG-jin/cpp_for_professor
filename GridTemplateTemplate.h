#pragma once



#include <cstddef>
#include <stdexcept>
#include <vector>
#include <optional>
#include <utility>


template<typename T,
	template<typename E, typename Allocator=std::allocator<E>> typename Container=std::vector>
class Grid
{
public:
	explicit Grid(size_t width = kWidth, size_t height = kHeight);
	virtual ~Grid() = default;

	Grid(const Grid& src) = default;
	Grid<T, Container>& operator=(const Grid& rhs) = default;

	Grid(Grid&& src) = default;
	Grid<T, Container>& operator=(Grid&& rhs) = default;

	std::optional<T>& at(size_t x, size_t y);
	const std::optional<T>& at(size_t x, size_t y) const;


	size_t getHeight() const { return mHeight; }
	size_t getWidth() const { return mWidth; }



	static const size_t kWidth = 10;
	static const size_t kHeight = 10;

private:

	void verifyCoordinate(size_t x, size_t y) const;

	std::vector<Container<std::optional<T>>> mCells;
	size_t mWidth = 0, mHeight = 0;



};


template<typename T, template<typename E, typename Allocator=std::allocator<E>> typename Container>
Grid<T, Container>::Grid(size_t width, size_t height)
	:mWidth(width), mHeight(height)
{
	mCells.resize(mWidth);
	for (auto& col : mCells)
	{
		col.resize(mHeight);
	}
}

template<typename T, template<typename E, typename Allocator=std::allocator<E>> typename Container>
void Grid<T, Container>::verifyCoordinate(size_t x, size_t y) const
{
	if (x >= mWidth || y >= mHeight)
	{
		throw std::out_of_range("");
	}
}

template<typename T, template<typename E, typename Allocator=std::allocator<E>> typename Container>
const std::optional<T>& Grid<T, Container>::at(size_t x, size_t y) const
{
	verifyCoordinate(x, y);
	return mCells[x][y];
}


template<typename T, template<typename E, typename Allocator = std::allocator<E>> typename Container>
std::optional<T>& Grid<T, Container>::at(size_t x, size_t y)
{
	return const_cast<std::optional<T>&>(std::as_const(*this).at(x, y));
}