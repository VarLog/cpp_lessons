#include <iostream>

class Transport {
   public:
    virtual void addFuel(int fuel_count) = 0;
    virtual void startEngine() = 0;

    virtual ~Transport() = default;
};

class Car : public Transport {
   public:
    Car() : Transport(), fuel_(0) {}

    void addFuel(int fuel_count) override {
        static const int kFuelLimit = 50;
        fuel_ += fuel_count;
        fuel_ = std::min(fuel_, kFuelLimit);
    }

    void startEngine() override {
        if (fuel_ > 0) {
            // Запуск
            // engine->start();
            std::cout << "Car engine started" << std::endl;
        }
    }

   private:
    int fuel_;
};

class Plane : public Transport {
   public:
    Plane() : Transport(), fuel_tank1_(0), fuel_tank2_(0) {}

    void addFuel(int fuel_count) override {
        const static int kFuelLimitInTank = 1000;

        auto rest = 0;
        fuel_tank1_ += fuel_count;

        if (fuel_tank1_ > kFuelLimitInTank) {
            rest = fuel_tank1_ - kFuelLimitInTank;
            fuel_tank1_ = kFuelLimitInTank;
        }

        fuel_tank2_ += rest;
        fuel_tank2_ = std::min(fuel_tank2_, kFuelLimitInTank);
    }

    void startEngine() override {
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

void start(Transport *t) {
    t->addFuel(20);
    t->startEngine();
}

int main(int, char **) {
    Car *car = new Car();
    Plane *plane = new Plane();

    start(car);
    start(plane);

    delete car;
    delete plane;

    return 0;
}
