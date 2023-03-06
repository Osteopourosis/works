#include <iostream>
#include <cmath>
#include <string>
#include <vector>
#include <fstream>
#include <cstdlib>

class Point{

public:

    Point(double ix,double iy): x(ix) , y(iy){
    }

    Point(){
        x = 0;
        y = 0;
    }

    std::string to_s() const{
        return "(" + std::to_string(x) + ", " + std::to_string(y) + ")";
    }

    double distance(Point p) const{
        return std::sqrt(std::pow((x - p.x), 2) + std::pow((y - p.y), 2));
    }
    // note that we can access
    // the private member data x and y of p
    // even if it's a different object
    // because it's an instance of the same class

    double sum_distances_points(const std::vector<Point>& pv){
        double sum=0;

        if(pv.size()>1) {
            for (int i = 0; i < pv.size(); i++) {
                if (i + 1 <= pv.size() - 1) {
                    sum += pv[i].distance(pv[i + 1]);
                }
            }
        }
        return sum;
        // TODO: complete this function

    }
private:

    double x;
    double y;

};

double sum_distances_points(const std::vector<Point>& pv){
    double sum=0;

    if(pv.size()>1) {
        for (int i = 0; i < pv.size(); i++) {
            if (i + 1 <= pv.size() - 1) {
                sum += pv[i].distance(pv[i + 1]);
            }
        }
    }
    return sum;
    // TODO: complete this function

}

int main(){

    std::ifstream infile;
    infile.open("points.txt");

    if(!infile.is_open()){
        std::cout << "error opening file" << std::endl;
        return EXIT_FAILURE;
    }

    std::vector<Point> points;

    double inx, iny;



    while(infile >> inx >> iny){
        Point tmp(inx,iny);
        points.push_back(tmp);

        // TODO:
        // instantiate an object of type Point within this loop
        // passing inx and iny to its constructor
        // then add it to vector points
        // (since the instantiation happens within the loop
        //  a different object, although with the same name,
        //  will actually be instantiated at each iteration)
    }

    infile.close();

    std::cout << sum_distances_points(points) << std::endl;

}