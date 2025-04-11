#include <iostream>
#include <memory>
#include <vector>

void Task1() {
    for (int i = 0; i < 1e8 * 5; i++) {
        int *a = new int(1);
        //delete a;
    }
}

void Task2() {
    for (int i = 0; i < 1e8 * 3; i++) {
        auto safePtr = std::make_unique<int>(1);
    }
}

class MyClass {
public:
    MyClass() : data(nullptr){}
    explicit MyClass(int s) : data(std::make_unique<int>(s)){};
    MyClass& operator=(const MyClass& a) {
        data = std::make_unique<int>(*a.data);
    }
    ~MyClass() = default;

    std::string check_status() {
        if (data == nullptr)
            return "Error";
        else
            return "OK";
    }

private:
    std::unique_ptr<int> data;
};

void fortask3(std::shared_ptr<int> &a, int p = 0) {
    if (p == 200) return;
    auto copy = a;
    std::cout << "Use count: " << a.use_count() << "\n";
    fortask3(copy, p + 1);
    std::cout << "Use count: " << a.use_count() << "\n";
}
void Task3() {
    auto shr = std::make_shared<int>(100);
    std::cout << "Use count: " << shr.use_count() << std::endl;
    fortask3(shr);
    std::cout << "Use count: " << shr.use_count() << std::endl;
}

void Task4() {
    auto shr = std::make_shared<int>(100);
    std::weak_ptr<int> weak = shr;

    if (auto locked = weak.lock()) {
        std::cout << "alive: " << *locked << std::endl;
    } else {
        std::cout << "dead" << std::endl;
    }

    shr.reset();

    if (auto locked = weak.lock()) {
        std::cout << "alive: " << *locked << std::endl;
    } else {
        std::cout << "dead" << std::endl;
    }
}

int main() {
    Task4();


    return 0;
}
