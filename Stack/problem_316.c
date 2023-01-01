char * removeDuplicateLetters(char * s){
    int len = 0;
    char *dup = s;
    int hm[26] = {0,};
    int refer[26] = {0,};
    while(*dup != '\0'){
        len++;
        hm[*dup - 'a']++;
        dup++;
    }
    char *result = malloc(sizeof(char) * (len + 1));
    int ind = -1;
    while(*s != '\0'){
        hm[*s - 'a']--;
        if(ind == -1){
            result[++ind] = *s;
            refer[*s - 'a'] = 1;
        }
        if(refer[*s - 'a'] == 0){
            while((ind >= 0) && (*s < result[ind]) && (hm[result[ind] - 'a'] != 0)){
                refer[result[ind--] - 'a'] = 0;
            }
            result[++ind] = *s;
            refer[*s - 'a'] = 1;
        }
        s++;
    }
    result[++ind] = '\0';
    return result;
}
