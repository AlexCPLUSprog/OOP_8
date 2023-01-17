#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <unordered_map>
#include <utility>
#include <tuple>


class DataManager {
public:
	int mostSearchedKey() {
		std::unordered_map<int, int> keyAmount;
		for (size_t i = 0; i < _keys.size(); i++) {
			const auto& [it, isInserted] = keyAmount.insert({_keys[i], 1});	// делаем вставку того, что встречаетс€ один раз
			if (!isInserted) {
				auto value = it->second;
				value++;
				keyAmount[_keys[i]] = value;	//  вадратные скобки гарантированно добавл€ют значени€
			}
		}
		std::pair<int, int> keyBiggestValue = {0,0};
		for (std::unordered_map<int, int>::const_iterator it = keyAmount.begin(); it != keyAmount.end(); it++) {
			if (keyBiggestValue.second < it->second) {
				keyBiggestValue = std::make_pair(it->first, it->second);
			}
		}
		return keyBiggestValue.first;
	}

private:
	std::vector<int> _keys = { 1,1,2,2,4,2,6,7,7,7,2 };
};

int divide(int a, int b) {
	if (b == 0) {
		throw "division by zero";
	}
	return a / b;
}

int errorFunc() {
	throw 0;
	return 1;
}

int main() {

	// тапл включаетс€ библиотекой <tuple>, может есть в <utility>
	/*std::tuple<int, std::string, double, float> t{1, "hey", 2.4, 2.3f};	// тапл как пара, но принимает больше двух значений
	const auto& [a, b, c, d] = t;
	std::cout << a << " " << b << " " << c << " " << d << '\n';

	std::cout << std::get<0>(t) << '\n';	// обращение к 0 элементу через функцию std::get

	std::vector <std::tuple<int, double, std::string>> vec;
	vec.push_back({ 55, 5.4, "bob" });
	vec.push_back({ 98, 6.8, "Alex" });

	for (size_t i = 0; i < vec.size(); i++) {
		const auto& [x, y, z] = vec[i];
		std::cout << x << " " << y << " " << z << '\n';
	}*/

	/*DataManager dm;
	std::cout << dm.mostSearchedKey() << '\n';*/

	// try...catch
	/*int x = 10, y = 0;
	try {
		errorFunc() << '\n';
		std::cout << divide(x, y) << '\n';
	}
	catch (const char* msg) {
		std::cerr << msg << '\n';	// дискриптор cerr как дискриптор cout, но более заточен под ошибки
	}
	catch (int e) {
		std::cerr << e << '\n';
	}

	catch(...){	// catch all
		std::cerr << "Some exception has occured" << '\n';
	}*/

	std::vector<int> v{ 1,2,3 };
	try {
		int z = v.at(10);
	}
	catch (const std::out_of_range& e) {
		std::cerr << e.what() << '\n';
	}

}

