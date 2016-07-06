#ifndef Utilities_hpp
#define Utilities_hpp

#include <base/Angle.hpp>

namespace rock_util {

class Utilities {

public:
    static std::vector<float> get_radians(const std::vector<base::Angle>& angles) {
        std::vector<float> radians;
        for (std::vector<base::Angle>::const_iterator it = angles.begin(); it != angles.end(); it++) radians.push_back(it->rad);
        return radians;
    }
};

}

#endif /* end of include guard: Utilities_hpp */
