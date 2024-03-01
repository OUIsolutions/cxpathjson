
#include "src/one.c"


CxpathJsonNamespace xpath;
CxpathJsonErrorNamespace errors;


int main(){
    xpath = newCxpathJsonNamespace();
    errors = xpath.errors;
    CxpathJson *t = xpath.newJsonObject();
    xpath.set_str(t,"['a']['b']","aaaaaaaa");
    char *content = xpath.dump_to_string(t, false);
    if(content){
        printf("%s", content);
        free(content);

    }
    xpath.free(t);

}