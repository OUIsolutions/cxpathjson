
#include "../../../CxpathJson.h"


CxpathJsonNamespace xpath;
CxpathJsonErrorNamespace errors;


int main(){
    xpath = newCxpathJsonNamespace();
    errors = xpath.errors;
    CxpathJson *t = xpath.newJsonObject();
    xpath.set_int(t,10 ,"['a', 'b']");

    char *result = xpath.dump_to_string(t, false);
    printf("%s",result);
    xpath.free(t);
    free(result);



}