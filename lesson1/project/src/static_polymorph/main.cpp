#include <iostream>

class Car {
   public:
    Car() : fuel_(0) {}

    void addFuel(int fuel_count) {
        static const int kFuelLimit = 50;

        fuel_ += fuel_count;
        fuel_ = std::min(fuel_, kFuelLimit);
    }

    void startEngine() {
        if (fuel_ > 0) {
            // Запуск
            // engine->start();
            std::cout << "Car engine started" << std::endl;
        }
    }

   private:
    int fuel_;
};

class Plane {
   public:
    void addFuel(int fuel_count) {
        static const int kFuelLimitInTank = 1000;

        auto rest = 0;
        fuel_tank1_ += fuel_count;

        if (fuel_tank1_ > kFuelLimitInTank) {
            rest = fuel_tank1_ - kFuelLimitInTank;
            fuel_tank1_ = kFuelLimitInTank;
        }

        fuel_tank2_ += rest;
        fuel_tank2_ = std::min(fuel_tank2_, kFuelLimitInTank);
    }

    void startEngine() {
        if (fuel_tank1_ > 0 || fuel_tank2_ > 0) {
            // Запуск
            // engine->start();
            std::cout << "Plane engine started" << std::endl;
        }
    }

   private:
    int fuel_tank1_;
    int fuel_tank2_;
};

template <class Transport>
void start(Transport&& t) {
    t.addFuel(20);
    t.startEngine();
}

int main(int, char**) {
    Car car;
    Plane plane;

    start(car);
    start(plane);

    return 0;
}
