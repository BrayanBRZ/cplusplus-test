#include <iostream>
#include <memory>
#include <numbers>
#include <vector>

class Shape
{
public:
    virtual ~Shape() = default;
    virtual double area() const = 0;
};

class Rectangle : public Shape
{
public:
    Rectangle(double width, double height)
        : width_{width}
        , height_{height}
    {
    }

    double area() const override
    {
        return width_ * height_;
    }

private:
    double width_;
    double height_;
};

class Circle : public Shape
{
public:
    explicit Circle(double radius)
        : radius_{radius}
    {
    }

    double area() const override
    {
        return std::numbers::pi * radius_ * radius_;
    }

private:
    double radius_;
};

void printArea(const Shape& shape)
{
    std::cout << "area = " << shape.area() << '\n';
}

int main()
{
    std::vector<std::unique_ptr<Shape>> shapes;

    shapes.push_back(std::make_unique<Rectangle>(3.0, 4.0));
    shapes.push_back(std::make_unique<Circle>(2.0));

    for (const auto& shape : shapes) {
        printArea(*shape);
    }
}

