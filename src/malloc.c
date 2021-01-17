/*
** EPITECH PROJECT, 2020
** PSU_2019_malloc
** File description:
** malloc
*/

#include "../include/malloc.h"

static mem_block_t *list = NULL;

mem_block_t *create_page(mem_block_t *head, size_t old_size)
{
    mem_block_t *new_block = sbrk(0);
    size_t size = page_alloc(old_size);

    if ((new_block = (mem_block_t *)sbrk(size)) == (void *) - 1)
        return (NULL);
    new_block->address = (void *)((long)new_block + sizeof(mem_block_t));
    new_block->free = true;
    new_block->size = size - sizeof(mem_block_t);
    new_block->next = NULL;
    if (head != NULL) {
        head->next = new_block;
    }
    new_block->prev = head;
    split_block(new_block, old_size);
    return (new_block);
}

mem_block_t *assign_block(mem_block_t *new_block, mem_block_t *tmp, size_t size)
{
    if (!(new_block = best_fit(tmp, size)))
        if (!(new_block = create_page(list, size + sizeof(mem_block_t))))
            return (NULL);
    else {
        if ((size + sizeof(mem_block_t)) < new_block->size)
            split_block(new_block, size + sizeof(mem_block_t));
    }
    return (new_block);
}

void *malloc(size_t s)
{
    mem_block_t *new_block;
    mem_block_t *tmp = list;
    size_t size = align_memory(s);

    if (!list) {
        if (!(new_block = create_page(NULL, size)))
            return (NULL);
        list = new_block;
    }
    else {
        new_block = assign_block(new_block, tmp, size);
    }
    return (new_block->address);
}

void free(void *ptr)
{
    mem_block_t *tmp = list;

    if (!ptr)
        return;
    while (tmp) {
        if (tmp->address == ptr) {
            tmp->free = true;
        }
        tmp = tmp->next;
    }
}