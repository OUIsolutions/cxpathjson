
#include "../../../CxpathJson.h"



CxpathJsonNamespace xpath;
CxpathJsonErrorNamespace errors;


int main(){
    xpath = newCxpathJsonNamespace();
    errors = xpath.errors;
    CxpathJson *t =  xpath.newJsonObject();
    for(int i = 0; i < 3; i++){
        char name_formated[20] ={0};
        sprintf(name_formated,"name %d",i);
        xpath.set_str(t,name_formated,"['elements','$append','name']");
        xpath.set_int(t,i,"['elements',-1,'age']");
    }
    char * result = xpath.dump_to_string(t,true);

    if(errors.has_errors(t)){
        char *message =errors.get_error_message(t);
        int code = errors.get_error_code(t);
        printf("code: %d\n",code);
        printf("message: %s\n",message);
        printf("path %s\n",errors.get_error_path(t));
        xpath.free(t);
        return 0;
    }
    printf("%s",result);

    free(result);
    xpath.free(t);

}