

int CxpathJson_type(CxpathJson * self, const char *format, ...){

    if(CxpathJson_get_error_code(self)){
        return CXPATHJSON_NOT_FOUND;
    }

    va_list args;
    va_start(args, format);
    bool old_raise_conf = self->raise_runtime_errors;
    self->raise_runtime_errors = false;
    cJSON *result = private_CxpathJson_get_cJSON_by_vargs( self,format, args);
    self->raise_runtime_errors = old_raise_conf;

    va_end(args);
    return private_cxpathjson_get_json_type(result);
}

bool CxpathJson_exist(CxpathJson * self, const char *format, ...){

    if(CxpathJson_get_error_code(self)){
        return CXPATHJSON_NOT_FOUND;
    }

    va_list args;
    va_start(args, format);
    bool old_raise_conf = self->raise_runtime_errors;

    self->raise_runtime_errors = false;
    cJSON *result = private_CxpathJson_get_cJSON_by_vargs( self,format, args);
    self->raise_runtime_errors = old_raise_conf;

    va_end(args);
    return (bool)private_cxpathjson_get_json_type(result);
}

bool CxpathJson_its_not_null(CxpathJson * self, const char *format, ...){
    if(CxpathJson_get_error_code(self)){
        return CXPATHJSON_NOT_FOUND;
    }

    va_list args;
    va_start(args, format);
    bool old_raise_conf = self->raise_runtime_errors;

    self->raise_runtime_errors = false;
    cJSON *result = private_CxpathJson_get_cJSON_by_vargs( self,format, args);
    self->raise_runtime_errors = old_raise_conf;

    va_end(args);
    int generated_type = private_cxpathjson_get_json_type(result);
    if(generated_type == CXPATHJSON_NULL){
        return  false;
    }

    if(generated_type == CXPATHJSON_NOT_FOUND){
        return  false;
    }

    return  true;
}



const char * CxpathJson_type_str(CxpathJson * self, const char *format, ...){

    if(CxpathJson_get_error_code(self)){
        return CXPATHJSON_NOT_FOUND_TEXT;
    }

    va_list args;
    va_start(args, format);
    bool old_raise_conf = self->raise_runtime_errors;
    self->raise_runtime_errors = false;
    cJSON *result = private_CxpathJson_get_cJSON_by_vargs( self,format, args);
    self->raise_runtime_errors = old_raise_conf;
    va_end(args);
    return private_cxpathjson_convert_json_type_to_str(result);
}
bool CxpathJson_its_iterable(CxpathJson * self, const char *format, ...){
    if(CxpathJson_get_error_code(self)){
        return CXPATHJSON_NOT_FOUND;
    }

    va_list args;
    va_start(args, format);
    bool old_raise_conf = self->raise_runtime_errors;

    self->raise_runtime_errors = false;
    cJSON *result = private_CxpathJson_get_cJSON_by_vargs( self,format, args);
    self->raise_runtime_errors = old_raise_conf;

    va_end(args);
    int generated_type = private_cxpathjson_get_json_type(result);
    if(generated_type == CXPATHJSON_ARRAY){
        return  true;
    }

    if(generated_type == CXPATHJSON_OBJECT){
        return  true;
    }

    return  false;
}