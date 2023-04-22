// C language naming convention
// Header file:					HF_{HEADER_FILE_PATH}
// Macro:						M_{MACRO_NAME}
// Macro function:				MF_{MACRO_FUNTION_NAME}()
// Macro function parameter:	MFP_{MACRO_FUNTION_PARAMETER_NAME}
// Global variable:				gv_{global_variable_name}
// Local variable:				lv_{local_variable_name}
// Member variable:				mv_{member_variable_name}
// Global function:				gf_{global_function_name}
// Local function:				lf_{global_function_name}
// Struct type:					st_{struct_type_name}
// Union type:					ut_{union_type_name}
// Typedef type:				tt_{typedef_type_name}
// Enum type:					et_{enum_type_name}
// Enum value:					ev_{enum_type_name}_{enum_value}
// Goto tag:					gt_{goto_tag_name}
#ifndef HF_NAMING_CONVENTION_H
#define HF_NAMING_CONVENTION_H
#define MF_HEADER_FILE(MFP_HEADER_FILE_PATH) \
	HF_##MFP_HEADER_FILE_PATH
#define MF_MACRO(MFP_MACRO_NAME) \
	M_##MFP_MACRO_NAME
#define MF_MACRO_FUNCTION(MFP_MACRO_FUNCTION_NAME) \
	MF_##MFP_MACRO_FUNCTION_NAME
#define MF_MACRO_FUNTION_PARAMETER(MFP_MACRO_FUNCTION_PARAMETER_NAME) \
	MFP_##MFP_MACRO_FUNCTION_PARAMETER_NAME
#define MF_GLOBAL_VARIABLE(MFP_GLOBAL_VARIABLE_NAME) \
	gv_##MFP_GLOBAL_VARIABLE_NAME
#define MF_LOCAL_VARIABLE(MFP_LOCAL_VARIABLE_NAME) \
	lv_##MFP_LOCAL_VARIABLE_NAME
#define MF_MEMBER_VARIABLE(MFP_MEMBER_VARIABLE_NAME) \
	mv_##MFP_MEMBER_VARIABLE_NAME
#define MF_GLOBAL_FUNCTION(MFP_GLOBAL_FUNCTION_NAME) \
	gf_##MFP_GLOBAL_FUNCTION_NAME
#define MF_LOCAL_FUNCTION(MFP_LOCAL_FUNCTION_NAME) \
	lf_##MFP_LOCAL_FUNCTION_NAME
#define MF_STRUCT_TYPE(MFP_STRUCT_TYPE_NAME) \
	st_##MFP_STRUCT_TYPE_NAME
#define MF_UNION_TYPE(MFP_UNION_TYPE_NAME) \
	ut_##MFP_UNION_TYPE_NAME
#define MF_ENUM_TYPE(MFP_ENUM_TYPE_NAME) \
	et_##MFP_ENUM_TYPE_NAME
#define MF_TYPEDEF_TYPE(MFP_TYPEDEF_TYPE_NAME) \
	tt_##MFP_TYPEDEF_TYPE_NAME
#define MF_ENUM_VALUE(MFP_ENUM_TYPE_NAME,MFP_ENUM_VALUE) \
	ev_##MFP_ENUM_TYPE_NAME##MFP_ENUM_VALUE
#define MF_GOTO_TAG(MFP_GOTO_TAG_NAME) \
	gt_##MFP_GOTO_TAG_NAME
#endif // !HF_NAMING_CONVENTION_H
