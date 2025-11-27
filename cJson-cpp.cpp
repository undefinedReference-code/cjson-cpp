#include "cJson-cpp.h"
extern "C" {
#include "cJSON_internal.h"
}

#include <charconv>
#include <system_error>
#include <limits>
#include "fast_float.h" 


cJSON_bool parse_number_impl(cJSON* const item, parse_buffer* const input_buffer)
{
    const char* current_ptr = reinterpret_cast<const char*>(buffer_at_offset(input_buffer));
    const char* end_ptr = reinterpret_cast<const char*>(input_buffer->content + input_buffer->length);


    if (current_ptr >= end_ptr) {
        return false;
    }

    if (*current_ptr == '+') {
        current_ptr++;
    }

    double number = 0.0;

    auto result = fast_float::from_chars(current_ptr, end_ptr, number);

    if (result.ec != std::errc()) {
        return false;
    }

    item->valuedouble = number;
    item->type = cJSON_Number;

    if (number >= static_cast<double>(std::numeric_limits<int>::max())) {
        item->valueint = std::numeric_limits<int>::max();
    }
    else if (number <= static_cast<double>(std::numeric_limits<int>::min())) {
        item->valueint = std::numeric_limits<int>::min();
    }
    else {
        item->valueint = static_cast<int>(number);
    }

    input_buffer->offset = static_cast<size_t>(result.ptr - reinterpret_cast<const char*>(input_buffer->content));

    return true;
}
