#ifndef RPL_PLATFORM_CC_H_INCLUDED_
#define RPL_PLATFORM_CC_H_INCLUDED_

// Intel compiler.
#if defined(__INTEL_COMPILER)
#  define RPL_CC_INTEL

// Sun Studio/Sun Pro compiler.
#elif defined(__SUNPRO_C)
#  define RPL_CC_SUN

// Clang compiler.
#elif defined(__clang__)
#  define RPL_CC_CLANG

// GNU Compiler Collection.
#elif defined(__GNUC__)
#  define RPL_CC_GNU

// Microsoft compiler.
#elif defined(_MSC_VER)
#  define RPL_CC_MICROSOFT

// Unknown compiler.
#else
#  define RPL_CC_UNKNOWN

#endif

#endif
