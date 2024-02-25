#include "src/one.c"


int  main(){
    
    
    cJSON *t = cjson_path_load_from_file("teste.json");
    const char *a = cjson_path_get_str(t,"[\"a\"]");
    printf("%s\n",a);

    cjson_path_free(t);


}