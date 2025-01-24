
#include <algorithm>
#include <iostream>
#include <vector>

std::vector<std::string> split(const std::string& input, std::string delimiter) {
    std::vector<std::string> result;
    size_t start = 0;
    size_t end = input.find(delimiter); // 구문자의 위치를 찾는다.
    while (end != std::string::npos) {
        result.push_back(input.substr(start, end - start));  // string substr (size_t pos = 0, size_t len = npos) const;
        start = end + delimiter.size();
        end = input.find(delimiter, start); // size_t find (const string& str, size_t pos = 0) const noexcept;
    }
    result.emplace_back(input.substr(start));
    return result;
}

int main() {
    std::string data1 = "apple,banana,kiwi";
    auto split_data = split(data1, ",");
    for (const auto& s : split_data) {
        std::cout << s << std::endl;
    }

    std::cout << "\n";

    std::string data2 = "apple  banana  kiwi";
    split_data = split(data2, "  ");
    for (const auto& s : split_data) {
        std::cout << s << std::endl;
    }
    return 0;
}