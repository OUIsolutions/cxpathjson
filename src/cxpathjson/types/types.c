

int cxpathjson_type(CxpathJson * self, const char *format, ...){

    if(CxpathJson_get_error_code(self)){
        return CXPATHJSON_NOT_FOUND;
    }

    va_list args = {0};
    va_start(args, format);
    cJSON *result = private_CxpathJson_get_cJSON_by_vargs( self,format, args);

    if(!result){
        return CXPATHJSON_NOT_FOUND;
    }


    va_end(args);


    if(cJSON_IsNull(result)){
        return CXPATHJSON_NULL;
    }

    if(cJSON_IsBool(result)){
        return CXPATHJSON_BOOL;
    }

    if(cJSON_IsNumber(result)){
        return CXPATHJSON_NUMBER;
    }

    if(cJSON_IsString(result)){
        return CXPATHJSON_STRING;
    }

    if(cJSON_IsObject(result)){
        return CXPATHJSON_OBJECT;
    }

    if(cJSON_IsArray(result)){
        return CXPATHJSON_ARRAY;
    }
    return CXPATHJSON_NOT_FOUND;

}
const char * CxpathJson_type_str(CxpathJson * self, const char *format, ...){

    if(CxpathJson_get_error_code(self)){
        return CXPATHJSON_INVALID_TEXT;
    }



    va_list args = {0};
    va_start(args, format);
    int error_code;

    cJSON *result = private_CxpathJson_get_cJSON_by_vargs(&error_code, element, format, args);
    va_end(args);
    if(error_code){
        return CXPATHJSON_INVALID_TEXT;
    }

    if(cJSON_IsNull(result)){
        return CXPATHJSON_NULL_TEXT;
    }

    if(cJSON_IsBool(result)){
        return CXPATHJSON_BOOL_TEXT;
    }

    if(cJSON_IsNumber(result)){
        return CXPATHJSON_NUMBER_TEXT;
    }

    if(cJSON_IsString(result)){
        return CXPATHJSON_STRING_TEXT;
    }

    if(cJSON_IsObject(result)){
        return CXPATHJSON_OBJECT_TEXT;
    }

    if(cJSON_IsArray(result)){
        return CXPATHJSON_ARRAY_TEXT;
    }
    return CXPATHJSON_INVALID_TEXT;
}