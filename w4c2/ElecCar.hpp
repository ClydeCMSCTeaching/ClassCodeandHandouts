#ifndef ELECCAR_HPP
#define ELECCAR_HPP

#include "Car.hpp"

class ElecCar : public Car {
public:
    ElecCar() = default;

    void whoami() override {std::cout << "ELEC CAR!";};
};


std::ostream& operator<<(std::ostream& os, ElecCar const& v) {
    os << "I am a ElecCar with speed " << v.getSpeed()
              << ", capacity " << v.getCapacity()
              << ", mass " << v.getMass() 
              << ", num doors " << v.getNum_doors() << ".";
    return os;
}


#endif