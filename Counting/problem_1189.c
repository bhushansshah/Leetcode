int maxNumberOfBalloons(char * text){
    int hm[26] = {0,};
    int result = 0;
    while(*text != '\0'){
        hm[*text - 'a']++;
        text++;
    }
    if(hm['a' - 'a'] == 0){
        return 0;
    }
    else{
        result = hm['a' -'a'];
    }
    if(hm['b' - 'a'] == 0)
        return 0;
    else{
        if(result > hm['b' - 'a']){
            result = hm['b' - 'a'];
        }
    }
    if(hm['n' - 'a'] == 0)
        return 0;
    else{
        if(result > hm['n' - 'a']){
            result = hm['n' - 'a'];
        }
    }
    if(hm['l' - 'a'] < 2)
        return 0;
    else{
        if(result > (hm['l' - 'a'] / 2)){
            result = hm['l' - 'a'] / 2;
        }
    }
    if(hm['o' - 'a'] < 2)
        return 0;
    else{
        if(result > (hm['o' - 'a'] / 2)){
            result = hm['o' - 'a'] / 2;
        }
    }
    return result;
}
