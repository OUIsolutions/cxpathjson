

cJSON * cjson_path_load_from_string( int *error_code,const char *data);

cJSON * cjson_path_load_from_file( int *error_code,const char *path);


char *cjson_path_dump_to_string(cJSON *element,bool format);

int cjson_path_dump_to_file(const char *filename,cJSON *element,bool format);


void cjson_path_free(cJSON *data);

