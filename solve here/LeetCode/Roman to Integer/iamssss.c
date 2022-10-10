char * intToRoman(int num){
    char *ret=malloc(30*sizeof(char));
    
    int cnt=0; int i=0;
    if(num/1000>0){
        for(i=0;i<num/1000;i++)
            ret[cnt++]='M';
        num=num%1000;
    }
    if(num/900>0){ 
        ret[cnt++]='C'; ret[cnt++]='M'; num=num%900;
    }else{
        if(num/500>0){
            ret[cnt++]='D'; num=num-500;            
        }else if(num/400>0){
            ret[cnt++]='C'; ret[cnt++]='D'; num=num-400;
        }
        if(num/100>0){
            for(i=0;i<num/100;i++)
                ret[cnt++]='C';            
            num=num%100;
        }        
    }    
    if(num/90>0){
        ret[cnt++]='X'; ret[cnt++]='C'; num=num%90;
    }else{
        if(num/50>0){
            ret[cnt++]='L'; num=num-50;            
        }else if(num/40>0){
            ret[cnt++]='X'; ret[cnt++]='L'; num=num-40;
        }
        if(num/10>0){
            for(i=0;i<num/10;i++)
                ret[cnt++]='X';
            num=num%10;
        }        
    }    
    if(num/9>0){
        ret[cnt++]='I'; ret[cnt++]='X';
    }else{
        if(num/5>0){
            ret[cnt++]='V'; num=num-5;            
        }else if(num/4>0){
            ret[cnt++]='I'; ret[cnt++]='V'; num=num-4;
        }
        if(num>0){
            for(i=0;i<num;i++)
                ret[cnt++]='I';
        }        
    }
    
    ret[cnt]='\0';    
    return ret;    
}
