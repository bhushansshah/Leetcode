int longestPalindrome(char * s){
    int hm[130] = {0,};
    //char *p = s;
    int len =0;
    char i = 'A';
    while(*s != '\0'){
        hm[*s] = hm[*s] + 1;
        s++;
    }
    while(i <= 'z'){
        if((i <= 'Z' && i >= 'A') || (i <= 'z' && i >= 'a')){
            if((hm[i] != 0) && (hm[i] >= 2)){
                if(hm[i] % 2){
                    len += hm[i] - 1;
                    hm[i] = 1;
                }
                else{
                    len+= hm[i];
                    hm[i] = 0;
                }
            }
        }
        i++;
    }
    i = 'A';
    while(i <= 'z'){
        if((i <= 'Z' && i >= 'A') || (i <= 'z' && i >= 'a')){
            if(hm[i] != 0){
                len++;
                break;
            }
        }
        i++;
    }
    return len;
}
