#include <iostream>

using namespace std;

class Shape {
 private:
  double area;

 public:
  Shape() { this->area = 0; }
  double getArea() { return this->area; }
  void setArea(double area) { this->area = area; }
  void printArea() { cout << "Area: " << getArea() << '\n'; }
};

class Rectangle : public Shape {
 private:
  double l;
  double b;

 public:
  Rectangle(double l, double b) {
    this->l = l;
    this->b = b;
    setArea(this->l * this->b);
  }
};

class Circle : private Shape {
 private:
  double r;

 public:
  Circle(double r) {
    this->r = r;
    setArea(3.14 * this->r * this->r);
  }

  void printArea() { cout << "Area of circle: " << getArea() << '\n'; }
};

class Triangle : protected Shape {
 private:
  double b;
  double h;

 public:
  Triangle(double b, double h) {
    this->b = b;
    this->h = h;
    setArea(0.5 * this->b * this->h);
  }
  void printArea() { cout << "Area of triangle: " << getArea() << '\n'; }
};

class Sphere : public Shape {
 private:
  double r;

 public:
  Sphere(double r) {
    this->r = r;
    setArea((4 / 3) * 3.14 * r * r * r);
  }
};

int main() {
  Rectangle r(4, 5);
  r.printArea();

  Triangle t(4, 5);
  t.printArea();

  Circle c(5);
  c.printArea();

  Sphere s(5);
  s.printArea();

  return 0;
}

//Constructors

#include <iostream>

using namespace std;

class Area {
 private:
  double area;

 public:
Area::Area() { this->area = 0; }

Area::Area(double l, double b) { this->area = l * b; }

Area::Area(double b, float h) { this->area = 0.5 * b * h; }

Area::Area(double r) { this->area = 3.14 * r * r; }

Area::Area(float r) { this->area = (4 / 3) * 3.14 * r * r * r; }

};


int main() {
  cout << "\n Enter Radius of the Circle : ";
  double r;
  cin >> r;
  Area a1(r);
  cout << "Area of circle: " << a1.getArea() << "\n\n";

  cout << "\n Enter Length and Breadth of the Rectangle : ";
  double l, b;
  cin >> l >> b;
  Area a2(l, b);
  cout << "Area of rectangle: " << a2.getArea() << "\n\n";

  cout << "\n Enter Base and Height of Triangle : ";
  double base;
  float height;
  cin >> base >> height;
  Area a3(base, height);
  cout << "Area of triangle: " << a3.getArea() << "\n\n";

  cout << "\n Enter Radius of sphere : ";
  float rad;
  cin >> rad;
  Area a4(rad);
  cout << "Area of sphere: " << a4.getArea() << "\n\n";

  return 0;
}
