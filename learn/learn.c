#include <stdio.h>
#include <ctype.h>
//变长参数使用
#include <stdarg.h>
int inputToLower(){
  int c;
  while((c=getchar())!=EOF){
    putchar(tolower(c));
  }
  return 0;
}

//变长参数
void minprintf(char *fmt,...){
    va_list ap;
    char *p,*sval;
    int ival;
    double dval;
    va_start(ap,fmt);
    for(p=fmt;*p;p++){
        if(*p!='%'){
            putchar(*p);
            continue;
        }
        switch(*++p){
    case 'd':
        ival =va_arg(ap,int);
        printf("%d",ival);
        break;
    case 'f':
        dval=va_arg(ap,double);
        printf("%f",dval);
        break;
    case 's':
        for(sval=va_arg(ap,char *);*sval;sval++){
            putchar(*sval);
        }
        break;
    default:
        putchar(*p);
        break;
        }
    }
    va_end(ap);
}

int cat(int argc,char *argv[]){
    FILE *fp;
    void filecopy(FILE *,FILE *);
    char *prog=argv[0];
    if(argc==1)
        filecopy(stdin,stdout);
    else{
        while(--argc>0){
            if((fp=fopen(*++argv,"r"))==NULL){
                sprintf(stderr,"%s: can`t open %s\n",prog,*argv);
                return 1;
            } else{
                filecopy(fp,stdout);
                fclose(fp);
            }
        }
    }
    if(ferror(stdout)){
        fprintf(stderr,"%s:error writing stdout\n",prog);
        return 2;
    }
    return 0;
}

void filecopy(FILE *ifp,FILE *ofp){
    int c;
    while((c=getc(ifp))!=EOF){
        putc(c,ofp);
    }
}

int mainfun(int argc,char *argv[]){
    int status=cat(argc,argv);
    exit(status);
}
