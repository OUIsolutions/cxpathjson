
int private_cjson_path_set_cjson_by_path_list(cJSON *element,cJSON *value,cJSON *path_list) {

    cJSON *current_element = element;
    int path_size = cJSON_GetArraySize(path_list);
    if(path_size == 0){
        return  CJSON_PATH_ARG_PATH_NOT_VALID_CODE;
    }

    if(!current_element){
        return  CJSON_PATH_ELEMENT_PATH_NOT_EXIST_CODE;
    }

    for(int i = 0;i <path_size-1;i++){

        if(!current_element){
            return  CJSON_PATH_ELEMENT_PATH_NOT_EXIST_CODE;
        }
        
        bool current_its_object = cJSON_IsObject(current_element);
        bool current_its_terable = cJSON_IsArray(current_element) || current_its_object;

        if(!current_its_terable){
            return  CJSON_PATH_MIDDLE_ELEMENT_ITS_NOT_ITERABLE;
        }

        cJSON *current_path = cJSON_GetArrayItem(path_list,i);

        if(cJSON_IsString(current_path) && !current_its_object){
            return  CJSON_PATH_MIDDLE_ELEMENT_ITS_NOT_OBJECT;
        }

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


        cJSON *created_element  = NULL;

        cJSON *next_path = cJSON_GetArrayItem(path_list,i+1);
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
        current_element = created_element;

    }

    if(!current_element){
        return  CJSON_PATH_ELEMENT_PATH_NOT_EXIST_CODE;
    }

    bool current_its_object = cJSON_IsObject(current_element);
    bool current_its_terable = cJSON_IsArray(current_element) || current_its_object;

    if(!current_its_terable){
        return  CJSON_PATH_MIDDLE_ELEMENT_ITS_NOT_ITERABLE;
    }

    cJSON *last_path = cJSON_GetArrayItem(path_list,path_size-1);

    if(cJSON_IsString(last_path) && !current_its_object){
        return  CJSON_PATH_MIDDLE_ELEMENT_ITS_NOT_OBJECT;
    }

    if(cJSON_IsString(last_path)){
        cJSON *already_exist  = cJSON_GetObjectItem(current_element,last_path->valuestring);
        if(already_exist){
            cJSON_DeleteItemFromObject(current_element,last_path->valuestring);
        }

        cJSON_AddItemToObject(current_element,last_path->valuestring,value);
    }

    if(cJSON_IsNumber(last_path)){

        int index = last_path->valueint;
        if(index < 0){
            int current_element_size = cJSON_GetArraySize(current_element);
            index = (current_element_size + index);
        }
        //printf("index:%d\n",index);

        if(index > path_size){
            cJSON_AddItemToArray(current_element,value);
        }

    }

    return CJSON_PATH_OK;
}

int private_cjson_path_set_cjson_by_va_arg(cJSON *element,cJSON *value,const char *format, va_list args){
    char buffer[2000] = {0};
    vsnprintf(buffer, sizeof(buffer), format, args);
    private_cjson_path_replace_comas(buffer);
    cJSON *parsed_path  = cJSON_Parse(buffer);

    if(private_cjson_path_validate_path(parsed_path)){
        cJSON_Delete(parsed_path);
        return  CJSON_PATH_ARG_PATH_NOT_VALID_CODE;
    }
    int result = private_cjson_path_set_cjson_by_path_list(element,value,parsed_path);
    cJSON_Delete(parsed_path);
    return  result;
}


int cjson_path_set_cjson(cJSON *element,cJSON *value,const char *format,...){
    va_list args;
    va_start(args, format);
    int result = private_cjson_path_set_cjson_by_va_arg(element,value,format,args);
    va_end(args);
    return  result;
}
int cjson_path_set_str(cJSON *element,const char *string,const char *format,...){
    va_list args;
    va_start(args, format);
    cJSON *value = cJSON_CreateString(string);
    int result = private_cjson_path_set_cjson_by_va_arg(element,value,format,args);
    if(result){
        cJSON_Delete(value);
    }

    va_end(args);
    return  result;
}
