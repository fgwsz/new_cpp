#ifndef HF_VECTOR_H
#define HF_VECTOR_H
#include"extern_c.h"
#include"any.h"
M_EXTERN_C_BEGIN
typedef struct st_vector {
	tt_any* mv_data;
	size_t mv_number_of_elements;
	size_t mv_capacity;
}tt_vector;
extern tt_boolean gf_vector_construct(tt_vector* lv_this);
extern tt_boolean gf_vector_assign(tt_vector* lv_this, tt_vector const* lv_vector_ref);
extern tt_boolean gf_vector_destory(tt_vector* lv_this);
extern tt_boolean gf_vector_insert(tt_vector* lv_this, size_t index, tt_any const* lv_value_ref);
extern tt_boolean gf_vector_erase(tt_vector* lv_this, size_t index);
extern tt_boolean gf_vector_set_element(tt_vector* lv_this, size_t index, tt_any const* lv_value_ref);
extern tt_boolean gf_vector_get_element(tt_vector* lv_this, size_t index, tt_any* lv_value_ref);
extern tt_boolean gf_vector_push_back(tt_vector* lv_this, tt_any const* lv_value_ref);
extern void gf_vector_pop_back(tt_vector* lv_this);
extern void gf_vector_clear(tt_vector* lv_this);
extern size_t gf_vector_size(tt_vector const* lv_this);
extern size_t gf_vector_capacity(tt_vector const* lv_this);
M_EXTERN_C_END
#endif // !HF_VECTOR_H