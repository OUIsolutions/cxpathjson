

CxpathJsonNamespace newCxpathJsonNamespace(){
    CxpathJsonNamespace self;
    self.new_from_cJSON = newCxpathJson_from_cJSON;
    self.newJsonObject = newCxpathJsonObject;
    self.newJsonArray = newCxpathJsonArray;
    self.new_from_string = newCxpathJson_from_string;
    self.new_from_file = newCxpathJson_from_file;

    return self;
}