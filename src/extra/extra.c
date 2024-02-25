
int private_cjson_path_convert_index(int index,int size){
    if(index >=0){
        return index;
    }
    return (size +index);


}