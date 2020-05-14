#pragma once



#include <cstddef>
#include <optional>
#include <vector>
#include <utility>
#include <stdexcept>


template <typename T, typename Container=std::vector<std::optional<int>>>
class Grid
{
public:
	explicit Grid(size_t width = kWidth, size_t height = kHeight);
	virtual ~Grid() = default;


	Grid(const Grid& src) = default;
	Grid<T, Container>& operator=(const Grid& rhs) = default;

	Grid(Grid&& src) = default;
	Grid<T, Container>& operator=(Grid&& rhs) = default;

	typename Container::value_type& at(size_t, size_t y);
	const typename Container::value_type& at(size_t, size_t y) const;

	size_t getHeight() const { return mHeight; }
	size_t getWidht() const { return mWidth; }

	static const size_t kWidth = 10;
	static const size_t kHeight = 10;


private:
	void verifyCoordinate(size_t x, size_t y) const;

	std::vector<Container> mCells;
	size_t mWidth = 0, mHeight = 0;


};


template<typename T, typename Container>
Grid<T, Container>::Grid(size_t width, size_t height)
	:mWidth(width), mHeight(height)
{
	mCells.resize(mWidth);
	for (auto& col : mCells)
	{
		col.resize(mHeight);
	}
}


template<typename T, typename Container>
void Grid<T, Container>::verifyCoordinate(size_t x, size_t y) const
{
	if (x >= mWidth || y >= mHeight) {
		throw std::out_of_range("");
	}
}

template<typename T, typename Container>
const typename Container::value_type& Grid<T, Container>::at(size_t x, size_t y) const
{
	verifyCoordinate(x, y);
	return mCells[x][y];
}

template<typename T, typename Container>
typename Container::value_type& Grid<T, Container>::at(size_t x, size_t y)
{
	return const_cast<typename Container::value_type&>(std::as_const(*this).at(x, y));
}