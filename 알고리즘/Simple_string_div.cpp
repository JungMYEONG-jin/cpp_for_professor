#include <string>


long long solves(std::string st, int k) {
	//..
	int size = st.size() - k;
	long long max = 0;
	for (int i = 0; i <= st.size() - size; i++)
	{
		if (max < stoi(st.substr(i, size)))
			max = stoi(st.substr(i, size));
	}
	return max;
}
