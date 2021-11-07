#include<iostream>
#include <vector>

using namespace std;

int main() {
   
    vector<int> vec;
    cout << vec.size()<<endl;
    for (int i =0; i < 5; i++) {
        vec.push_back(i);
    }
    cout << vec.size()<<endl;


    vector<int>::iterator v  = vec.begin();

    while (v!=vec.end())
    {
        std::cout << *v << std::endl;
        /* code */
        v++;
    }
    



    return 1;
} 