#include "src/one.c"


int  main(){
    

    CxpathJson *t = newCxpathJson_from_file("a.json");

    int b = CxpathJson_get_int(t,"['a','b']");
    CxpathJson_catch(t){
        char *message = CxpathJson_get_error_message(t);
        printf("%s",message);

    }
    CxpathJson_protected(t){
        printf("%d\n",b);
    }

    CxpathJson_free(t);
}