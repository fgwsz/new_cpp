#include<stdlib.h> // malloc() free()
#include<string.h> // memset()
#include"memory.h"
void* gf_memory_alloc(size_t lv_byte_size) {
	if (lv_byte_size == 0) {
		return 0;
	}
	void* lv_result = NULL;
	while (1) {
		lv_result = malloc(lv_byte_size);
		if (lv_result != NULL) {
			break;
		}
		free(lv_result);
		lv_result = NULL;
	}
	gf_memory_set(lv_result, (unsigned char)0, lv_byte_size);
	return lv_result;
}
void gf_memory_free(void* lv_address) {
	if (lv_address == 0) {
		return;
	}
	free(lv_address);
}
void* gf_memory_set(
	void* lv_address, 
	unsigned char lv_byte_value, 
	size_t lv_byte_size
) {
	return memset(lv_address, (int)lv_byte_value, lv_byte_size);
}
void* gf_memory_copy(
	void* lv_to_address, 
	void const* lv_from_address, 
	size_t lv_byte_size
) {
	return memmove(lv_to_address, lv_from_address, lv_byte_size);
}
