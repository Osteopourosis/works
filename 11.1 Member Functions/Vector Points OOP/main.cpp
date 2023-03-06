#include <iostream>
#include <cmath>
#include <string>
#include <vector>
#include <fstream>
#include <cstdlib>

struct Point{
    double x;
    double y;

    std::string to_s() const {
        return "(" + std::to_string(x) + ", " + std::to_string(y) + ")";
    }

    double distance(Point p) const{
        return std::sqrt(std::pow((x - p.x), 2) + std::pow((y - p.y), 2));
    }
};

// idxp1 and idxp2 are output parameters
// after the function call they will contain
// the indices of the two closest points in vp
// if vp contains two points or more
// (otherwise they will just contain uninitialised values)

void closest_points(const std::vector<Point>& vp, int& idxp1, int& idxp2){
    Point minidx;
    double minDist=99999,tmp;


    for(int i=0;i<vp.size();i++) {
        for (int j=0;j<vp.size();j++) {
            tmp=vp[i].distance(vp[j]);
            std::cout<<"Comparing "<<i<<" with "<<j<<" min value so far is :"<< minDist <<std::endl;

            if(tmp<minDist && tmp!=0){
                minDist=tmp;
                minidx.x=i;
                minidx.y=j;

            }
        }
    }

    idxp1=minidx.x;
    idxp2=minidx.y;

    std::cout<<idxp1<<std::endl;
    std::cout<<idxp2<<std::endl;


    // TODO:
    // complete this function
    // (make use of member function distance)
}


int main(){
    std::ifstream infile;
    infile.open("points.txt");

    if(!infile.is_open()){
        std::cout << "error opening file" << std::endl;
        return EXIT_FAILURE;
    }

    std::vector<Point> points;
    Point tmp;

    while(infile >> tmp.x >> tmp.y){
        points.push_back(tmp);
    }

    infile.close();


    if(points.size() == 0){
        std::cout << "there are no points in the file" << std::endl;
    }

    else if(points.size() == 1){
        std::cout << "there is only one point in the file" << std::endl;
    }
    else{
        int idxp1, idxp2;
        closest_points(points, idxp1, idxp2);

        // TODO:
        // print the two points
        // (make use of member function to_s)

        std::cout<< points[idxp1].to_s() <<std::endl;
        std::cout<< points[idxp2].to_s() <<std::endl;
    }



}
