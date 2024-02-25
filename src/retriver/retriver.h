


cJSON * private_cjson_path_get_cJSON_by_vargs(int *error_code,cJSON *element, const char *format, va_list args);


cJSON * cjson_path_get_cJSON(int *error_code,cJSON *element, const char *format, ...);

const char * cjson_path_get_str(int *error_code,cJSON *element,const char *format, ...);

double cjson_path_get_double(int *error_code,cJSON *element,const char *format, ...);

int cjson_path_get_int(int *error_code,cJSON *element,const char *format, ...);

bool cjson_path_get_bool(int *error_code,cJSON *element,const char *format, ...);

int cjson_path_type(cJSON *element,const char *format, ...);