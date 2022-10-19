#include <iostream>
#include <string>

using namespace std;

class Shape {
public:
    virtual void draw() = 0;
};

class Rectangle : public Shape {
public:
    void draw() override {
        cout << "Inside Rectangle::draw() method." << endl;
    }
};

class Square : public Shape {
public:
    void draw() override {
        cout << "Inside Square::draw() method." << endl;
    }    
};

class Color {
public:
    virtual void fill() = 0;
};

class Red : public Color {
public:
    void fill() override {
        cout << "Inside Red::fill() method." << endl;
    }    
};

class Green : public Color {
public:
    void fill() override {
        cout << "Inside Green::fill() method." << endl;
    }    
};

// create abstract factory
class AbstractFactory {
public:
    virtual Color* getColor(string color) = 0;
    virtual Shape* getShape(string shape) = 0;
};

class ShapeFactory : public AbstractFactory {
public:
    Shape* getShape(string shape) override {
        if (shape.empty()) return nullptr;
        if (shape == "SQUARE") return new Square;
        if (shape == "RECTANGLE") return new Rectangle;
        return nullptr;
    } 
    Color* getColor(string color) override {
        return nullptr;
    }
};

class ColorFactory : public AbstractFactory {
public:
    Shape* getShape(string shape) override {
        return nullptr;
    } 
    Color* getColor(string color) override {
        if (color.empty()) return nullptr;
        if (color == "RED") return new Red;
        if (color == "GREEN") return new Green;
        return nullptr;
    }
};

class FactoryProducer {
public:
    static AbstractFactory* getFactory(string choice) {
        if (choice == "SHAPE") {
            return new ShapeFactory;
        } else if (choice == "COLOR") {
            return new ColorFactory;
        }
        return nullptr;
    }
};

int main() {
    AbstractFactory* shapeFactory = FactoryProducer::getFactory("SHAPE");
    auto shape1 = shapeFactory->getShape("SQUARE");
    shape1->draw();

    AbstractFactory* colorFactory = FactoryProducer::getFactory("COLOR");
    auto color1 = colorFactory->getColor("RED");
    color1->fill();
    return 0;
}