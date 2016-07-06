#ifndef SonarInfo_hpp
#define SonarInfo_hpp

#include <iostream>
#include <base/samples/SonarScan.hpp>
#include <base/samples/Sonar.hpp>

namespace rock_util {

class SonarInfo {

public:

    static void print_sonar_scan_data(const base::samples::SonarScan sample);
    static void print_sonar_data(const base::samples::Sonar sample);

private:

    SonarInfo() {
    }

    virtual ~SonarInfo() {
    }

};

}


#endif /* SonarInfo_hpp */
