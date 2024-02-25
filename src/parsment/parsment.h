

cJSON * cxpathjson_load_from_string(int *error_code, const char *data);

cJSON * cxpathjson_load_from_file(int *error_code, const char *path);


char *cxpathjson_dump_to_string(cJSON *element, bool ident);

int cxpathjson_dump_to_file(const char *filename, cJSON *element, bool ident);


void cxpathjson_free(cJSON *data);

