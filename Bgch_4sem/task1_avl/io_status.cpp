#include "io_status.h"

const char* get_error_message(io_status err){
    switch(err){
        case io_status::open:
            return "failed to open file!";
        case io_status::format:
            return "wrong input format in file!";
        case io_status::eof:
            return "not enough data in file!";
        case io_status::memory:
            return "failed to allocate memory!";
        case io_status::success:
            return "";
        default:
            return "unknown";
    }
}