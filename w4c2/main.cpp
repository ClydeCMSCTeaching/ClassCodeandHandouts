#include <iostream>
#include <vector>

#include "Vehicle.hpp"
#include "Car.hpp"
#include "ElecCar.hpp"

int main() {
    Car c1 = Car(2, 3, 4);
    c1.setNum_doors(4);

    ElecCar ec;

    std::vector<Car*> parkingLot;

    parkingLot.push_back(&c1);
    parkingLot.push_back(&ec);


    parkingLot[0]->whoami();
    std::cout << std::endl;
    parkingLot[1]->whoami();
    std::cout << std::endl;


    std::cout << *parkingLot[0] << std::endl;
    std::cout << *parkingLot[1] << std::endl;

 
}