
#include "CxpathJson.h"


CxpathJsonNamespace xpath;
CxpathJsonErrorNamespace errors;


int main(){
    xpath = newCxpathJsonNamespace();
    errors = xpath.errors;
    CxpathJson *t = xpath.newJsonObject();
    xpath.set_str(t, "Mateus","['a', 'name']");
    xpath.set_int(t, 27,"['a', 'age']");
    xpath.set_double(t, 1.80,"['a', 'height']");
    xpath.set_bool(t,true,"['a', 'maried']");

    char *result = xpath.dump_to_string(t, false);
    printf("%s",result);
    xpath.free(t);
    free(result);



}