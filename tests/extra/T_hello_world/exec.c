
#include "../../../CxpathJson.h"


CxpathJsonNamespace xpath;
CxpathJsonErrorNamespace errors;


int main(){
    xpath = newCxpathJsonNamespace();
    errors = xpath.errors;
    CxpathJson *t = xpath.newJsonObject();
    xpath.set_str(t,"hello world","['a']");
    char *content = xpath.dump_to_string(t,true);
    printf("%s",content);
    free(content);
    xpath.free(t);


}