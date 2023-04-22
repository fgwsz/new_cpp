#ifndef HF_EXTERN_C_H
#define HF_EXTERN_C_H
#ifdef __cplusplus
	#define M_EXTERN_C_BEGIN extern "C" {
	#define M_EXTERN_C_END   }
#else
	#define M_EXTERN_C_BEGIN 
	#define M_EXTERN_C_END   
#endif
#endif // !HF_EXTERN_C_H
