

CxpathJsonNamespace newCxpathJsonNamespace(){
    CxpathJsonNamespace self;
    self.new_from_cJSON = newCxpathJson_from_cJSON;
    self.newJsonObject = newCxpathJsonObject;
    self.newJsonArray = newCxpathJsonArray;
    self.new_from_string = newCxpathJson_from_string;
    self.new_from_file = newCxpathJson_from_file;

    self.get_bool = CxpathJson_get_bool;
    self.get_cJSON = CxpathJson_get_cJSON;
    self.get_double = CxpathJson_get_double;
    self.get_int = CxpathJson_get_int;
    self.get_str  = CxpathJson_get_str;
    self.size = CxpathJson_get_size;

    
    self.set_bool = CxpathJson_set_bool;
    self.set_long = CxpathJson_set_long;
    self.set_double = CxpathJson_set_double;
    self.set_cjson = CxpathJson_set_cjson;
    self.set_str  = CxpathJson_set_str;

    
    self.errors = newCxpathJsonErrorNamespace();

    return self;
}