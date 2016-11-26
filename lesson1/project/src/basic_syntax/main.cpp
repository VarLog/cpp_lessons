#include <iostream>

class Widget {
   public:
    Widget() {
        // default constructor
        counter_ = 0;
    }

    Widget(int counter) {
        // constructor with parameter
        counter_ = counter;
    }

    ~Widget() {
        // destructor
    }

    int getCounter() const { return counter_; }
    void setCounter(int counter) { counter_ = counter; }

    void doWork() {
        if (counter_ <= 0) {
            return;
        }

        for (int i = counter_; i > 0; --i) {
            std::cout << "working... " << i << std::endl;
        }

        std::cout << "done" << std::endl;
    }

   private:
    int counter_;
};

int main(int, char**) {
    Widget w;

    w.setCounter(10);
    w.doWork();

    return 0;
}
