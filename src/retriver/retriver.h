
int private_cjson_path_validate_path(cJSON *path);


cJSON * private_cjson_path_get_cJSON_by_vargs(int *error_code,cJSON *element, const char *format, va_list args);


cJSON * cjson_path_get_cJSON(int *error_code,cJSON *element, const char *format, ...);

const char * cjson_path_get_str(int *error_code,cJSON *element,const char *format, ...);
