#include "src/one.c"


int  main(){
    

    CxpathJson *t = newCxpathJson__from_file("a.json");

    CxpathJson_free(t);
}