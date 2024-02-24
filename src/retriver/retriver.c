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
cJSON * cjson_path_get_cJSON_by_vargs(cJSON *element, const char *format, va_list args){
    int size = vsnprintf(NULL, 0, format, args);
    char *buffer = (char *)malloc(size + 1);
    vsnprintf(buffer, size + 1, format, args);
    cJSON *parsed_path  = cJSON_Parse(buffer);
    free(buffer);
    if(private_cjson_path_validate_path(parsed_path)){
        cJSON_Delete(parsed_path);
        return  NULL;
    }
    cJSON *current_element = element;
    int path_size = cJSON_GetArraySize(parsed_path);
    for(int i = 0;i <path_size;i++){

        if(!current_element){
            cJSON_Delete(parsed_path);
            return  NULL;
        }

        cJSON *current_path = cJSON_GetArrayItem(parsed_path,i);

        if(cJSON_IsString(current_path)){
            current_element = cJSON_GetObjectItem(current_element,current_element->valuestring);
        }


        if(cJSON_IsNumber(current_path)){
            current_element = cJSON_GetArrayItem(current_element,current_path->valueint);
        }


    }
    cJSON_Delete(parsed_path);

    return current_element;
}

cJSON *cjson_path_get_cJSON(cJSON *element, const char *format, ...) {
    va_list args;
    va_start(args, format);
    cJSON *result = cjson_path_get_cJSON_by_vargs(element,format,args);
    va_end(args);
    return  result;

}

const char * cjson_path_get_str(cJSON *element,const char *format, ...){
    va_list args;
    va_start(args, format);
    cJSON *result = cjson_path_get_cJSON_by_vargs(element,format,args);
    va_end(args);
    if(result){
        return  result->valuestring;
    }

    return  NULL;
}