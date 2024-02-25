#include "src/one.c"


int  main(){
    
    int error = 0;
    cJSON *t = cjson_path_load_from_file(&error,"teste.json");
    cJSON *created = cJSON_CreateNumber(10);
    cjson_path_set_cjson(t,created,"['a','b','c']");
    cjson_path_dump_to_file("r.json",t,true);
    cjson_path_free(t);


}