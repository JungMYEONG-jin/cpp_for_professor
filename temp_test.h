#pragma once
#include <cmath>
#include <assert.h>

bool equal(double const a, double const b, double const epsilon = 0.001)
{
	return std::fabs(a - b) < epsilon;
}

namespace test_temp
{
	enum class scale{celsius, fahren, kelvin};

	template<scale S>
	class quantity
	{
		double const amount;
	public:
		constexpr explicit quantity(double a) : amount(a) {}
		explicit operator double() const { return amount; }
	};

	template<scale S>
	inline bool operator==(quantity<S> const& lhs, quantity<S> const& rhs)
	{
		return equal(static_cast<double>(lhs), static_cast<double>(rhs));
	}

	template<scale S>
	inline bool operator!=(quantity<S> const& lhs, quantity<S> const& rhs)
	{
		return !(lhs == rhs);
	}

	template<scale S>
	inline bool operator<(quantity<S> const& lhs, quantity<S> const& rhs)
	{
		return (static_cast<double>(lhs) < static_cast<double>(rhs));
	}

	template<scale S>
	inline bool operator>(quantity<S> const& lhs, quantity<S> const& rhs)
	{
		return (rhs < lhs);
	}

	template<scale S>
	inline bool operator>=(quantity<S> const& lhs, quantity<S> const& rhs)
	{
		return !(lhs < rhs);
	}

	template<scale S>
	inline bool operator<=(quantity<S> const& lhs, quantity<S> const& rhs)
	{
		return !(lhs > rhs);
	}

	template<scale S>
	constexpr quantity<S> operator+(quantity<S> const& lhs, quantity<S> const& rhs)
	{
		return quantity<S>(static_cast<double>(lhs) + static_cast<double>(rhs));
	}

	template<scale S>
	constexpr quantity<S> operator-(quantity<S> const& lhs, quantity<S> const& rhs)
	{
		return quantity<S>(static_cast<double>(lhs) - static_cast<double>(rhs));
	}

	template<scale S, scale R>
	struct convert_traits
	{
		static double convert(double const a) = delete;
	};

	template<>
	struct convert_traits<scale::celsius, scale::fahren>
	{
		static double convert(double const a)
		{
			return a * 1.8 + 32;
		}
	};

	template<>
	struct convert_traits<scale::fahren, scale::celsius>
	{
		static double convert(double const a)
		{
			return (a - 32) / 1.8;
		}
	};

	template<>
	struct convert_traits<scale::celsius, scale::kelvin>
	{
		static double convert(double const a)
		{
			return a + 273.15;
		}
	};

	template<>
	struct convert_traits<scale::kelvin, scale::celsius>
	{
		static double convert(double const a)
		{
			return a - 273.15;
		}
	};


	template<>
	struct convert_traits<scale::fahren, scale::kelvin>
	{
		static double convert(double const a)
		{
			return (a - 32) / 1.8 + 273.15;
		}
	};

	template<>
	struct convert_traits<scale::kelvin, scale::fahren>
	{
		static double convert(double const a)
		{
			return (a - 273.15) / 1.8 + 32;

		}
	};

	template<scale R, scale S>
	constexpr quantity<R> temper_cast(quantity<S> const& q)
	{
		return quantity<R>(convert_traits<S, R>::convert(static_cast<double>(q)));
	}

	

	namespace literal
	{
		constexpr quantity<scale::celsius> operator "" _deg(long double const a)
		{
			return quantity<scale::celsius>{static_cast<double>(a)};
		}

		constexpr quantity<scale::fahren> operator "" _F(long double const a)
		{
			return quantity<scale::fahren>{static_cast<double>(a)};
		}

		constexpr quantity<scale::kelvin> operator "" _K(long double const a)
		{
			return quantity<scale::kelvin>{static_cast<double>(a)};
		}
	}


}
