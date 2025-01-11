#pragma once
#include <string>

constexpr double PI{3.14159265358979323846};

// Point class
class Point {
private:
  std::size_t x;
  std::size_t y;

public:
  Point(std::size_t x, std::size_t y) : x(x), y(y) {}
  Point(const Point&) = default;
  ~Point() = default;
};

// Shape class
class Shape {
private:
  std::string name;
  double area;

public:
  Shape(std::string name, double area) : name(std::move(name)), area(area) {}
  Shape(const Shape&) = default;
  ~Shape() = default;

  auto get_area() const -> double { return area; }
};

// Circle class
class Circle : public Shape {
private:
  Point center_point;
  std::size_t radius;

public:
  Circle(Point center_point, std::size_t radius)
      : Shape("Circle", (radius * radius) * PI), center_point(center_point),
        radius(radius) {}
  Circle(const Circle&) = default;
  ~Circle() = default;
};

// Square class
class Square : public Shape {
private:
  std::size_t length;

public:
  explicit Square(std::size_t length)
      : Shape("Square", length * length), length(length) {}
  Square(const Square&) = default;
  ~Square() = default;
};
