int private_cjson_path_validate_path(cJSON *path){

    if(!path){
        return 1;
    }

    if(!cJSON_IsArray(path)){
        return 1;
    }

    int path_size = cJSON_GetArraySize(path);
    for(int i = 0;i <path_size;i++){
        cJSON *current = cJSON_GetArrayItem(path,i);
        if(cJSON_IsString(current)){
            continue;
        }

        if(cJSON_IsNumber(current)){
            continue;
        }
        return  1;
    }
    return  0;



}


cJSON * private_cjson_path_get_cJSON_by_vargs(int *error_code, cJSON *element, const char *format, va_list args){
    int size = vsnprintf(NULL, 0, format, args);
    char *buffer = (char *)malloc(size + 1);
    vsnprintf(buffer, size + 1, format, args);
    cJSON *parsed_path  = cJSON_Parse(buffer);
    free(buffer);
    if(private_cjson_path_validate_path(parsed_path)){
        *error_code = CJSON_PATH_ARG_PATH_NOT_VALID_CODE;
        cJSON_Delete(parsed_path);
        return  NULL;
    }

    cJSON *current_element = element;
    int path_size = cJSON_GetArraySize(parsed_path);
    for(int i = 0;i <path_size;i++){

        if(!current_element){
            break;
        }

        cJSON *current_path = cJSON_GetArrayItem(parsed_path,i);

        if(cJSON_IsString(current_path)){
            current_element = cJSON_GetObjectItem(current_element,current_path->valuestring);
        }


        if(cJSON_IsNumber(current_path)){
            current_element = cJSON_GetArrayItem(current_element,current_path->valueint);
        }


    }

    cJSON_Delete(parsed_path);

    if(!current_element){
        *error_code = CJSON_PATH_ELEMENT_PATH_NOT_EXIST_CODE;
        return  NULL;
    }
    return current_element;
}


cJSON *cjson_path_get_cJSON(int *error_code,cJSON *element, const char *format, ...) {
    va_list args;
    va_start(args, format);
    cJSON *result = private_cjson_path_get_cJSON_by_vargs(error_code, element,format, args);
    va_end(args);
    return  result;

}

const char * cjson_path_get_str(int *error_code,cJSON *element,const char *format, ...){
    va_list args;
    va_start(args, format);
    cJSON *result = private_cjson_path_get_cJSON_by_vargs(error_code,element, format, args);
    va_end(args);
    if(*error_code){
        return  NULL;
    }
    if(!cJSON_IsString(result)){
        *error_code =CJSON_PATH_ELEMENT_HAS_WRONG_TYPE;

        return  NULL;
    }
    return  result->valuestring;
}