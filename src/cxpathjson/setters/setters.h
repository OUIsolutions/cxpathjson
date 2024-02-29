

int private_CxpathJson_verifiy_if_insertion_is_possible(CxpathJson *self, cJSON *path_list);

void private_cxpathjson_set_cjson_by_path_list(CxpathJson *self, cJSON *value, cJSON *path_list);

void private_CxpathJson_set_cjson_by_va_arg(CxpathJson *self, cJSON *value, const char *format, va_list args);

void CxpathJson_set_cjson(CxpathJson *self, cJSON *value, const char *format, ...);

void CxpathJson_set_str(CxpathJson *self, const char *value, const char *format, ...);

void CxpathJson_set_str_getting_ownership(CxpathJson *self,  char *value, const char *format, ...);

void CxpathJson_set_double(CxpathJson *self, double value, const char *format, ...);

void CxpathJson_set_long(CxpathJson *self, long value, const char *format, ...);

void CxpathJson_set_bool(CxpathJson *self, bool value, const char *format, ...);

