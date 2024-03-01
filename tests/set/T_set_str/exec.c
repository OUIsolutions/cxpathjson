
#include "../../../CxpathJson.h"


CxpathJsonNamespace xpath;
CxpathJsonErrorNamespace errors;


int main(){
    xpath = newCxpathJsonNamespace();
    errors = xpath.errors;
    CxpathJson *t = xpath.newJsonObject();
    char *heap_str = strdup("Hello World");
    xpath.set_str(t, heap_str,"['a', 'b']");

    char *result = xpath.dump_to_string(t, false);
    printf("%s",result);
    xpath.free(t);
    free(result);



}