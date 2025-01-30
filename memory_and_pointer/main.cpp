
#include <algorithm>
#include <iostream>
#include <vector>
#include <string>

class node {
    public :
     void *data;
     node *next;
};

int main() {
    int i;
    std::cout << &i << "\n";
    i = 0;
    std::cout << &i << "\n";

    int a = 4;
    int *b = &a;
    std::cout << &a << "\n";
    std::cout << b << "\n";
    std::cout << sizeof(b) << "\n";

    std::string name = "brightro99";
    std::string *name_ptr = &name;
    std::cout << *name_ptr << "\n";

    int arr[3] = {1, 2, 3};
    int *arr_ptr = arr;
    std::cout << arr_ptr << "\n";
    std::cout << &arr[0] << "\n";
    std::cout << arr_ptr + 1 << "\n";
    std::cout << &arr[1] << "\n";
    
    return 0;
}