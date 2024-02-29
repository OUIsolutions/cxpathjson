

CxpathJson * private_newCxpathJson();



CxpathJson * newCxpathJson_from_cJSON(cJSON *element);

CxpathJson * newCxpathJsonObject();

CxpathJson * newCxpathJsonArray();

CxpathJson * newCxpathJson_from_string( const char *data);

CxpathJson * newCxpathJson_from_file(const char *path);


void CxpathJson_free(CxpathJson * self);
