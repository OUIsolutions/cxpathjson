#include "src/one.c"


int  main(){
    
    int error = 0;
    cJSON *t = cxpathjson_load_from_file(&error, "teste.json");
    error  = cxpathjson_set_str(t, "aaaaaaa", "['a','b','c']");
    
        
    printf("result: %d\n",error);

    cxpathjson_dump_to_file("a.json", t, true);

    cxpathjson_free(t);


}