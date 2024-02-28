
void newCxpathJson_raise_errror(CxpathJson * self, int error_code, const char *path, const char *format, ...){
    if(self->error_code){
        return;
    }
    self->error_code = error_code;
    self->error_path = strdup(path);
    va_list args = {0};
    va_start(args, format);
    self->error_message = malloc(2000 * sizeof (char));
    vsnprintf(self->error_message, 2000 * sizeof (char), format, args);
    va_end(args);

}

void newCxpathJson_clear_errors(CxpathJson * self){
    if(self->error_message){
        free(self->error_message);
    }

    if(self->error_path){
        free(self->error_path);
    }
    self->error_code = CXPATHJSON_OK;
}
