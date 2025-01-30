
#include <algorithm>
#include <iostream>
#include <map>
#include <string>
#include <vector>

int main() {
    std::map<int, int> mp;
    std::vector<int> v1 = {1, 1, 2, 2, 2, 3, 4, 5, 5};
    for (int item : v1) {
        if (mp[item]) {
            continue;
        } else {
            mp[item] = 1;
        }
    }

    std::vector<int> ret;
    for (auto item : mp) {
        ret.emplace_back(item.first);
    }

    for (auto item : ret) {
        std::cout << item << "\n";
    }

    std::vector<int> v2 = {1, 1, 1, 2, 2, 2, 3, 4, 5, 5, 1, 2, 3};

    std::cout << "Before\n";
    for (auto item : v2) {
        std::cout << item << ", ";
    }
    std::cout << "\n";
    /*
     * Before
     * 1, 1, 1, 2, 2, 2, 3, 4, 5, 5, 1, 2, 3,
     */

    // 중복되지 않은 요소로 채운 후, 그 다음 이터레이터를 반환한다.
    auto it = std::unique(v2.begin(), v2.end());

    std::cout << "After\n";
    for (auto item : v2) {
        std::cout << item << ", ";
    }
    std::cout << "\n";
    /*
     * After
     * 1, 2, 3, 4, 5, 1, 2, 3, 5, 5, 1, 2, 3,
     */

    std::vector<int> v3 = {1, 1, 1, 2, 2, 2, 3, 4, 5, 5, 1, 2, 3, 100, 200, 100, 300};
    std::sort(v3.begin(), v3.end()); // 정렬
    std::cout << "sort() \n";
    for (auto item : v3) {
        std::cout << item << ", ";
    }
    std::cout << "\n";
    /*
     * sort() 
     * 1, 1, 1, 1, 2, 2, 2, 2, 3, 3, 4, 5, 5, 100, 100, 200, 300, 
     */

    it = std::unique(v3.begin(), v3.end());
    std::cout << "Only unique()\n";
    for (auto item : v3) {
        std::cout << item << ", ";
    }
    std::cout << "\n";
    /*
     * Only unique()
     * 1, 2, 3, 4, 5, 100, 200, 300, 3, 3, 4, 5, 5, 100, 100, 200, 300, 
     */

    v3.erase(std::unique(v3.begin(), v3.end()), v3.end());
    std::cout << "unique() + erase()\n";
    for (auto item : v3) {
        std::cout << item << ", ";
    }
    std::cout << "\n";
    /*
     * unique() + erase()
     * 1, 2, 3, 4, 5, 100, 200, 300, 3, 4, 5, 100, 200, 300, 
     */


    return 0;
}