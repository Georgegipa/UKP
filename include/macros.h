#define ARR_SIZE(X) sizeof(X)/sizeof(X[0])
#define force_inline __attribute((always_inline))
#define IF_TRUE(X) X ? 1 : 0