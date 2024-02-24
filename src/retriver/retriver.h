
int private_cjson_path_validate_path(cJSON *path);


cJSON * cjson_path_get_cJSON_by_vargs(cJSON *element, const char *format, va_list args);

cJSON * cjson_path_get_cJSON(cJSON *element, const char *format, ...);

const char * cjson_path_get_str(cJSON *element,const char *format, ...);
