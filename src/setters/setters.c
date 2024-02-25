
int private_cxpathjson_verifiy_if_insertion_is_possible(cJSON *element, cJSON *path_list){
    if(!element){
        return  CJSON_PATH_ELEMENT_PATH_NOT_EXIST_CODE;
    }
    int path_size = cJSON_GetArraySize(path_list);

    if(path_size == 0){
        return  CJSON_PATH_ARG_PATH_NOT_VALID_CODE;
    }

    cJSON *current_element = element;
    for(int i = 0;i <path_size;i++){


        if(!current_element){
            return  CJSON_PATH_OK;
        }

        cJSON *current_path = cJSON_GetArrayItem(path_list,i);
        bool current_its_object = cJSON_IsObject(current_element);
        bool current_is_an_array = cJSON_IsArray(current_element);
        bool current_its_iterable = cJSON_IsArray(current_element) || current_its_object;

        bool is_append = private_cxpathjson_path_is_append(current_path);
        bool path_must_be_an_object = cJSON_IsString(current_path) && !is_append;
        bool path_must_be_an_array = cJSON_IsNumber(current_path) || is_append;


        if(current_its_iterable == false) {
            return  CJSON_PATH_MIDDLE_ELEMENT_ITS_NOT_ITERABLE;
        }

        if(path_must_be_an_object && current_its_object == false){
            return  CJSON_PATH_MIDDLE_ELEMENT_ITS_NOT_OBJECT;
        }
        if(path_must_be_an_array && current_is_an_array == false){
            return  CJSON_PATH_MIDDLE_ELEMENT_ITS_NOT_ARRAY;
        }

        if(current_its_object){
            const char *key = current_path->valuestring;
            current_element = cJSON_GetObjectItem(current_element,key);
        }


        if(current_is_an_array){
            int index = private_cxpathjson_convert_index(
                    current_path->valueint,
                    cJSON_GetArraySize(current_element)
            );
            current_element = cJSON_GetArrayItem(current_element,index);
        }
    }

    return CJSON_PATH_OK;


}
int private_cxpathjson_set_cjson_by_path_list(cJSON *element, cJSON *value, cJSON *path_list) {

    cJSON *current_element = element;

    int error  = private_cxpathjson_verifiy_if_insertion_is_possible(element, path_list);
    if(error){
        return  error;
    }
    int path_size = cJSON_GetArraySize(path_list);

    for(int i = 0;i <path_size-1;i++){

        cJSON *current_path = cJSON_GetArrayItem(path_list,i);


        bool is_append = private_cxpathjson_path_is_append(current_path);
        bool path_must_be_an_object = cJSON_IsString(current_path) && !is_append;
        bool path_must_be_an_array = cJSON_IsNumber(current_path) || is_append;


        cJSON *possible_current_element = NULL;
        if(path_must_be_an_object){
            possible_current_element = cJSON_GetObjectItem(current_element,current_path->valuestring);
        }


        if(path_must_be_an_array){
            int index = private_cxpathjson_convert_index(
                    current_path->valueint,
                    cJSON_GetArraySize(current_element)
            );
            possible_current_element = cJSON_GetArrayItem(current_element,index);
        }


        if(possible_current_element){
            current_element = possible_current_element;
            continue;
        }

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


    cJSON *last_path = cJSON_GetArrayItem(path_list,path_size-1);


    if(cJSON_IsString(last_path)){
        cJSON *already_exist  = cJSON_GetObjectItem(current_element,last_path->valuestring);
        if(already_exist){
            cJSON_DeleteItemFromObject(current_element,last_path->valuestring);
        }


        cJSON_AddItemToObject(current_element,last_path->valuestring,value);
    }

    if(cJSON_IsNumber(last_path)){
        int index = private_cxpathjson_convert_index(
                last_path->valueint,
                cJSON_GetArraySize(current_element)
        );

        if(index >= path_size){
            cJSON_AddItemToArray(current_element,value);
        }
        else{
            cJSON_ReplaceItemInArray(current_element,index,value);
        }

    }

    return CJSON_PATH_OK;
}

int private_cxpathjson_set_cjson_by_va_arg(cJSON *element, cJSON *value, const char *format, va_list args){

    char buffer[2000] = {0};
    vsnprintf(buffer, sizeof(buffer), format, args);
    private_cxpathjson_replace_comas(buffer);
    cJSON *parsed_path  = cJSON_Parse(buffer);

    if(private_cxpathjson_validate_path(parsed_path)){
        cJSON_Delete(parsed_path);
        return  CJSON_PATH_ARG_PATH_NOT_VALID_CODE;
    }

    int result = private_cxpathjson_set_cjson_by_path_list(element, value, parsed_path);
    cJSON_Delete(parsed_path);
    return  result;

}


int cxpathjson_set_cjson(cJSON *element, cJSON *value, const char *format, ...){
    va_list args;
    va_start(args, format);
    int result = private_cxpathjson_set_cjson_by_va_arg(element, value, format, args);
    va_end(args);
    return  result;
}
int cxpathjson_set_str(cJSON *element, const char *string, const char *format, ...){
    va_list args;
    va_start(args, format);
    cJSON *value = cJSON_CreateString(string);
    int result = private_cxpathjson_set_cjson_by_va_arg(element, value, format, args);
    if(result){
        cJSON_Delete(value);
    }

    va_end(args);
    return  result;
}
