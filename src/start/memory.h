#ifndef HF_MEMORY_H
#define HF_MEMORY_H
#include"extern_c.h"
#include<stddef.h> // size_t
M_EXTERN_C_BEGIN
extern void* gf_memory_alloc(size_t lv_byte_size);
extern void  gf_memory_free(void* lv_address);
extern void* gf_memory_set(
	void* lv_address,
	unsigned char lv_byte_value,
	size_t lv_byte_size
);
extern void* gf_memory_copy(
	void* lv_to_address,
	void const* lv_from_address,
	size_t lv_byte_size
);
M_EXTERN_C_END
#endif // !HF_MEMORY_H