#include <iostream>

using namespace std;

class Transport {
public:
    virtual void deliver() = 0;
};

class Car : public Transport {
public:
    void deliver() override {
        cout << "Delivering by car" << endl;
    }
};

class Truck : public Transport {
public:
    void deliver() override {
        cout << "Delivering by truck" << endl;
    }
};

class Train : public Transport {
public:
    void deliver() override {
        cout << "Delivering by train" << endl;
    }
};

class TransportFactory {
public:
    static Transport* create(const string& type) {
        if (type == "car") {
            return new Car();
        }
        else if (type == "truck") {
            return new Truck();
        }
        else if (type == "train") {
            return new Train();
        }
        else {
            return nullptr;
        }
    }
};

int main() {
    Transport* transport = TransportFactory::create("car");
    transport->deliver();

    transport = TransportFactory::create("truck");
    transport->deliver();

    transport = TransportFactory::create("train");
    transport->deliver();

    return 0;
}

