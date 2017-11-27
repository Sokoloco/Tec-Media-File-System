//
// Created by pedro on 25/11/17.
//

#ifndef TECMFS_DISK_CLIENTE_H
#define TECMFS_DISK_CLIENTE_H

#include <iostream>
#include <netinet/in.h>
#include <cstring>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <stdio.h>
#include <stdlib.h>


class cliente {
public:
    struct sockaddr_in direccionServidor;
    int cliente;
    bool conectado = false;

    //estructura para guardar las direcciones y puertos de servidores
    struct direc{
        char* ip = new char();
        char* ipHA = new char();
        int port,portHA;
    }direc1;

    void init(char* dir[]);
    bool conectar();
    void sendM(char msj[]);
    void recibir(char* txt);


};


#endif //TECMFS_DISK_CLIENTE_H
