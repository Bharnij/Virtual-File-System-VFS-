// defining a mounted file system

#ifndef VFS_CTX_H
#define VFS_CTX_H


#include <stdio.h>
#include "vfs.h"

// defining a structure
typedef struct {

    FILE *disk;

    Superblock sb;

} VFS;

int vfs_mount(const char *filename, VFS *vfs);
void vfs_unmount(VFS *vfs);


#endif





