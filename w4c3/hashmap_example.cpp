#include <unordered_map>
#include <iostream>
#include <tuple>
#include <vector>
// unordered 
// unique keys -> you cannot have pairs (1, 2) and pairs (1, 3). 
// associative keys-> values

template<typename K, typename V>
struct MyOwnHashMap {

    V getFromKey(K key) {
        for (auto p : myhashmap) {
            if (p.first == key) {
                return p.second;
            }
        }
    }

    std::vector<std::pair<K, V>> myhashmap;
};

int main() {
    std::unordered_map<int, std::string> map;

    map.insert( {1, "hello"});
    map.insert( {14580 , "Webster"});
    map.insert( {1232 , "Narnia"} );

    for (auto pair : map) {
        std::cout << "KEY: " << pair.first << ", VALUE: " << pair.second << std::endl;
    }

    std::pair<double, double> mypair = {1.0, 2.0};


    std::tuple<int, double, std::string, std::vector<int>> mytuple = {1, 1.0, "string", {1,2,3}};


    std::cout << "this is the second thing in my tuple " << std::get<1>(mytuple) << std::endl;

}