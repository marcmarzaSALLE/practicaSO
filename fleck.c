#include "fleck.h"
#include "reads.h"

Fleck fleck;

char *checkName(char *name){
    int i=0, j=0;

    char *aux = (char *)malloc(sizeof(char));

    while(name[i] != '\0'){
        if(name[i] != '&'){
            aux = (char*)realloc(aux, sizeof(char) * (j+2));
            aux[j++] = name[i];
        }
        i++;
    }
    aux[j] = '\0';
    
    return aux;
}

void readConfig(char *nameFile){
    int fd;
    char *name;
    //char *directory;
    //int size;
    char *aux;
    writing("Reading config file\n");
    //Show name of file
    writing(nameFile);
    fd = open(nameFile, O_RDONLY);
    if(fd != 0){
        name = read_until(fd, '\n');
        writing(name);
        fleck.name = checkName(name);
        free(name);
        //directory = read_until(fd, '\n');
        fleck.ipServer = read_until(fd, '\n');
        aux = read_until(fd, '\n');
        fleck.portServer = atoi(aux);
        free(aux);
    }else{
        writing("Error: File not found\n");
        close(fd);
        exit(0);
    }
}

int main(int argc, char **argv){
    if(argc != 2){
        writing("Error: Missing arguments\n");
        writing("Usage: ./fleck <config_file>\n");
        exit(1);
    } else {
        readConfig(argv[1]);
    }

    return 0;

}