

cJSON * private_CxpathJson_cJSON_by_cjson_path_list(CxpathJson * self, cJSON *path_list);


cJSON * private_CxpathJson_get_cJSON_by_vargs(CxpathJson * self, const char *format, va_list args);


cJSON * CxpathJson_get_cJSON(CxpathJson * self, const char *format, ...);

const char * CxpathJson_get_str(CxpathJson * self, const char *format, ...);

double cxpathjson_get_double(CxpathJson * self, const char *format, ...);

int cxpathjson_get_int(CxpathJson * self, const char *format, ...);

bool cxpathjson_get_bool(CxpathJson * self, const char *format, ...);


int cxpathjson_size(CxpathJson * self, const char *format, ...);
