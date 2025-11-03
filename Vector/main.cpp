#include <iostream>

#include "MyVector.h"

int main() {
    /*
         std::vector<int> vec1 = {1, 4, 4};
         std::vector vec7 = {"fe", "wef", "fe"};
         std::vector<int> vec2(5);
         std::vector<int> vec5(5, 34);
         std::vector<int> vec3;

         int arr[3] = {1,4,6};
         std::vector<int> vec4(std::begin(arr), std::end(arr));



         for (size_t i = 0; i < vec2.size(); ++i) {
             std::cout << vec1[i];
         }
    */

    MyVector<int> vec1 = {1,4,5,3,4};

    MyVector<int> vec2 = {1,3};
    vec1.swap(vec2);

    std::cout << vec1;

}
