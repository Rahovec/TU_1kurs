//compile command gcc FSAE.c hiredis.c net.c sds.c async.c dict.c read.c -o FSAE


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "hiredis.h"



int main() {
    int j;
    redisContext *c;
    redisReply *reply;
    const char *hostname ="127.0.0.1";
    int port = 6379;

    
    c = redisConnect(hostname, port);

    /* PING server */
    reply = redisCommand(c,"PING");
    printf("PING: %s\n", reply->str);
    freeReplyObject(reply);

	reply = redisCommand(c,"DEL rpmlist");
	freeReplyObject(reply);

	for(j = 0; j<1000; j++){	
	reply = redisCommand(c,"LPUSH rpmlist %d", j);
	freeReplyObject(reply);
	}
	
	
	
	redisFree(c);
	return 0;
}
