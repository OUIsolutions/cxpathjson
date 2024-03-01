#include "CxpathJson.h"


CxpathJsonNamespace xpath;
CxpathJsonErrorNamespace errors;


int main(){
    xpath = newCxpathJsonNamespace();
    errors = xpath.errors;
    CxpathJson *t = xpath.newJsonObject();
    xpath.set_str(t,"test","['a']['b']");
    xpath.dump_to_file(t,"side_effect/b.json", true);
    xpath.free(t);
    printf("OK");

}