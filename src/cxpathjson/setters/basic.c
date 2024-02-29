
void private_cxpathjson_set_cjson_by_path_list(CxpathJson *self, cJSON *value, cJSON *path_list) {

    if(CxpathJson_get_error_code(self)){
        return;
    }

    if(private_CxpathJson_verifiy_if_insertion_is_possible(self, path_list)){
        return;
    }


    cJSON *last_element = self->element;
    int path_size = cJSON_GetArraySize(path_list);

    for(int i = 0;i <path_size-1;i++){


        cJSON *current_path = cJSON_GetArrayItem(path_list,i);


        bool is_append = private_cxpathjson_path_is_append(current_path);
        bool path_must_be_an_object = cJSON_IsString(current_path);
        bool path_must_be_an_array = cJSON_IsNumber(current_path);
        cJSON *possible_current_element = NULL;

        if(path_must_be_an_object && !is_append){
            possible_current_element = cJSON_GetObjectItem(last_element, current_path->valuestring);
        }


        if(path_must_be_an_array && !is_append){
            int index = private_cxpathjson_convert_index(
                    current_path->valueint,
                    cJSON_GetArraySize(last_element)
            );
            possible_current_element = cJSON_GetArrayItem(last_element, index);
        }


        if(possible_current_element){
            last_element = possible_current_element;
            continue;
        }

        cJSON *created_element  = NULL;

        cJSON *next_path = cJSON_GetArrayItem(path_list,i+1);

        //Creating the element
        if(private_cxpathjson_path_is_append(next_path)){
            created_element = cJSON_CreateArray();
        }

        else if(cJSON_IsNumber(next_path) ){
            created_element = cJSON_CreateArray();
        }

        else if(cJSON_IsString(next_path)) {
            created_element = cJSON_CreateObject();
        }




        if(cJSON_IsObject(last_element)){
            cJSON_AddItemToObject(last_element, current_path->valuestring, created_element);
        }
            //inserting the created element in current
        else{
            cJSON_AddItemToArray(last_element, created_element);
        }
        last_element = created_element;

    }

    cJSON *last_path = cJSON_GetArrayItem(path_list,path_size-1);

    if(private_cxpathjson_path_is_append(last_path)){

        cJSON_AddItemToArray(last_element, value);
    }

    else if(cJSON_IsString(last_path)){
        cJSON *already_exist  = cJSON_GetObjectItem(last_element, last_path->valuestring);
        if(already_exist){
            cJSON_DeleteItemFromObject(last_element, last_path->valuestring);
        }
        cJSON_AddItemToObject(last_element, last_path->valuestring, value);
    }

    else {
        int index = private_cxpathjson_convert_index(
                last_path->valueint,
                cJSON_GetArraySize(last_element)
        );

        cJSON_ReplaceItemInArray(last_element, index, value);

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
