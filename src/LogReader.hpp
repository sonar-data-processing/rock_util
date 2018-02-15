#ifndef LogReader_hpp
#define LogReader_hpp

#include <cstring>
#include <string>
#include <pocolog_cpp/LogFile.hpp>
#include <pocolog_cpp/InputDataStream.hpp>

namespace rock_util {

class LogStream {
public:
    template <typename T>
    bool read_sample(T& sample, int sample_index) {
        memset(&sample, 0, sizeof(T));
        if (sample_index < total_samples()) {
            data_stream_->getSample<T>(sample, sample_index);
            return true;
        }
        return false;
    }
    template <typename T>
    bool next(T& sample) {
        return read_sample<T>(sample, current_sample_index_++);
    }

    void reset() {
        current_sample_index_ = 0;
    }

    size_t total_samples() {
        return data_stream_->getSize();
    }

    size_t current_sample_index() {
        return current_sample_index_;
    }

    void set_current_sample_index(size_t index) {
        current_sample_index_ = index;
    }

    LogStream()
        : data_stream_(NULL)
    {
    }

private:

    LogStream(pocolog_cpp::InputDataStream *data_stream)
        : data_stream_(data_stream)
        , current_sample_index_(0) {
    }

    pocolog_cpp::InputDataStream* data_stream_;
    size_t current_sample_index_;

    friend class LogReader;
};

class LogReader {
public:

    LogReader (const std::string& input_file_path)
        : log_file_(input_file_path)
    {
    }

    ~LogReader() {
    }

     LogStream stream(const std::string& stream_name) {
        try {
            return LogStream(dynamic_cast<pocolog_cpp::InputDataStream*>(&log_file_.getStream(stream_name)));
        } catch (...) {
            throw;
        }
        return LogStream();
    }

private:

    pocolog_cpp::LogFile log_file_;
};

}


#endif /* LogExtractor_hpp */
