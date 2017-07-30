#include "SonarInfo.hpp"

namespace rock_util {

void SonarInfo::print_sonar_scan_data(const base::samples::SonarScan sample) {
    std::cout << "------------------------------------" << std::endl;
    std::cout << "angular_resolution: " << sample.angular_resolution << std::endl;
    std::cout << "start_bearing: " << sample.start_bearing << std::endl;
    std::cout << "number_of_beams: " << sample.number_of_beams << std::endl;
    std::cout << "number_of_bins: " << sample.number_of_bins << std::endl;
    std::cout << "sampling_interval: " << sample.sampling_interval << std::endl;
    std::cout << "beamwidth_horizontal: " << sample.beamwidth_horizontal << std::endl;
    std::cout << "beamwidth_vertical: " << sample.beamwidth_vertical << std::endl;
    std::cout << "speed_of_sound: " << sample.speed_of_sound << std::endl;
    std::cout << "data_size: " << sample.data.size() << std::endl;
    std::cout << "number_of_beams x number_of_bins: " << (sample.number_of_beams * sample.number_of_bins) << std::endl;
    std::cout << "beamwidth_horizontal / number_of_beams: " << (sample.beamwidth_horizontal.rad / sample.number_of_beams ) << std::endl;
}

void SonarInfo::print_sonar_data(const base::samples::Sonar sample) {
    std::cout << "------------------------------------" << std::endl;
    std::cout << "beam_width: " << sample.beam_width << std::endl;
    std::cout << "beam_height: " << sample.beam_height << std::endl;
    std::cout << "beam_count: " << sample.beam_count << std::endl;
    std::cout << "bin_count: " << sample.bin_count << std::endl;
    std::cout << "speed_of_sound: " << sample.speed_of_sound << std::endl;
}

}
