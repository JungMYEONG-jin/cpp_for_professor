#include <iostream>


using namespace std;


/// <summary>
/// ////
/// </summary>
/// <typeparam name="T"></typeparam>
/// <param name="arg"></param>
/// <returns></returns>
template <typename T>
T minimum(T arg)
{
	return arg;
}


/// <summary>
/// </summary>
/// <typeparam name="T"></typeparam>
/// <typeparam name="...Tn"></typeparam>
/// <param name="init"></param>
/// <param name="...arg"></param>
/// <returns></returns>
template<typename T, typename... Tn>
T minimum(T init, Tn... arg)
{
	return init < minimum(arg...) ? init : minimum(arg...);
}

//여기까진 내 소스




// book source

template<typename T>
T get_minimum(T const a, T const b)
{
	return a < b ? a : b;
}

template<typename T, typename... Tn>
T get_minimum(T a, Tn... arg)
{
	return get_minimum(a, get_minimum(arg...));
}



template <class Comp, typename T>
T minimumC(Comp comp, T const a, T const b)
{
	return comp(a, b) ? a : b;
}

template <class Comp, typename T, typename... Tn>
T minimumC(Comp comp, T a, Tn... args)
{
	return minimumC(comp, a, minimumC(comp, args...));
}




int main()
{


	cout << minimum(3, 1, 2, 6, 7, 8, 0, 0.475) << endl;
	cout << get_minimum(3, 1, 2, 6, 7, 8, 0) << endl;
	cout << minimumC(less(), 3, 2, 1, 99);
}