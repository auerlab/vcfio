// FIXME: Are there limits defined by the VCF format?
#define VCF_ID_MAX_CHARS            256
// FIXME: What's the real maximum?  Maybe 3 since there are only 3 alternate
// alleles possible with standard bases?
#define VCF_DUP_CALL_MAX            10

// Error codes should be negative so vcf_read_calls_for_position() can
// return a positive call count
#define VCF_READ_OK                 0
#define VCF_READ_EOF                -1
#define VCF_READ_OVERFLOW           -2
#define VCF_READ_TRUNCATED          -3

/*
 *  vcfio is meant to provide a very simple and fast method for processing
 *  VCF streams one call at a time.  As such, there should generally be only
 *  one or a few vcf_call_t structures substantiated at a given moment, and
 *  we can afford to be generous with the max sizes.
 *  If you're writing programs that inhale many VCF calls into memory, vcfio
 *  is not for you.
 */

// Use different sizes for each so tsv_read_field() buffer overflow errors
// will point to a specific field.  Eventually should have tsv_read_field()
// return an error code rather than exit with an error message
#define VCF_CHROMOSOME_MAX_CHARS    256
#define VCF_POSITION_MAX_CHARS      32
#define VCF_REF_MAX_CHARS           34
#define VCF_ALT_MAX_CHARS           36
#define VCF_QUALITY_MAX_CHARS       38
#define VCF_FILTER_MAX_CHARS        64
// Yes, we actually saw INFO fields over 128k in some dbGap BCFs
#define VCF_INFO_MAX_CHARS          1048576
#define VCF_FORMAT_MAX_CHARS        4096
#define VCF_SAMPLE_MAX_CHARS        1024

#define VCF_CALL_INIT \
	{ \
	    "", "", "", "", "", "", "", "", "", NULL, 0 \
	}

// Access macros.  Separate interface from implementation, so client programs
// don't reference structure members explicitly.
#define VCF_CHROMOSOME(vcf_call)    ((vcf_call)->chromosome)
#define VCF_POS(vcf_call)           ((vcf_call)->pos)
#define VCF_POS_STR(vcf_call)       ((vcf_call)->pos_str)
#define VCF_ID(vcf_call)            ((vcf_call)->id)
#define VCF_REF(vcf_call)           ((vcf_call)->ref)
#define VCF_ALT(vcf_call)           ((vcf_call)->alt)
#define VCF_QUAL(vcf_call)          ((vcf_call)->quality)
#define VCF_FILTER(vcf_call)        ((vcf_call)->filter)
#define VCF_INFO(vcf_call)          ((vcf_call)->info)
#define VCF_FORMAT(vcf_call)        ((vcf_call)->format)
#define VCF_SAMPLE(vcf_call, index) ((vcf_call)->samples[index])
#define VCF_INFO_LEN(vcf_call)      ((vcf_call)->info_len)

typedef struct
{
    char    chromosome[VCF_CHROMOSOME_MAX_CHARS + 1],
	    pos_str[VCF_POSITION_MAX_CHARS + 1],
	    id[VCF_ID_MAX_CHARS + 1],
	    ref[VCF_REF_MAX_CHARS + 1],
	    alt[VCF_ALT_MAX_CHARS + 1],
	    quality[VCF_QUALITY_MAX_CHARS + 1],
	    filter[VCF_FILTER_MAX_CHARS + 1],
	    info[VCF_INFO_MAX_CHARS + 1],
	    format[VCF_FORMAT_MAX_CHARS + 1],
	    **samples;
    size_t  pos,
	    info_len;
    //int     ref_count,
    //        alt_count,
    //        other_count;
}   vcf_call_t;

typedef struct
{
    size_t      count;
    vcf_call_t  call[VCF_DUP_CALL_MAX];
}   vcf_calls_for_position_t;

// CentOS 7 gcc does not support restrict, which helps the optimizer produce
// faster code.  Keep _RESTRICT def separate from strlcpy() prototype in case
// other platforms are missing one but not the other.
#ifdef __linux__
#define _RESTRICT
#else
#define _RESTRICT   restrict
#endif

#ifdef __linux__
size_t strlcpy(char * _RESTRICT dest, const char * _RESTRICT src, size_t len);
#endif

#include "vcfio-protos.h"
#include "chromosome-name-cmp-protos.h"
