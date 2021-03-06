#ifndef _bl_overlap_h_

#ifndef _STDIO_H_
#include <stdio.h>
#endif

#ifndef _INTTYPES_H_
#include <inttypes.h>
#endif

#ifndef _biolibc_h_
#include "biolibc.h"
#endif

// 1-based, inclusive at both ends
typedef struct
{
    uint64_t    feature1_len;
    uint64_t    feature2_len;
    uint64_t    overlap_start;
    uint64_t    overlap_end;
    uint64_t    overlap_len;
}   bl_overlap_t;

/*
 *  Generated by /home/bacon/scripts/gen-get-set
 *
 *  Accessor macros.  Use these to access structure members from functions
 *  outside the bl_overlap_t class.
 *
 *  These generated macros are not expected to be perfect.  Check and edit
 *  as needed before adding to your code.
 */

#define BL_OVERLAP_FEATURE1_LEN(ptr)    ((ptr)->feature1_len)
#define BL_OVERLAP_FEATURE2_LEN(ptr)    ((ptr)->feature2_len)
#define BL_OVERLAP_OVERLAP_START(ptr)   ((ptr)->overlap_start)
#define BL_OVERLAP_OVERLAP_END(ptr)     ((ptr)->overlap_end)
#define BL_OVERLAP_OVERLAP_LEN(ptr)     ((ptr)->overlap_len)

/*
 *  Generated by /home/bacon/scripts/gen-get-set
 *
 *  Mutator macros for setting with no sanity checking.  Use these to
 *  set structure members from functions outside the bl_overlap_t
 *  class.  These macros perform no data validation.  Hence, they achieve
 *  maximum performance where data are guaranteed correct by other means.
 *  Use the mutator functions (same name as the macro, but lower case)
 *  for more robust code with a small performance penalty.
 *
 *  These generated macros are not expected to be perfect.  Check and edit
 *  as needed before adding to your code.
 */

#define BL_OVERLAP_SET_FEATURE1_LEN(ptr,val)    ((ptr)->feature1_len = (val))
#define BL_OVERLAP_SET_FEATURE2_LEN(ptr,val)    ((ptr)->feature2_len = (val))
#define BL_OVERLAP_SET_OVERLAP_START(ptr,val)   ((ptr)->overlap_start = (val))
#define BL_OVERLAP_SET_OVERLAP_END(ptr,val)     ((ptr)->overlap_end = (val))
#define BL_OVERLAP_SET_OVERLAP_LEN(ptr,val)     ((ptr)->overlap_len = (val))

/* overlap.c */
int bl_overlap_set_all(bl_overlap_t *overlap, uint64_t feature1_len, uint64_t feature2_len, uint64_t overlap_start, uint64_t overlap_end);
int bl_overlap_print(FILE *stream, bl_overlap_t *overlap, char *feature1_name, char *feature2_name);

/* overlap-mutators.c */
int bl_overlap_set_feature1_len(bl_overlap_t *bl_overlap_ptr, uint64_t new_feature1_len);
int bl_overlap_set_feature2_len(bl_overlap_t *bl_overlap_ptr, uint64_t new_feature2_len);
int bl_overlap_set_overlap_start(bl_overlap_t *bl_overlap_ptr, uint64_t new_overlap_start);
int bl_overlap_set_overlap_end(bl_overlap_t *bl_overlap_ptr, uint64_t new_overlap_end);
int bl_overlap_set_overlap_len(bl_overlap_t *bl_overlap_ptr, uint64_t new_overlap_len);

#endif // _bl_overlap_h_
