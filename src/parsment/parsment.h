

cJSON * cjson_path_load_from_string( int *error_code,const char *data);

cJSON * cjson_path_load_from_file( int *error_code,const char *path);

void cjson_path_free(cJSON *data);
