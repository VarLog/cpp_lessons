#include <iostream>
#include <string>

// Класс, предоставляющий доступ к некому ресурсу (сокету, сетевому соединению)
class Handler {
    //...
   public:
    void connect(const std::string& addr) {
        // Установить соединение
        // ...
        std::cout << "Connection was established" << std::endl;
    };

    void close() {
        // Закрыть соединение
        // ...
        std::cout << "Connection was closed" << std::endl;
    }

    //...
};

class Widget {
   public:
    Widget(const std::string& addr) { handle_.connect(addr); }

    ~Widget() {
        // Освобождение ресурсов
        handle_.close();
    }

    void doWork() {
        // work with handle_
        std::cout << "working..." << std::endl;
    }

   private:
    Handler handle_;
};

int main(int, char**) {
    // Клиентский код. Ничего не знает про Handler внутри Widget
    {
        Widget w("iate.ru");

        w.doWork();
        std::cout << "done" << std::endl;
    }

    return 0;
}
