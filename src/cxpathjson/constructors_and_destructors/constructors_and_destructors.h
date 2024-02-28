

CxpathJson * private_newCxpathJson();



CxpathJson * newCxpathJson_from_cJSON(cJSON *element);

CxpathJson * newCxpathJson_from_string(int *error_code, const char *data);

CxpathJson * newCxpathJson__from_file(int *error_code, const char *path);


void CxpathJson_free(CxpathJson * self);
