bool buddyStrings(char * s, char * goal){
    int len1=strlen(s);
    int len2=strlen(goal);
    if(len1!=len2)return false;
    int i=0,j=0;
    int k=0,t1,t2;
    while(i<=len1)
    {
        if(s[i]!=goal[j])
        {
            k++;
            if(k>2)return false;
            t1=i;
            if(k<2)t2=t1;
        }
        i++;
        j++;
    }
    //k==0,1,2;
    char t;
    if(k==1)return false;
    if(k==2)
    {
        memcpy(&t,&s[t2],sizeof(char));
        memcpy(&s[t2],&s[t1],sizeof(char));
        memcpy(&s[t1],&t,sizeof(char));
        return strcmp(s,goal)==0?true:false;
    }
    if(k==0)
    {
        for(int i=0;i<len1;i++)
        {
            for(int j=i+1;j<len1;j++)
            {
                if(s[i]==s[j])return true;      
            }
        }
        
    }
    return false;
}