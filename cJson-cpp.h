#pragma once

#ifdef __cplusplus
extern "C"
{
#endif
#include "cJSON.h"
#include "cJSON_internal.h"

cJSON_bool parse_number_impl(cJSON* const item, parse_buffer* const input_buffer);

#ifdef __cplusplus
}
#endif
