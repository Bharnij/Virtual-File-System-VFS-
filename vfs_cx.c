#include <stdio.h>

#include "vfs.h"

// out is the pointer to a SB, where the read data will be stored
int vfs_open(const char *filename, Superblock *out) {

    //opens the file in read-only mode ; 'rb' = read binary
    FILE *fp = fopen(filename, "rb"); 

    if (!fp) {
        perror("Failed to open FS");
        return -1;
    }

    // reads data from the file and stores it in out
    // reads 1 block , of the size ____
    size_t read = fread(out, sizeof(Superblock), 1, fp);

    // checks if exactly 1 SB was read
    if (read != 1) {
        perror("Failed to read SB");
        fclose(fp);
        return -1;
    }

    fclose(fp);

    // checks for the signature magic number
    if (out->magic != VFS_MAGIC) {
        printf("bad magic number\n");
        return -1;
    }

    // checks for the version
    if (out->version != VFS_VERSION) {
        printf("Unsupported FS version\n");
        return -1;
    }

    return 0;
}









