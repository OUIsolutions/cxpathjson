
int private_cjson_path_set_cjson_by_va_arg(cJSON *element,cJSON *value,const char *format, va_list args){
    char buffer[2000] = {0};
    vsnprintf(buffer, sizeof(buffer), format, args);
    private_cjson_path_replace_comas(buffer);
    cJSON *parsed_path  = cJSON_Parse(buffer);

    if(private_cjson_path_validate_path(parsed_path)){
        cJSON_Delete(parsed_path);
        return  CJSON_PATH_ARG_PATH_NOT_VALID_CODE;
    }

    cJSON *current_element = element;
    int path_size = cJSON_GetArraySize(parsed_path);
    if(path_size == 0){
        cJSON_Delete(parsed_path);
        return  CJSON_PATH_ARG_PATH_NOT_VALID_CODE;
    }

    if(!current_element){
        cJSON_Delete(parsed_path);
        return  CJSON_PATH_ELEMENT_PATH_NOT_EXIST_CODE;
    }

    for(int i = 0;i <path_size-1;i++){


        cJSON *current_path = cJSON_GetArrayItem(parsed_path,i);

        cJSON *possible_current_element = NULL;
        if(cJSON_IsString(current_path)){
            possible_current_element = cJSON_GetObjectItem(current_element,current_path->valuestring);
        }

        if(cJSON_IsNumber(current_path)){
            int index = current_path->valueint;
            if(index < 0){
                int current_element_size = cJSON_GetArraySize(current_element);
                index = (current_element_size + index);
            }
            possible_current_element = cJSON_GetArrayItem(current_element,index);
        }


        if(possible_current_element){
            current_element = possible_current_element;
            continue;
        }
        //here means current were not finded

        cJSON *next_path = cJSON_GetArrayItem(current_path,i+1);
        cJSON *created_element  = NULL;

        if(cJSON_IsString(next_path)){
            created_element = cJSON_CreateObject();
        }
        if(cJSON_IsNumber(next_path)){
            created_element = cJSON_CreateArray();
        }


        if( cJSON_IsString(current_path)){
            cJSON_AddItemToObject(current_element,current_path->valuestring,created_element);
        }

        if(cJSON_IsNumber(current_path)){
            cJSON_AddItemToArray(current_element,created_element);
        }


    }


    cJSON_Delete(parsed_path);
    return CJSON_PATH_OK;
}

int cjson_path_set_cjson(cJSON *element,cJSON *value,const char *format,...){
    va_list args;
    va_start(args, format);
    int result = private_cjson_path_set_cjson_by_va_arg(element,value,format,args);
    va_end(args);
    return  result;
}