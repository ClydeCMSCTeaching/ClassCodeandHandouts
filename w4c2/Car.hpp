#ifndef CAR_HPP
#define CAR_HPP

#include <iostream>
#include "Vehicle.hpp"

class Car : public Vehicle {
public:
    Car() = default;
    Car(int speed_, int mass_, int capacity_) : Vehicle(speed_,
                                                        mass_,
                                                        capacity_) {};
    Car(int speed_, int mass_, int capacity_, int num_doors_) : Vehicle(speed_,
                                                        mass_,
                                                        capacity_), num_doors(num_doors_) {};



    void setNum_doors(int i) {num_doors = i;};
    int getNum_doors() const {return num_doors;};

    void whoami() {std::cout << "I AM A CAR!!!";};

protected:
    int num_doors;
    
};

std::ostream& operator<<(std::ostream& os, Car const& v) {
    os << "I am a Car with speed " << v.getSpeed()
              << ", capacity " << v.getCapacity()
              << ", mass " << v.getMass() 
              << ", num doors " << v.getNum_doors() << ".";
    return os;
}



#endif