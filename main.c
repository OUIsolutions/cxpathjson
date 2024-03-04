
#include "src/one.c"




CxpathJsonNamespace xpath;
CxpathJsonErrorNamespace errors;



int main(){
    xpath = newCxpathJsonNamespace();
    errors = xpath.errors;
    cJSON *test =  cJSON_CreateObject();
    CxpathJson *a = xpath.new_from_cJSON_by_reference(test);
    cJSON_Delete(test);
    xpath.free(a);
}