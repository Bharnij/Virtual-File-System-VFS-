#include <stdio.h>   //
#include <stdlib.h>  // initialized , has malloc 
#include "vfs.h"     //

int vfs_init(const char *filename){

    // Opens file in write mode - "wb": write in binary
    FILE *fp = fopen(filename, "wb");

    if(fp == NULL){

        perror("FS file not created");
        return -1;

    }

    Superblock sb;

    sb.magic = VFS_MAGIC;
    sb.block_size = 4096;
    sb.version = VFS_VERSION;
    sb.total_blocks = 1024;

    size_t written = fwrite(&sb, sizeof(Superblock), 1, fp);

    if (written != 1) {

        perror("Failed to write superblock");

        fclose(fp);
        return -1;
    }

    fclose(fp); // flushes buffered data and releases OS resources
    return 0;    

}
