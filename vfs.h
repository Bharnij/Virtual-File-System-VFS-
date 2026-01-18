

#ifndef VFS_H

#define VFS_H


#include <stdint.h>


#define VFS_MAGIC 0x56465331  // written in hex: 'VFS1'

#define VFS_VERSION 1


typedef struct {

    uint32_t magic;

    uint32_t version;

    uint32_t block_size;

    uint32_t total_blocks;

} Superblock;


#endif