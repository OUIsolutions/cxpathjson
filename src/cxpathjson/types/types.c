

int cxpathjson_type(CxpathJson * self, const char *format, ...){

    if(CxpathJson_get_error_code(self)){
        return CXPATHJSON_NOT_FOUND;
    }

    va_list args = {0};
    va_start(args, format);
    self->raise_runtime_errors = false;
    cJSON *result = private_CxpathJson_get_cJSON_by_vargs( self,format, args);
    self->raise_runtime_errors = true;

    va_end(args);
    return private_cxpathjson_get_json_type(result);
}

const char * CxpathJson_type_str(CxpathJson * self, const char *format, ...){

    if(CxpathJson_get_error_code(self)){
        return CXPATHJSON_NOT_FOUND_TEXT;
    }

    va_list args = {0};
    va_start(args, format);
    int error_code;
    self->raise_runtime_errors = false;
    cJSON *result = private_CxpathJson_get_cJSON_by_vargs( format, args);
    self->raise_runtime_errors = true;
    va_end(args);
    return private_cxpathjson_convert_json_type_to_str(result);
}