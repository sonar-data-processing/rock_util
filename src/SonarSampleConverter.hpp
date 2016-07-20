#ifndef ImageHelper_hpp
#define ImageHelper_hpp

#include <base/samples/Sonar.hpp>
#include <opencv2/opencv.hpp>
#include <sonar_util/ColorPalletes.hpp>

namespace rock_util {

class SonarSampleConverter {

public:

    static cv::Mat convert2raw (const base::samples::SonarScan& sonar,
                                uint32_t frame_width = 512, uint32_t  = 512,
                                sonar_util::color_palletes::PalleteType pallete_type = sonar_util::color_palletes::GRAY_PALLETE);

    static cv::Mat convert2raw(const base::samples::Sonar& sonar,
                               uint32_t frame_width = 512, uint32_t frame_height = 512,
                               sonar_util::color_palletes::PalleteType pallete_type = sonar_util::color_palletes::GRAY_PALLETE);

    static cv::Mat convert2polar(const base::samples::SonarScan& sonar,
                                 uint32_t frame_height = 512,
                                 sonar_util::color_palletes::PalleteType pallete_type = sonar_util::color_palletes::GRAY_PALLETE);

    static cv::Mat convert2polar(const base::samples::Sonar& sonar,
                                 uint32_t frame_height = 512,
                                 std::vector<int> beam_mapping = std::vector<int>(),
                                 sonar_util::color_palletes::PalleteType pallete_type = sonar_util::color_palletes::GRAY_PALLETE);


    static cv::Mat convert2polar(const base::samples::Sonar& sonar,
                                 uint32_t frame_width, uint32_t frame_height,
                                 std::vector<int> beam_mapping,
                                 sonar_util::color_palletes::PalleteType pallete_type = sonar_util::color_palletes::GRAY_PALLETE);

    static std::vector<int> generate_beam_mapping(const base::samples::Sonar& sonar,
                                                  int frame_width,
                                                  int frame_height);

    static std::vector<int> generate_beam_mapping_from_cartesian(const base::samples::Sonar& sonar,
                                                                 int frame_width,
                                                                 int frame_height);

};

} /* namespace rock_util */

#endif /* ImageHelper_hpp */
