

void CxpathJson_destroy(CxpathJson *self,const char *format, ...){
    if(CxpathJson_get_error_code(self)){
        return ;
    }

    va_list args;
    va_start(args, format);
    char buffer[2000] = {0};
    vsnprintf(buffer, sizeof(buffer), format, args);
    va_end(args);

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
    bool old_raise = self->raise_runtime_errors;
    self->raise_runtime_errors = false;
    cJSON *possible_element = private_CxpathJson_cJSON_by_cjson_path_list(self,parsed_path);
    self->raise_runtime_errors = old_raise;
    if(!possible_element){
        cJSON_Delete(parsed_path);
        return;
    }

    //here we know the element exist
    int path_size = cJSON_GetArraySize(parsed_path);
    cJSON *rest = cJSON_CreateArray();

    for(int i = 0; i < path_size -1; i++){
        cJSON *element = cJSON_GetArrayItem(parsed_path,i);
        cJSON_AddItemReferenceToArray(rest,element);
    }
    cJSON *father = private_CxpathJson_cJSON_by_cjson_path_list(self,rest);
    cJSON_Delete(rest);

    cJSON *last = cJSON_GetArrayItem(parsed_path,path_size -1);

    if(cJSON_IsString(last)){
        cJSON_DeleteItemFromObject(father,last->valuestring);
    }
    if(cJSON_IsNumber(last)){
        cJSON_DeleteItemFromArray(father,last->valueint);
    }

    cJSON_Delete(parsed_path);

}