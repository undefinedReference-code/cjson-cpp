#pragma once
#include <locale.h>
typedef struct internal_hooks
{
    void* (CJSON_CDECL* allocate)(size_t size);
    void (CJSON_CDECL* deallocate)(void* pointer);
    void* (CJSON_CDECL* reallocate)(void* pointer, size_t size);
} internal_hooks;

typedef struct
{
    const unsigned char* content;
    size_t length;
    size_t offset;
    size_t depth; /* How deeply nested (in arrays/objects) is the input at the current offset. */
    internal_hooks hooks;
} parse_buffer;


/* check if the given size is left to read in a given parse buffer (starting with 1) */
#define can_read(buffer, size) ((buffer != NULL) && (((buffer)->offset + size) <= (buffer)->length))
/* check if the buffer can be accessed at the given index (starting with 0) */
#define can_access_at_index(buffer, index) ((buffer != NULL) && (((buffer)->offset + index) < (buffer)->length))
#define cannot_access_at_index(buffer, index) (!can_access_at_index(buffer, index))
/* get a pointer to the buffer at the position */
#define buffer_at_offset(buffer) ((buffer)->content + (buffer)->offset)
