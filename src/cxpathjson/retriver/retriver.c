

cJSON *CxpathJson_get_cJSON(CxpathJson  *self, const char *format, ...) {

    if(CxpathJson_get_error_code(self)){
        return NULL;
    }
    va_list args;
    va_start(args, format);
    cJSON *result = private_CxpathJson_get_cJSON_by_vargs( self, format, args);
    va_end(args);
    return  result;
}


CxpathJson  * CxpathJson_get_object(CxpathJson * self, const char *format, ...){
    if(CxpathJson_get_error_code(self)){
        return NULL;
    }

    va_list args;
    va_start(args, format);
    cJSON *result = private_CxpathJson_get_cJSON_by_vargs(self, format, args);
    va_end(args);
    if(CxpathJson_get_error_code(self)){
        return NULL;
    }

    if(!cJSON_IsObject(result)){
        if(self->raise_runtime_errors){
            char buffer[2000] = {0};
            vsnprintf(buffer, sizeof(buffer), format, args);
            private_cxpathjson_replace_comas(buffer);
            cJSON *parsed_path  = cJSON_Parse(buffer);
            CxpathJson  *root = private_CxpathJson_get_root(self);

            CxpathJson_raise_errror(
                    root,
                    CXPATHJSON_ELEMENT_HAS_WRONG_TYPE_CODE,
                    parsed_path,
                    PRIVATE_CXPATHJSON_ELEMENT_HAS_WRONG_TYPE_MESSAGE,
                    private_cxpathjson_convert_json_type_to_str(result),
                    CXPATHJSON_OBJECT_TEXT
            );
            cJSON_Delete(parsed_path);
        }


        return  NULL;
    }

    return private_CxpathJson_construct_child(self,result);
}

CxpathJson  * CxpathJson_get_array(CxpathJson * self, const char *format, ...){
    if(CxpathJson_get_error_code(self)){
        return NULL;
    }

    va_list args;
    va_start(args, format);
    cJSON *result = private_CxpathJson_get_cJSON_by_vargs(self, format, args);
    va_end(args);
    if(CxpathJson_get_error_code(self)){
        return NULL;
    }
    if(!cJSON_IsArray(result)){
        if(self->raise_runtime_errors){
            char buffer[2000] = {0};
            vsnprintf(buffer, sizeof(buffer), format, args);
            private_cxpathjson_replace_comas(buffer);
            cJSON *parsed_path  = cJSON_Parse(buffer);
            CxpathJson  *root = private_CxpathJson_get_root(self);

            CxpathJson_raise_errror(
                    root,
                    CXPATHJSON_ELEMENT_HAS_WRONG_TYPE_CODE,
                    parsed_path,
                    PRIVATE_CXPATHJSON_ELEMENT_HAS_WRONG_TYPE_MESSAGE,
                    private_cxpathjson_convert_json_type_to_str(result),
                    CXPATHJSON_ARRAY_TEXT
            );
            cJSON_Delete(parsed_path);
        }


        return  NULL;
    }

    return private_CxpathJson_construct_child(self,result);
}


 char * CxpathJson_get_str(CxpathJson *self, const char *format, ...){
    if(CxpathJson_get_error_code(self)){
        return NULL;
    }

    va_list args;
    va_start(args, format);
    cJSON *result = private_CxpathJson_get_cJSON_by_vargs(self, format, args);
    va_end(args);
    if(CxpathJson_get_error_code(self)){
        return NULL;
    }

    if(!cJSON_IsString(result)){
        if(self->raise_runtime_errors){
            char buffer[2000] = {0};
            vsnprintf(buffer, sizeof(buffer), format, args);
            private_cxpathjson_replace_comas(buffer);
            cJSON *parsed_path  = cJSON_Parse(buffer);
            CxpathJson  *root = private_CxpathJson_get_root(self);

            CxpathJson_raise_errror(
                    root,
                    CXPATHJSON_ELEMENT_HAS_WRONG_TYPE_CODE,
                    parsed_path,
                    PRIVATE_CXPATHJSON_ELEMENT_HAS_WRONG_TYPE_MESSAGE,
                    private_cxpathjson_convert_json_type_to_str(result),
                    CXPATHJSON_STRING_TEXT
            );
            cJSON_Delete(parsed_path);

        }

        return  NULL;
    }
    return  result->valuestring;
}
char * CxpathJson_get_key(CxpathJson * self, const char *format, ...){
    if(CxpathJson_get_error_code(self)){
        return NULL;
    }

    va_list args;
    va_start(args, format);
    cJSON *result = private_CxpathJson_get_cJSON_by_vargs(self, format, args);
    va_end(args);
    if(CxpathJson_get_error_code(self)){
        return NULL;
    }
    char *key =  result->string;
    if(!key && self->raise_runtime_errors){
        char buffer[2000] = {0};
        vsnprintf(buffer, sizeof(buffer), format, args);
        private_cxpathjson_replace_comas(buffer);
        cJSON *parsed_path  = cJSON_Parse(buffer);
        CxpathJson  *root = private_CxpathJson_get_root(self);

        CxpathJson_raise_errror(
                root,
                XPATH_JSON_ELEMENT_NOT_HAVE_KEY_CODE,
                parsed_path,
                XPATH_JSON_ELEMENT_NOT_HAVE_KEY_MESSAGE
        );
        cJSON_Delete(parsed_path);

    }
    return key;
}
double CxpathJson_get_double(CxpathJson * self, const char *format, ...){
    if(CxpathJson_get_error_code(self)){
        return CXPATH_ERROR_NUM_RETURN;
    }

    va_list args;
    va_start(args, format);
    cJSON *result = private_CxpathJson_get_cJSON_by_vargs(self, format, args);
    va_end(args);

    if(CxpathJson_get_error_code(self)){
        return CXPATH_ERROR_NUM_RETURN;
    }

    if(!cJSON_IsNumber(result)){
        if(self->raise_runtime_errors){
            char buffer[2000] = {0};
            vsnprintf(buffer, sizeof(buffer), format, args);
            private_cxpathjson_replace_comas(buffer);
            cJSON *parsed_path  = cJSON_Parse(buffer);
            CxpathJson  *root = private_CxpathJson_get_root(self);

            CxpathJson_raise_errror(
                    root,
                    CXPATHJSON_ELEMENT_HAS_WRONG_TYPE_CODE,
                    parsed_path,
                    PRIVATE_CXPATHJSON_ELEMENT_HAS_WRONG_TYPE_MESSAGE,
                    private_cxpathjson_convert_json_type_to_str(result),
                    CXPATHJSON_NUMBER_TEXT
            );
            cJSON_Delete(parsed_path);
        }
        return CXPATH_ERROR_NUM_RETURN;
    }
    return  result->valuedouble;
}

int CxpathJson_get_int(CxpathJson * self, const char *format, ...){
    if(CxpathJson_get_error_code(self)){
        return CXPATH_ERROR_NUM_RETURN;
    }

    va_list args;
    va_start(args, format);
    cJSON *result = private_CxpathJson_get_cJSON_by_vargs(self, format, args);
    va_end(args);

    if(CxpathJson_get_error_code(self)){
        return CXPATH_ERROR_NUM_RETURN;
    }

    if(!cJSON_IsNumber(result)){

        if(self->raise_runtime_errors){
            char buffer[2000] = {0};
            vsnprintf(buffer, sizeof(buffer), format, args);
            private_cxpathjson_replace_comas(buffer);

            cJSON *parsed_path  = cJSON_Parse(buffer);
            CxpathJson  *root = private_CxpathJson_get_root(self);
            CxpathJson_raise_errror(
                    root,
                    CXPATHJSON_ELEMENT_HAS_WRONG_TYPE_CODE,
                    parsed_path,
                    PRIVATE_CXPATHJSON_ELEMENT_HAS_WRONG_TYPE_MESSAGE,
                    private_cxpathjson_convert_json_type_to_str(result),
                    CXPATHJSON_NUMBER_TEXT
            );
            cJSON_Delete(parsed_path);

        }

        return CXPATH_ERROR_NUM_RETURN;
    }
    return  result->valueint;
}

bool CxpathJson_get_bool(CxpathJson * self, const char *format, ...){
    if(CxpathJson_get_error_code(self)){
        return CXPATH_ERROR_NUM_RETURN;
    }

    va_list args;
    va_start(args, format);
    cJSON *result = private_CxpathJson_get_cJSON_by_vargs(self, format, args);
    va_end(args);

    if(CxpathJson_get_error_code(self)){
        return CXPATH_ERROR_NUM_RETURN;
    }

    if(!cJSON_IsBool(result)){

        if(self->raise_runtime_errors){
            char buffer[2000] = {0};
            vsnprintf(buffer, sizeof(buffer), format, args);
            private_cxpathjson_replace_comas(buffer);

            cJSON *parsed_path  = cJSON_Parse(buffer);
            CxpathJson  *root = private_CxpathJson_get_root(self);
            CxpathJson_raise_errror(
                    root,
                    CXPATHJSON_ELEMENT_HAS_WRONG_TYPE_CODE,
                    parsed_path,
                    PRIVATE_CXPATHJSON_ELEMENT_HAS_WRONG_TYPE_MESSAGE,
                    private_cxpathjson_convert_json_type_to_str(result),
                    CXPATHJSON_BOOL_TEXT
            );
            cJSON_Delete(parsed_path);

        }

        return CXPATH_ERROR_NUM_RETURN;
    }
    return  (bool)result->valueint;
}

int CxpathJson_get_size(CxpathJson * self, const char *format, ...){
    if(CxpathJson_get_error_code(self)){
        return CXPATH_ERROR_NUM_RETURN;
    }

    va_list args;
    va_start(args, format);
    cJSON *result = private_CxpathJson_get_cJSON_by_vargs(self, format, args);
    va_end(args);

    if(CxpathJson_get_error_code(self)){
        return CXPATH_ERROR_NUM_RETURN;
    }

    if(!cJSON_IsArray(result)){
        if(self->raise_runtime_errors){
            char buffer[2000] = {0};
            vsnprintf(buffer, sizeof(buffer), format, args);
            private_cxpathjson_replace_comas(buffer);

            cJSON *parsed_path  = cJSON_Parse(buffer);
            CxpathJson  *root = private_CxpathJson_get_root(self);

            CxpathJson_raise_errror(
                    root,
                    CXPATHJSON_ELEMENT_HAS_WRONG_TYPE_CODE,
                    parsed_path,
                    PRIVATE_CXPATHJSON_ELEMENT_HAS_WRONG_TYPE_MESSAGE,
                    private_cxpathjson_convert_json_type_to_str(result),
                    CXPATHJSON_ARRAY

            );
            cJSON_Delete(parsed_path);

        }

        return CXPATH_ERROR_NUM_RETURN;
    }
    return cJSON_GetArraySize(result);
}