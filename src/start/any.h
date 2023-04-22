#ifndef HF_ANY_H
#define HF_ANY_H
#include"extern_c.h"
#include<stddef.h> // size_t
#include"boolean.h" // tt_boolean
M_EXTERN_C_BEGIN
typedef struct st_any {
	void* mv_data;
	size_t mv_byte_size;
}tt_any;
extern tt_boolean gf_any_construct(tt_any* lv_this);
extern tt_boolean gf_any_destory(tt_any* lv_this);
extern tt_boolean gf_any_set_value(
	tt_any* lv_this,
	void const* lv_value_address,
	size_t lv_byte_size
);
extern tt_boolean gf_any_get_value(
	tt_any const* lv_this, 
	void* lv_value_address
);
extern tt_boolean gf_any_assign(
	tt_any* lv_this,
	tt_any const* lv_any_ref
);
M_EXTERN_C_END
#endif//! HF_ANY_H