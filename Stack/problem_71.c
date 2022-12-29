char * simplifyPath(char * path){
    int len = 0;
    char *dup = path;
    char *result;
    int ind = -1;
    while(*dup != '\0'){
        len++;
        dup++;
    }
    len++;
    if(path[0] == '.'){
        result = malloc((len + 5) * sizeof(char));
        path++;
        result[0] = '/';
        result[1] = 'h';
        result[2] = 'o';
        result[3] = 'm';
        result[4] = 'e';
        ind = 4;
    }
    else{
        result = malloc((len + 1) * sizeof(char));
        result[0] = '/';
        path++;
        ind = 0;
    }
    
    while(*path != '\0'){
        if((*path >= 'a' && *path <= 'z') || (*path >= 'A' && *path <= 'Z') || (*path == '_') || ((*path >= '0') && *path <= '9')){
            ind++;
            result[ind] = *path;
        }
        else if((*path == '.') && (ind >= 1) && (result[ind] == '.') && (result[ind - 1]) == '/' && ((*(path + 1) == '/') || (*(path + 1) == '\0'))){
            ind -= 3;
            while(ind >= 0 && result[ind] != '/'){
                ind--;
            }
        }
        else if((*path == '/') && (ind >= 0) && (result[ind] != '/')){
            ind++;
            result[ind] = *path;
        }
        else if((*path == '.') && (result[ind] == '/') && ((*(path + 1) == '/') || *(path + 1) == '\0')){
            ;
        }
        else if(*path == '.' && (ind >= 0)){
            ind++;
            result[ind] = *path;
        }
        path++;
        if(ind < 0){
            ind = 0;
        }
    }
    if(ind == 0 || result[ind] != '/'){
        result[++ind] = '\0';
    }
    else{
        result[ind] = '\0';
    }
    return result;
}
