#define BOOST_TEST_MODULE test_rock_util

#include <boost/test/unit_test.hpp>
#include <cstdio>
#include <fstream>
#include <base/samples/SonarScan.hpp>
#include <base/samples/Sonar.hpp>
#include <base/test_config.h>
#include "LogReader.hpp"

BOOST_AUTO_TEST_CASE(read_and_write_log_files)
{    
    std::string input_file = DATA_PATH_STRING + "/logs/gemini-ferry.0.log";
    std::string stream_name = "gemini.sonar_samples";
    rock_util::LogReader reader(input_file);
    rock_util::LogStream stream = reader.stream(stream_name);
    BOOST_TEST_MESSAGE("Reading the log samples...");
    while (stream.current_sample_index() < stream.total_samples()) {
        base::samples::Sonar sonar_sample;
        BOOST_ASSERT(stream.next<base::samples::Sonar>(sonar_sample) == true);
    }
}
