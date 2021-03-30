#include <stdio.h>
#include <string.h>


int main() {
    char url[1000];
    char protocol[4];
    char domain[50];
    int port=80;
    char path[50];
    char parameters[50];
    int protocol_error=0;
    int domain_error=0;
    int port_error=0;
    int path_error=0;
    int parameters_error=0;


    printf("Enter a URL to parse\n");
    scanf("%1000s",&url);
    printf("url = %s \n",url);
    sscanf(url,"%[^://]%*[:/]%[^:]:%d%[^?]%*[?]%s",protocol,domain,&port,path,parameters);




    if(port<1||port>65535){
        port_error=1;
    }

    char https[]="https";
    char http[]="http";
    char ftp[]="ftp";
    char ftps[]="ftps";
    if(strcmp(protocol,https)==0||strcmp(protocol,http)==0||strcmp(protocol,ftp)==0||strcmp(protocol,ftps)==0){
        protocol_error=0;
    }else{
        protocol_error=1;
    }

    char path_ch01;
    char path_end[50];
    char html[] = "html";
    char htm[] = "htm";
    char temp[10];
    char path_cp[50];
    //strcpy(path_cp,path)
    for (int i=0;i<50;i++){
        path_cp[i]=path[i];
    }
    sscanf(path_cp,"%[^.]%*[.]%s",temp,path_end);
    //printf("3parameters: %s\n", parameters);
   if(path[0]!='/'){
     path_error=3;
    }else{
        if(strcmp(path_end,htm)==0||strcmp(path_end,html)){
            path_error=1;
            parameters_error=4;
        }
    }


    char x[10];
    char y[10];
    char z[10];
    char com[]="com";
    char net[]="net";
    char edu[]="edu";
    char biz[]="biz";
    char gov[]="gov";
    //printf("4parameters: %s\n", parameters);
    int xyz=sscanf(domain,"%[^.]%*[.]%[^.]%*[.]%s",x,y,z);
    //printf("xyz: %d \n",xyz);
    if(xyz==3){
        if(strcmp(z,com)==0||strcmp(z,net)==0||strcmp(z,edu)==0||strcmp(z,biz)==0||strcmp(z,gov)==0){
            domain_error=0;
        }else
            domain_error=1;
    }else{
        domain_error=2;
        path_error=4;
        parameters_error=4;
    }
    //printf("5parameters: %s\n", parameters);
    if (protocol_error == 0) {
        printf("Protocol: %s \n", protocol);
    } else {
        printf("Protocol: %s is not a valid protocol.\n",protocol);
    }
    if(domain_error==2){
        printf("Invalid domain format must be in <x>.<y>.<z>\n");
    }else if(domain_error==1){
        printf("Domain: %s is an invalid host name must be com, net, edu, biz, or gov \n",z);
    }else{
        printf("Domain:  %s\n",domain);
    }


    if(port_error==1){
        printf("Port: %d is not a valid port number must be in the range of 1 to 65535.\n",port);
    }else
        printf("Port: %d \n",port);

    if(path_error==3){
        printf("Invalid path, does not start with '/'.\n");
    }else if(path_error==1){
        printf("Path: Invalid path does not end in .htm or .html\n");
    }else
        printf("Path: %s \n",path);
    if(parameters_error==4){
        printf("Parameters: ");

    }else if(parameters_error==1){
        printf("Invalid parameters string does not begin with a '?'.\n");
    }else
        printf("parameters: %s \n",parameters);

    return 0;
}
