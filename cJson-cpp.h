#pragma once

#ifdef __cplusplus
extern "C"
{
#endif
#include "cJSON.h"
#include "cJSON_internal.h"

cJSON_bool parse_number_impl(cJSON* const item, parse_buffer* const input_buffer);
cJSON_bool parse_string_impl(cJSON * const item, parse_buffer * const input_buffer);

unsigned parse_hex4_impl(const unsigned char * const input);

#ifdef __cplusplus
}
#endif
