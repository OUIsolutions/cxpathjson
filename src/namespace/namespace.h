

typedef struct {


    CxpathJson * (*new_from_cJSON)(cJSON *element);
    CxpathJson * (*newJsonObject)(void);
    CxpathJson * (*newJsonArray)(void);
    CxpathJson * (*new_from_string)( const char *data);
    CxpathJson * (*new_from_file)(const char *path);
    void (*free)(CxpathJson * self);


}CxpathJsonNamespace;

CxpathJsonNamespace newCxpathJsonNamespace();