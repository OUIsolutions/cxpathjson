

cJSON * private_cxpathjson_cJSON_by_cjson_path_list(int *error_code, cJSON *element, cJSON *path_list);


cJSON * private_cxpathjson_get_cJSON_by_vargs(int *error_code, cJSON *element, const char *format, va_list args);


cJSON * cxpathjson_get_cJSON(int *error_code, cJSON *element, const char *format, ...);

const char * cxpathjson_get_str(int *error_code, cJSON *element, const char *format, ...);

double cxpathjson_get_double(int *error_code, cJSON *element, const char *format, ...);

int cxpathjson_get_int(int *error_code, cJSON *element, const char *format, ...);

bool cxpathjson_get_bool(int *error_code, cJSON *element, const char *format, ...);

int cxpathjson_type(cJSON *element, const char *format, ...);

int cxpathjson_size(int *error_code, cJSON *element, const char *format, ...);
