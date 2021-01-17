/*
** EPITECH PROJECT, 2020
** PSU_2019_malloc
** File description:
** malloc
*/

#ifndef MALLOC_H_
#define MALLOC_H_

// INCLUDE

#include <unistd.h>
#include <stdbool.h>
#include <stdio.h>

// DEFINE

#define PAGE_SIZE 8192

// STRUCTURE

typedef struct mem_block_s {
    size_t size;
    struct mem_block_s *next;
    struct mem_block_s *prev;
    bool free;
    void *address;
} mem_block_t;

// DECLARATION

void *malloc(size_t size);
void *calloc(size_t nmemb, size_t size);
void free(void *ptr);
mem_block_t *best_fit(mem_block_t *head, size_t size);
size_t page_alloc(size_t size);
mem_block_t *create_page(mem_block_t *head, size_t old_size);
void split_block(mem_block_t *block, size_t size);
size_t align_memory(size_t size);
mem_block_t *assign_block(mem_block_t *new_block, mem_block_t *tmp, size_t size);

#endif /* !MALLOC_H_ */