#ifndef LITHIUM_TYPES_FREEBSD_HH
#define LITHIUM_TYPES_FREEBSD_HH

#ifdef __FreeBSD__

// Types definition
namespace Lithium_Types {
    typedef int	*pInt_t;
    typedef int	*lpInt_t;

    typedef char *pChar_t;
    typedef char *lpChar_t;

    typedef bool *pBool_t;
    typedef bool *lpBool_t;

    typedef void *pVoid_t;
    typedef void *lpVoid_t;

    typedef float *pFloat_t;
    typedef float *lpFloat_t;
    
    typedef double *pDouble_t;
    typedef double *lpDouble_t;

    typedef void *pWindow_t;
    typedef void *lpWindow_t;

    constexpr pVoid_t Null_Ptr_t = (lpVoid_t)0;
}

#endif /* __FreeBSD__ */
#endif /* LITHIUM_TYPES_FREEBSD_HH */