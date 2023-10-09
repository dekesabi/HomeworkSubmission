#include <opencv2/opencv.hpp>
#include <Eigen/Dense>
#include "static_lib.hpp"
#include "shared_lib.hpp"
#include <iostream>
int main(){
    std::cout<<"opencv installed, version = "<<CV_VERSION<<std::endl;
    std::cout<<"Eigen installed, version = "<<EIGEN_WORLD_VERSION<<std::endl;
    CheckStaticLibrary();
    CheckSharedLibrary();
    return 0;
}