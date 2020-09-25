include <iostream>
#include <string>
#include <vector>
#include <iterator>
#include <algorithm>
template <typename T>
void print(T& arr)
{
	for (auto& val : arr) std::cout << val << " ";
	std::cout << std::endl;
}
int main()
{
	std::vector<std::string> v = { "Andrzej", "Ania", "Bartek", "Basia", "Cezary", "Celestyna","Dominik", "Daria", "Egon", "Emilia" };
	std::vector<std::string> v2;
	auto isWoman = [](std::string &s) { return s[s.size() - 1] == 'a'; };
	/*std::for_each(v.begin(), v.end(), [&v2](std::string &s ) {

		if (s[s.size() - 1] == 'a') { v2.push_back(s); }

	});*/
	std::copy_if(v.begin(), v.end(), std::back_inserter(v2), isWoman); // copy to new vector if woman
	v.erase(std::remove_if(v.begin(), v.end(), isWoman), v.end()); // if woman erase from vector

	std::printf("Women count: %d\n", v2.size());		// Women count based pn new vector size 
	print(v2);

	std::printf("Men count: %d\n", v.size());  // same for men, alternatively  count_if but its slower(?) 
	print(v);

	return 0;
}