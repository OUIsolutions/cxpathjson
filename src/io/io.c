



char *privatecjson_path_read_file(const char *filename) {
    FILE *file = fopen(filename, "r");

    if (file == NULL) {
        return NULL;
    }

    fseek(file, 0, SEEK_END);
    long file_size = ftell(file);
    fseek(file, 0, SEEK_SET);


    char *buffer = (char *)malloc(file_size + 1);


    fread(buffer, 1, file_size, file);
    buffer[file_size] = '\0';
    fclose(file);
    return buffer;
}

int  privatecjson_path_write_file(const char *filename, const char *value) {

    FILE *file = fopen(filename, "w");

    if (file == NULL) {
        return 1;
    }
    fputs(value, file);

    fclose(file);
    return 0;
}


cjson_path * cjson_path_load_from_string(const char *data){
    return cJSON_Parse(data);
}

cjson_path * cjson_path_load_from_file(const char *filename){
    char *content = privatecjson_path_read_file(filename);
    if(!content){
        return NULL;
    }

    cjson_path *result = cjson_path_load_from_string(content);
    free(content);
    return result;
}