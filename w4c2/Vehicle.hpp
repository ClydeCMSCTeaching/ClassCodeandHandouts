#ifndef VEHICLE_HPP
#define VEHICLE_HPP

#include <iostream>

//classes = structs except everything is default private
class Vehicle {
public:

    Vehicle() : speed(0), capacity(0), mass(0) {};
    Vehicle(int speed, int capacity, int mass);

    //moves starting at pos 0, and returns where it ends up after 1 timestep
    int moves() {return moves(0);};
    int moves(int from_spot);

    int getMass() const {return mass;};
    int getCapacity() const {return capacity;};
    int getSpeed() const {return speed;};


    virtual void whoami() = 0;


protected:
    int speed;
    int capacity; //in terms of mass
    int mass; // weight of the vehicle.
};

Vehicle::Vehicle(int speed, int capacity_, int mass) {
    this->speed = speed;
    capacity = capacity_;
    this->mass = mass;
}

std::ostream& operator<<(std::ostream &os, Vehicle const& v) {
    os << "I am a Vehcile with speed " << v.getSpeed()
              << ", capacity " << v.getCapacity()
              << ", mass " << v.getMass() << ".";
    return os;
}

#endif