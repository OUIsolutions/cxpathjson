


cJSON * private_cjson_path_get_cJSON_by_vargs(int *error_code, cJSON *element, const char *format, va_list args){
    char buffer[2000] = {0};
    vsnprintf(buffer, sizeof(buffer), format, args);
    private_cjson_path_replace_comas(buffer);
    cJSON *parsed_path  = cJSON_Parse(buffer);

    if(private_cjson_path_validate_path(parsed_path)){
        *error_code = CJSON_PATH_ARG_PATH_NOT_VALID_CODE;
        cJSON_Delete(parsed_path);
        return  NULL;
    }

    cJSON *current_element = element;
    int path_size = cJSON_GetArraySize(parsed_path);
    for(int i = 0;i <path_size;i++){

        if(!current_element){
            cJSON_Delete(parsed_path);
            *error_code = CJSON_PATH_ELEMENT_PATH_NOT_EXIST_CODE;
            return  NULL;
        }

        cJSON *current_path = cJSON_GetArrayItem(parsed_path,i);

        if(cJSON_IsString(current_path)){
            current_element = cJSON_GetObjectItem(current_element,current_path->valuestring);
        }


        if(cJSON_IsNumber(current_path)){
            current_element = cJSON_GetArrayItem(current_element,current_path->valueint);
        }


    }
    if(!current_element){
        cJSON_Delete(parsed_path);
        *error_code = CJSON_PATH_ELEMENT_PATH_NOT_EXIST_CODE;
        return  NULL;
    }

    cJSON_Delete(parsed_path);
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

double cjson_path_get_double(int *error_code,cJSON *element,const char *format, ...){
    va_list args;
    va_start(args, format);
    cJSON *result = private_cjson_path_get_cJSON_by_vargs(error_code,element, format, args);
    va_end(args);
    if(*error_code){
        return  -1;
    }
    if(!cJSON_IsNumber(result)){
        *error_code =CJSON_PATH_ELEMENT_HAS_WRONG_TYPE;
        return  -1;
    }
    return  result->valuedouble;
}

int cjson_path_get_int(int *error_code,cJSON *element,const char *format, ...){
    va_list args;
    va_start(args, format);
    cJSON *result = private_cjson_path_get_cJSON_by_vargs(error_code,element, format, args);
    va_end(args);
    if(*error_code){
        return  -1;
    }
    if(!cJSON_IsNumber(result)){
        *error_code =CJSON_PATH_ELEMENT_HAS_WRONG_TYPE;
        return  -1;
    }
    return  result->valueint;
}

bool cjson_path_get_bool(int *error_code,cJSON *element,const char *format, ...){
    va_list args;
    va_start(args, format);
    cJSON *result = private_cjson_path_get_cJSON_by_vargs(error_code,element, format, args);
    va_end(args);
    if(*error_code){
        return  -1;
    }
    if(!cJSON_IsBool(result)){
        *error_code =CJSON_PATH_ELEMENT_HAS_WRONG_TYPE;
        return  -1;
    }
    return  (bool)result->valueint;
}
int cjson_path_type(cJSON *element,const char *format,...){

    if(!element){
        return CJSON_PATH_INVALID;

    }
    va_list args;
    va_start(args, format);
    int error_code;

    cJSON *result = private_cjson_path_get_cJSON_by_vargs(&error_code,element, format, args);
    va_end(args);
    if(error_code){
        return CJSON_PATH_INVALID;
    }

    if(cJSON_IsNull(result)){
        return CJSON_PATH_NULL;
    }

    if(cJSON_IsBool(result)){
        return CJSON_PATH_BOOL;
    }

    if(cJSON_IsNumber(result)){
        return CJSON_PATH_NUMBER;
    }

    if(cJSON_IsString(result)){
        return CJSON_PATH_STRING;
    }

    if(cJSON_IsObject(result)){
        return CJSON_PATH_OBJECT;
    }

    if(cJSON_IsArray(result)){
        return CJSON_PATH_ARRAY;
    }

}

int cjson_path_size(int *error_code,cJSON *element,const char *format, ...){
    va_list args;
    va_start(args, format);
    cJSON *result = private_cjson_path_get_cJSON_by_vargs(error_code,element, format, args);
    va_end(args);
    if(*error_code){
        return  -1;
    }
    if(!cJSON_IsArray(result) && !cJSON_IsObject(result)){
        *error_code =CJSON_PATH_ELEMENT_HAS_WRONG_TYPE;
        return  -1;
    }

    return cJSON_GetArraySize(result);
}