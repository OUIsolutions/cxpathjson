

char *privatecjson_path_read_file(const char *filename);

int privatecjson_path_write_file(const char *filename, const char *value);

cjson_path * cjson_path_load_from_string(const char *data);

cjson_path * cjson_path_load_from_file(const char *data);

