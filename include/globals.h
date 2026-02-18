#define GLUE(a, b) a##b

#define STATIC_ASSERT(cond) typedef char GLUE(static_assertion_failed, __LINE__)[(cond) ? 1 : -1]

typedef __int64 longlong; 

typedef unsigned char uchar;
typedef unsigned short ushort; 
typedef unsigned int uint; 
typedef unsigned long ulong; 
typedef unsigned __int64 ulonglong; 