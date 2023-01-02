bool isValidSerialization(char * preorder){
    int s[10000] = {0,};
    int top = -1;
    int flag = 0;
    if(*preorder == NULL || ((*preorder == '#') && *(preorder + 1) == '\0')){
        return true;
    }
    if((*preorder == '#') && (*(preorder + 1) != '\0')){
        return false;
    }
    while(*preorder != '\0'){
        if(*preorder == ','){
            preorder++;
        }
        if(top == -1){
            s[++top] = *preorder;
            preorder++;
        }
        else if(*preorder >= '0' && *preorder <= '9'){
            s[++top] = *preorder;
            while(*preorder != ','){
                preorder++;
            }
        }
        else if(*preorder == '#' && s[top] != '#'){
            s[++top] = *preorder;
            preorder++;
        }
        else{
            top -= 2;
            while(top >= 0 && s[top] == '#'){
                top -= 2;
            }
            if(top < -1){
                flag = 1;
            }
            else{
                s[++top] = *preorder;
            }
            preorder++;
        }
        if(flag){
            break;
        }
    }
    if(flag){
        return false;
    }
    if(top == 0 && s[top] == '#'){
        return true;
    }    
    else{
        return false;
    }
}
