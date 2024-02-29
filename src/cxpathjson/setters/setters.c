
void private_cxpathjson_set_cjson_by_path_list(CxpathJson *self, cJSON *value, cJSON *path_list) {

    if(CxpathJson_get_error_code(self)){
        return;
    }

    if(private_CxpathJson_verifiy_if_insertion_is_possible(self, path_list)){
        return;
    }


    cJSON *current_element = self->element;
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



        if(cJSON_IsNumber(next_path) || private_cxpathjson_path_is_append(next_path)){
            created_element = cJSON_CreateArray();
        }
        else {
            created_element = cJSON_CreateObject();
        }

        if(cJSON_IsNumber(current_path) || is_append){
            cJSON_AddItemToArray(current_element,created_element);
        }
        else{
            cJSON_AddItemToObject(current_element,current_path->valuestring,created_element);
        }

        current_element = created_element;

    }


    cJSON *last_path = cJSON_GetArrayItem(path_list,path_size-1);

    if(private_cxpathjson_path_is_append(last_path)){

        cJSON_AddItemToArray(current_element,value);
    }

    else if(cJSON_IsString(last_path)){
        cJSON *already_exist  = cJSON_GetObjectItem(current_element,last_path->valuestring);
        if(already_exist){
            cJSON_DeleteItemFromObject(current_element,last_path->valuestring);
        }
        cJSON_AddItemToObject(current_element,last_path->valuestring,value);
    }

    else {
        int index = private_cxpathjson_convert_index(
                last_path->valueint,
                cJSON_GetArraySize(current_element)
        );

        cJSON_ReplaceItemInArray(current_element,index,value);

    }

}

void private_CxpathJson_set_cjson_by_va_arg(CxpathJson *self, cJSON *value, const char *format, va_list args){
    if(CxpathJson_get_error_code(self)){
        return;
    }
    char buffer[2000] = {0};
    vsnprintf(buffer, sizeof(buffer), format, args);
    private_cxpathjson_replace_comas(buffer);
    cJSON *parsed_path  = cJSON_Parse(buffer);

    if(private_cxpathjson_validate_path(parsed_path)){
        //we raise here beacause bad formatting its consider a comptime error
        CxpathJson_raise_errror(self,
                                CXPATHJSON_ARG_PATH_NOT_VALID_CODE,
                                NULL,
                                PRIVATE_CXPATHJSON_ARG_PATH_NOT_VALID_MESSAGE,
                                buffer
        );


        cJSON_Delete(parsed_path);
        return ;

    }
    private_cxpathjson_set_cjson_by_path_list(self, value, parsed_path);
    cJSON_Delete(parsed_path);

}


void CxpathJson_set_cjson(CxpathJson *self, cJSON *value, const char *format, ...){
    if(CxpathJson_get_error_code(self)){
        return;
    }
    va_list args;
    va_start(args, format);
    private_CxpathJson_set_cjson_by_va_arg(self, value, format, args);
    va_end(args);

}
void CxpathJson_set_str(CxpathJson *self, const char *value, const char *format, ...){

    if(CxpathJson_get_error_code(self)){
        return;
    }

    va_list args;
    va_start(args, format);
    cJSON *value_cjson = cJSON_CreateString(value);
    private_CxpathJson_set_cjson_by_va_arg(self, value_cjson, format, args);
    va_end(args);

    if(CxpathJson_get_error_code(self)){
        cJSON_Delete(value_cjson);

    }

}



void CxpathJson_set_double(CxpathJson *self, double value, const char *format, ...){
    if(CxpathJson_get_error_code(self)){
        return;
    }

    va_list args;
    va_start(args, format);
    cJSON *value_cjson = cJSON_CreateNumber(value);
    private_CxpathJson_set_cjson_by_va_arg(self, value_cjson, format, args);
    va_end(args);

    if(CxpathJson_get_error_code(self)){
        cJSON_Delete(value_cjson);

    }
}

void CxpathJson_set_long(CxpathJson *self, long value, const char *format, ...){
    if(CxpathJson_get_error_code(self)){
        return;
    }

    va_list args;
    va_start(args, format);
    cJSON *value_cjson = cJSON_CreateNumber((double )value);
    private_CxpathJson_set_cjson_by_va_arg(self, value_cjson, format, args);
    va_end(args);

    if(CxpathJson_get_error_code(self)){
        cJSON_Delete(value_cjson);

    }
}

void CxpathJson_set_bool(CxpathJson *self, bool value, const char *format, ...){
    if(CxpathJson_get_error_code(self)){
        return;
    }

    va_list args;
    va_start(args, format);
    cJSON *value_cjson = cJSON_CreateBool(value);
    private_CxpathJson_set_cjson_by_va_arg(self, value_cjson, format, args);
    va_end(args);

    if(CxpathJson_get_error_code(self)){
        cJSON_Delete(value_cjson);

    }
}
