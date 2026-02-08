#define GLUE(a, b) a##b

#define STATIC_ASSERT(cond) typedef char GLUE(static_assertion_failed, __LINE__)[(cond) ? 1 : -1]
