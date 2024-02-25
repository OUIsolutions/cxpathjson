
int private_cjson_path_set_cjson_by_path_list(cJSON *element,cJSON *value,cJSON *path_list);


int private_cjson_path_set_cjson_by_va_arg(cJSON *element,cJSON *value,const char *format, va_list args);


int cjson_path_set_cjson(cJSON *element,cJSON *value,const char *format,...);

int cjson_path_set_str(cJSON *element,const char *string,const char *format,...);
