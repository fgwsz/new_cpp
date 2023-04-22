#include"any.h"
#include"memory.h" // gf_memory_alloc() gf_memory_free() gf_memory_copy()
tt_boolean gf_any_construct(tt_any* lv_this) {
	if (lv_this == NULL) {
		return ev_boolean_false;
	}
	if (lv_this->mv_data != NULL) {
		gf_memory_free(lv_this->mv_data);
	}
	lv_this->mv_data = NULL;
	lv_this->mv_byte_size = 0;
	return ev_boolean_true;
}
tt_boolean gf_any_destory(tt_any* lv_this) {
	if (lv_this == NULL) {
		return ev_boolean_false;
	}
	if (lv_this->mv_data != NULL) {
		gf_memory_free(lv_this->mv_data);
	}
	return ev_boolean_true;
}
tt_boolean gf_any_set_value(
	tt_any* lv_this,
	void const* lv_value_address,
	size_t lv_byte_size
) {
	if (lv_this == NULL) {
		return ev_boolean_false;
	}
	if (lv_value_address == NULL || lv_byte_size == 0) {
		return gf_any_construct(lv_this);
	}
	if (lv_this->mv_byte_size < lv_byte_size) {
		if (lv_this->mv_data != NULL) {
			gf_memory_free(lv_this->mv_data);
		}
		lv_this->mv_data = gf_memory_alloc(lv_byte_size);
	}
	lv_this->mv_byte_size = lv_byte_size;
	gf_memory_copy(lv_this->mv_data, lv_value_address, lv_byte_size);
	return ev_boolean_true;
}
tt_boolean gf_any_get_value(
	tt_any const* lv_this,
	void* lv_value_address
) {
	if (lv_this == NULL || lv_value_address == NULL) {
		return ev_boolean_false;
	}
	gf_memory_copy(lv_value_address, lv_this->mv_data, lv_this->mv_byte_size);
	return ev_boolean_true;
}
tt_boolean gf_any_assign(
	tt_any* lv_this,
	tt_any const* lv_any_ref
) {
	if (lv_this == NULL || lv_any_ref == NULL) {
		return ev_boolean_false;
	}
	return gf_any_set_value(lv_this, lv_any_ref->mv_data, lv_any_ref->mv_byte_size);
}