#include <iostream>
#include <cmath>
struct Point{
    double x;
    double y;

    std::string to_s() const{
        return "(" + std::to_string(x) + ", " + std::to_string(y) + ")";
    }
    double distance(Point p) const {
        return std::sqrt(std::pow((x - p.x), 2) + std::pow((y - p.y), 2));
    }
};
struct Triangle{
    Point a;
    Point b;
    Point c;

    double perimeter() const{
        return a.distance(b)+a.distance(c)+b.distance(c);
    }


};
int main() {

    Triangle t;
    std::cout << "Please enter the X and Y coordinates of the 1st point of the triangle:" << std::endl;
    std::cin>>t.a.x>>t.a.y;
    std::cout << "Please enter the X and Y coordinates of the 2nd point of the triangle:" << std::endl;
    std::cin>>t.b.x>>t.b.y;
    std::cout << "Please enter the X and Y coordinates of the 3rd point of the triangle:" << std::endl;
    std::cin>>t.c.x>>t.c.y;

    std::cout<<"The perimeter is : "<< t.perimeter()<< std::endl;

}
