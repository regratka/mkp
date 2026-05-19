#ifndef _GLOBAL
#define _GLOBAL

#define GLUE(a, b) a##b

#define STATIC_ASSERT(cond) typedef char GLUE(static_assertion_failed, __LINE__)[(cond) ? 1 : -1]

#if ME2
    #define DLLEXPORT __declspec(dllexport)
#else
    #define DLLEXPORT __declspec(dllimport)
#endif

typedef unsigned char uchar;
typedef unsigned short ushort; 
typedef unsigned int uint; 
typedef unsigned long ulong; 

typedef __int64 longlong; 
typedef unsigned __int64 ulonglong; 

typedef int BOOL;

#define DWORD_PTR DWORD // old 

#define NULL 0
#define TRUE 1
#define FALSE 0

#endif