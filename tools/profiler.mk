include tools/config.mk
include tools/lib.mk

PROFILER		= llvm-profdata
PROFILER-INSTR	= -fprofile-instr-generate

.PHNOY: profiler-test
profiler-test:
	$()