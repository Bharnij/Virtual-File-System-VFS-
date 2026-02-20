#ifndef VFS_META_H
#define VFS_META_H

#include <stdint.h>
#include "vfs_cntx.h"

#define VFS_FILENAME_MAX 64
#define VFS_MAX_FILES 128


typedef struct {

    char filename[VFS_FILENAME_MAX];

    uint64_t offset;    
    uint64_t size;      
    uint8_t used;        
    uint8_t padding[7];
    
} VFS_FileEntry;


typedef struct {

    VFS_FileEntry entries[VFS_MAX_FILES];

} VFS_MetadataTable;


int vfs_meta_init(VFS *vfs);
int vfs_meta_load(VFS *vfs, VFS_MetadataTable *table);
int vfs_meta_sync(VFS *vfs, VFS_MetadataTable *table);

#endif






