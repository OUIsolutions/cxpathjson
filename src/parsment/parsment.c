
cJSON * cjson_path_load_from_string( int *error_code,const char *data){
    cJSON  *result = cJSON_Parse(data);
    if(!result){
        *error_code = CJSON_PATH_DOCUMENT_NOT_PARSABLE_CODE;
    }
    return  result;
}

cJSON * cjson_path_load_from_file( int *error_code,const char *path){
    char *content = privatecjson_path_read_file(path);
    if(!content){
        *error_code  = CJSON_PATH_DOCUMENT_NOT_EXIST_CODE;
        return NULL;
    }

    cJSON *result = cjson_path_load_from_string(error_code,content);
    free(content);
    return result;
}

void cjson_path_free(cJSON *data){
    cJSON_Delete(data);
}