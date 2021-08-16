#include <iostream>
#include <vector>


template<typename T>
void modifyArray(std::vector<T>& myVec) {
    myVec.push_back(86);
}

struct MyRandomType{
    char a;
};

char toUpperCaseFromLowerCase(char a) {
    if (a > 95)
        return a -  32;
    else:
        return a;
}


int main() {
    std::vector<float> myVec = {1, 2, 3};


    std::cout << "This is before our function call" << std::endl;
    for (int i = 0; i < myVec.size(); i++ ) {
        auto item = myVec[i];
        std::cout << "item " << item << std::endl;
    }

    modifyArray(myVec);

    std::cout << "\nThis is before our function call" << std::endl;
    for (auto item : myVec) {
        std::cout << "item " << item << std::endl;
    }




    std::vector<char> myVecc = {'a', 'b', 'c'};

    modifyArray(myVecc);
    std::cout << "\nThis should be chars...." << std::endl;
    for (auto item : myVecc) {
        std::cout << "item " << item << std::endl;
    }



    std::cout << "\n c in caps is " << toUpperCaseFromLowerCase('c') << std::endl;




    MyRandomType myobj = new MyRandomType();
    delete myobj;


}