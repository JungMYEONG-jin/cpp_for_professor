#include <iostream>
#include <string>
#include <vector>
#include <tuple>


using namespace std;


// MyCode

struct {
	double sum = 0, temp;
}v;

class Value
{
public:
	static void add(int n) { v.sum += n; } // mycode have to add each_type definition 
	static void add(double n) { v.sum += n; }
	static void add(float n) { v.sum += n; }
	static void add(long n) { v.sum += n; }
	static void add(long long n) { v.sum += n; }
	template<typename T>
	static void add(T n) {}
};

template<size_t S=0, typename... Ts>
inline typename std::enable_if<S ==sizeof...(Ts), void>::type
	tuple_sum(const std::tuple<Ts...>& tpl) { v.temp = v.sum; }

template<size_t S=0, typename... Ts>
inline typename std::enable_if<S < sizeof...(Ts), double>::type
	tuple_sum(const std::tuple<Ts...>& tpl)
{
	Value::add(std::get<S>(tpl));
	tuple_sum<S + 1, Ts...>(tpl);
	v.sum = 0;
	return v.temp;
}

// BestCode

template<typename T>
std::enable_if_t<!std::is_arithmetic<T>::value, double> double_val(T n) { return 0.0; }

template<typename T>
std::enable_if_t<std::is_arithmetic<T>::value, double> double_val(T n) { return n; }

double double_val(char) { return 0.0; }

// 연산이 안되는 type은 0으로 연산 가능시 그대로 값 전달 하도록 미리 정의


template<size_t I=0, typename... Ts>
std::enable_if_t<I == sizeof...(Ts), double>
tuple_sums(const std::tuple<Ts...>& tpl) { return 0.0; }

template<size_t I=0, typename... Ts>
std::enable_if_t < I <sizeof...(Ts), double>
	tuple_sums(const std::tuple<Ts...>& tpl)
{
	return double_val((std::get<I>(tpl))) + tuple_sums<I + 1, Ts...>(tpl);
}




int main()
{
	tuple<double, double, double, string, vector<int>, long> res;
	res = make_tuple(1.2, 3.3, 2.1, "saki", vector<int>{1, 2, 3},12123);

	cout << tuple_sum(res) << endl;
	cout << tuple_sums(res) << endl;


}