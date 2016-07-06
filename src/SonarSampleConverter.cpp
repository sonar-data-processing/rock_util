#include <cmath>
#include "sonar_util/Converter.hpp"
#include "rock_util/SonarSampleConverter.hpp"
#include "rock_util/Utilities.hpp"
#include "base/MathUtil.hpp"

using namespace sonar_util;
using namespace base;

namespace rock_util {

cv::Mat SonarSampleConverter::convert2raw(const base::samples::SonarScan& sonar, uint32_t frame_width, uint32_t frame_height, color_palletes::PalleteType pallete_type) {
    std::vector<float> data;
    data.resize(sonar.data.size());
    std::transform(sonar.data.begin(), sonar.data.end(), data.begin(), std::bind2nd(std::divides<float>(), 255));
    return Converter::convert2raw(data, sonar.number_of_beams, sonar.number_of_bins, frame_width, frame_height, pallete_type);
}

cv::Mat SonarSampleConverter::convert2raw(const base::samples::Sonar& sonar, uint32_t frame_width, uint32_t frame_height, color_palletes::PalleteType pallete_type) {
    return Converter::convert2raw(sonar.bins, sonar.beam_count, sonar.bin_count, frame_width, frame_height, pallete_type);
}

cv::Mat SonarSampleConverter::convert2polar(const base::samples::SonarScan& sonar, uint32_t frame_height, color_palletes::PalleteType pallete_type) {
    return Converter::convert2polar(sonar.data, sonar.number_of_beams, sonar.number_of_bins, sonar.start_bearing.rad, sonar.angular_resolution.rad, frame_height, pallete_type);
}

cv::Mat SonarSampleConverter::convert2polar(const base::samples::Sonar& sonar,
                                            uint32_t frame_width, uint32_t frame_height,
                                            std::vector<int> beam_mapping, color_palletes::PalleteType pallete_type) {
    return Converter::convert2polar(sonar.bins, Utilities::get_radians(sonar.bearings), sonar.bin_count, sonar.beam_count, frame_width, frame_height, beam_mapping, pallete_type);
}

cv::Mat SonarSampleConverter::convert2polar(const base::samples::Sonar& sonar,
                                            uint32_t frame_height,
                                            std::vector<int> beam_mapping,
                                            color_palletes::PalleteType pallete_type) {
    uint32_t frame_width = MathUtil::aspect_ratio_width(sonar.bearings[sonar.bearings.size()-1].rad, frame_height);
    return Converter::convert2polar(sonar.bins, Utilities::get_radians(sonar.bearings), sonar.bin_count, sonar.beam_count, frame_width, frame_height, beam_mapping, pallete_type);
}

std::vector<int> SonarSampleConverter::generate_beam_mapping(const base::samples::Sonar& sonar, int frame_width, int frame_height) {
    return Converter::generate_beam_mapping(sonar.bins, Utilities::get_radians(sonar.bearings), sonar.bin_count, sonar.beam_count, frame_width, frame_height);
}

std::vector<int> SonarSampleConverter::generate_beam_mapping_from_cartesian(const base::samples::Sonar& sonar, int frame_width, int frame_height) {
    return Converter::generate_beam_mapping_from_cartesian(sonar.bins, Utilities::get_radians(sonar.bearings), sonar.bin_count, sonar.beam_count, frame_width, frame_height);
}

}
