#include "src/one.c"


int  main(){
    
    int error = 0;
    cJSON *t = cjson_path_load_from_file(&error,"teste.json");
    int result = cjson_path_set_str(t,"aaaaaaa","['a','$append','c']");
    printf("result: %d\n",result);
    cjson_path_dump_to_file("a.json",t,true);
    cjson_path_free(t);


}