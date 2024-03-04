
#include "src/one.c"




CxpathJsonNamespace xpath;
CxpathJsonErrorNamespace errors;



int main(){
    xpath = newCxpathJsonNamespace();
    errors = xpath.errors;
    CxpathJson *a = xpath.newJsonObject();
    xpath.set_str(a ,"t value" ,"['a']");

    CxpathJson *b = xpath.newJsonObject();
    xpath.set_str(b,"t2 value","['b1']");


   xpath.set_xpathJson_getting_onwership(a,b,"['b']");

    char *result = xpath.dump_to_string(a, false);
    printf("%s",result);
    xpath.free(a);
    free(result);


}