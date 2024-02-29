
int private_CxpathJson_verifiy_if_insertion_is_possible(CxpathJson *self, cJSON *path_list){

    int path_size = cJSON_GetArraySize(path_list);

    if(path_size == 0){
        char *dumped = cJSON_Print(path_list);
        if(self->raise_runtime_errors){
            CxpathJson_raise_errror(
                    self,
                    CXPATHJSON_ARG_PATH_NOT_VALID_CODE,
                    path_list,
                    PRIVATE_CXPATHJSON_ARG_PATH_NOT_VALID_MESSAGE,
                    dumped
            );
        }
        free(dumped);
        return CXPATHJSON_GENERIC_ERROR;
    }

    cJSON *current_element = self->element;
    for(int i = 0;i <path_size;i++){


        if(!current_element){
            return  CXPATHJSON_OK_CODE;
        }

        cJSON *current_path = cJSON_GetArrayItem(path_list,i);
        bool current_its_object = cJSON_IsObject(current_element);
        bool current_is_an_array = cJSON_IsArray(current_element);
        bool current_its_iterable = cJSON_IsArray(current_element) || current_its_object;

        bool is_append = private_cxpathjson_path_is_append(current_path);
        bool path_must_be_an_object = cJSON_IsString(current_path) && !is_append;
        bool path_must_be_an_array = cJSON_IsNumber(current_path) || is_append;


        if(current_its_iterable == false) {
            if(self->raise_runtime_errors){
                CxpathJson_raise_errror(
                        self,
                        CXPATHJSON_MIDDLE_ELEMENT_ITS_NOT_ITERABLE_CODE,
                        path_list,
                        PRIVATE_CXPATHJSON_MIDDLE_ELEMENT_ITS_NOT_ITERABLE_MESSAGE
                );
            }
            return  CXPATHJSON_GENERIC_ERROR;
        }

        if(path_must_be_an_object && current_its_object == false){
            if(self->raise_runtime_errors){
                CxpathJson_raise_errror(
                        self,
                        CXPATHJSON_MIDDLE_ELEMENT_ITS_NOT_OBJECT_CODE,
                        path_list,
                        PRIVATE_CXPATHJSON_MIDDLE_ELEMENT_ITS_NOT_OBJECT_MESSAGE
                );
            }

            return CXPATHJSON_GENERIC_ERROR;

        }

        if(path_must_be_an_array && current_is_an_array == false){
            if(self->raise_runtime_errors){
                CxpathJson_raise_errror(
                        self,
                        CXPATHJSON_MIDDLE_ELEMENT_ITS_NOT_ARRAY_CODE,
                        path_list,
                        PRIVATE_CXPATHJSON_MIDDLE_ELEMENT_ITS_NOT_ARRAY_MESSAGE
                );
            }

            return  CXPATHJSON_GENERIC_ERROR;
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
    return CXPATHJSON_OK_CODE;


}
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
void CxpathJson_set_str(CxpathJson *self, const char *string, const char *format, ...){

    if(CxpathJson_get_error_code(self)){
        return;
    }

    va_list args = {0};
    va_start(args, format);
    cJSON *value = cJSON_CreateString(string);
    private_CxpathJson_set_cjson_by_va_arg(self, value, format, args);
    va_end(args);

    if(CxpathJson_get_error_code(self)){
        cJSON_Delete(value);

    }

}
