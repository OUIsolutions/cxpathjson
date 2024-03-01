#include "../../../CxpathJson.h"


CxpathJsonNamespace xpath;
CxpathJsonErrorNamespace errors;


int main(){
    xpath = newCxpathJsonNamespace();
    errors = xpath.errors;
    CxpathJson *t = xpath.newJsonObject();
    xpath.set_str(t,"teste","['a']['b']");
    char *content = xpath.dump_to_string(t, false);
    printf("%s", content);
    xpath.free(t);
    free(content);

    

}