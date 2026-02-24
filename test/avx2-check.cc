/* avx2_check.c - FreeBSD
 * clang -O2 -Wall avx2_check.c -o avx2_check
 */

#include <sys/types.h>
#include <sys/syscall.h>
#include <unistd.h>
#include <stdint.h>

// int syscall(int, ...);

static inline void
cpuid(uint32_t leaf, uint32_t subleaf,
      uint32_t *a, uint32_t *b,
      uint32_t *c, uint32_t *d)
{
    __asm__ volatile (
        "cpuid"
        : "=a"(*a), "=b"(*b), "=c"(*c), "=d"(*d)
        : "a"(leaf), "c"(subleaf)
    );
}

static inline uint64_t
xgetbv(uint32_t index)
{
    uint32_t eax, edx;
    __asm__ volatile (
        "xgetbv"
        : "=a"(eax), "=d"(edx)
        : "c"(index)
    );
    return ((uint64_t)edx << 32) | eax;
}

static void
write_str(const char *s, size_t len)
{
    syscall(SYS_write, 1, s, len);
}

int
main(void)
{
    uint32_t a, b, c, d;

    /* CPUID leaf 1 */
    cpuid(1, 0, &a, &b, &c, &d);

    if (!(c & (1u << 27))) { /* OSXSAVE */
        write_str("\033[31m[ERROR] OSXSAVE not supported\n\033[0m", 40);
        return 1;
    }

    if (!(c & (1u << 28))) { /* AVX */
        write_str("\033[31m[ERROR] AVX not supported\n\033[0m", 36);
        return 2;
    }

    /* CPUID leaf 7 */
    cpuid(7, 0, &a, &b, &c, &d);

    if (!(b & (1u << 5))) { /* AVX2 */
        write_str("\033[31m[ERROR] AVX2 not supported by CPU\n\033[0m", 45);
        return 3;
    }

    /* XCR0 check */
    uint64_t xcr0 = xgetbv(0);
    if ((xcr0 & 0x06) != 0x06) {
        write_str("\033[31m[ERROR] AVX YMM state not enabled by OS\n\033[0m", 52);
        return 4;
    }

    write_str("\033[32m[OK] AVX2 is supported and enabled\n\033[0m", 44);
    return 0;
}
