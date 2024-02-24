
cJSON * cjson_path_load_from_string(const char *data){
    return cJSON_Parse(data);
}

cJSON * cjson_path_load_from_file(const char *filename){
    char *content = privatecjson_path_read_file(filename);
    if(!content){
        return NULL;
    }

    cJSON *result = cjson_path_load_from_string(content);
    free(content);
    return result;
}

void cjson_path_free(cJSON *data){
    cJSON_Delete(data);
}