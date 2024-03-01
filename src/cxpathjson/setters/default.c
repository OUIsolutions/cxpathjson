

void CxpathJson_set_default_cjson_getting_ownership(CxpathJson *self, cJSON *value, const char *format, ...){
    if(CxpathJson_get_error_code(self)){
        cJSON_Delete(value);
        return;
    }
    va_list args;
    va_start(args, format);

    bool old_config = self->raise_runtime_errors;
    self->raise_runtime_errors = false;
    cJSON *old = private_CxpathJson_get_cJSON_by_vargs(self,format,args);
    self->raise_runtime_errors = old_config;

    if(CxpathJson_get_error_code(self) || old){
        cJSON_Delete(value);
        return;
    }

    private_CxpathJson_set_cjson_by_va_arg_getting_ownership(self, value, format, args);
    va_end(args);
}
void CxpathJson_set_default_str_getting_onwership(CxpathJson *self,  char *value, const char *format, ...){
    if(CxpathJson_get_error_code(self)){
        return;
    }

    va_list args;
    va_start(args, format);
    cJSON *value_cjson = cJSON_New_Item(&global_hooks);
    value_cjson->type = cJSON_String;
    value_cjson->valuestring = value;
    CxpathJson_set_default_cjson_getting_ownership(self, value_cjson, format, args);
    va_end(args);


}
void CxpathJson_set_default_str(CxpathJson *self, const char *value, const char *format, ...){
    if(CxpathJson_get_error_code(self)){
        return;
    }

    va_list args;
    va_start(args, format);
    cJSON *value_cjson = cJSON_CreateString(value);
    CxpathJson_set_default_cjson_getting_ownership(self, value_cjson, format, args);
    va_end(args);

}


void CxpathJson_set_default_double(CxpathJson *self, double value, const char *format, ...){
    if(CxpathJson_get_error_code(self)){
        return;
    }

    va_list args;
    va_start(args, format);
    cJSON *value_cjson = cJSON_CreateNumber(value);
    CxpathJson_set_default_cjson_getting_ownership(self, value_cjson, format, args);
    va_end(args);

}

void CxpathJson_set_default_int(CxpathJson *self, int value, const char *format, ...){
    if(CxpathJson_get_error_code(self)){
        return;
    }

    va_list args;
    va_start(args, format);
    cJSON *value_cjson = cJSON_CreateNumber((double )value);
    CxpathJson_set_default_cjson_getting_ownership(self, value_cjson, format, args);
    va_end(args);

}

void CxpathJson_set_default_bool(CxpathJson *self, bool value, const char *format, ...){
    if(CxpathJson_get_error_code(self)){
        return;
    }

    va_list args;
    va_start(args, format);
    cJSON *value_cjson = cJSON_CreateBool(value);
    CxpathJson_set_default_cjson_getting_ownership(self, value_cjson, format, args);
    va_end(args);
}