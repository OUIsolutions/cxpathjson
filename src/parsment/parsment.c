
cJSON * cjson_path_load_from_string(const char *data){
    cJSON  *result = cJSON_Parse(data);
    if(!result){
        private_cjson_path_error_code = CJSON_PATH_DOCUMENT_NOT_PARSABLE_CODE;
        private_cjson_path_error_message = CJSON_PATH_DOCUMENT_NOT_PARSABLE_MESSAGE;
    }
    return  result;
}

cJSON * cjson_path_load_from_file(const char *filename){
    char *content = privatecjson_path_read_file(filename);
    if(!content){
        private_cjson_path_error_code = CJSON_PATH_DOCUMENT_NOT_EXIST_CODE;
        private_cjson_path_error_message = CJSON_PATH_DOCUMENT_NOT_EXIST_MESSAGE;
        return NULL;
    }

    cJSON *result = cjson_path_load_from_string(content);
    free(content);
    return result;
}

void cjson_path_free(cJSON *data){
    cJSON_Delete(data);
}