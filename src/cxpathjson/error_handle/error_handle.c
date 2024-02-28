
void CxpathJson_raise_errror(CxpathJson * self, int error_code, cJSON *path, const char *format, ...){
    if(self->error_code){
        return;
    }
    self->error_code = error_code;
    if(path){
        self->error_path_str = cJSON_PrintUnformatted(path);
        self->path_list = cJSON_Duplicate(path, true);
    }

    va_list args = {0};
    va_start(args, format);
    self->error_message = malloc(2000 * sizeof (char));
    vsnprintf(self->error_message, 2000 * sizeof (char), format, args);
    va_end(args);

}

void CxpathJson_clear_errors(CxpathJson * self){
    if(self->error_message){
        free(self->error_message);
    }
    if(self->path_list){
        cJSON_Delete(self->path_list);
    }
    if(self->error_path_str){
        free(self->error_path_str);
    }

    self->error_code = CXPATHJSON_OK_CODE;
}
