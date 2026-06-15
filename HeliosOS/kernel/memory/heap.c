#include "heap.h"

typedef struct block
{
    uint32_t size;
    uint8_t free;

    struct block* next;
} block_t;

static block_t* heap_head = 0;

static void memory_copy(uint8_t* dst, uint8_t* src, uint32_t size)
{
    while(size--)
        *dst++ = *src++;
}

static void memory_set(uint8_t* ptr, uint8_t value, uint32_t size)
{
    while(size--)
        *ptr++ = value;
}

void heap_init(uint32_t start, uint32_t size)
{
    heap_head = (block_t*)start;

    heap_head->size = size - sizeof(block_t);
    heap_head->free = 1;
    heap_head->next = 0;
}

static block_t* find_free_block(uint32_t size)
{
    block_t* current = heap_head;

    while(current)
    {
        if(current->free && current->size >= size)
            return current;

        current = current->next;
    }

    return 0;
}

static void split_block(block_t* block, uint32_t size)
{
    if(block->size <= size + sizeof(block_t))
        return;

    block_t* new_block =
        (block_t*)((uint8_t*)block +
        sizeof(block_t) + size);

    new_block->size =
        block->size - size - sizeof(block_t);

    new_block->free = 1;
    new_block->next = block->next;

    block->size = size;
    block->next = new_block;
}

void* kmalloc(uint32_t size)
{
    if(size == 0)
        return 0;

    size = (size + 7) & ~7;

    block_t* block = find_free_block(size);

    if(!block)
        return 0;

    split_block(block, size);

    block->free = 0;

    return (uint8_t*)block + sizeof(block_t);
}

void kfree(void* ptr)
{
    if(!ptr)
        return;

    block_t* block =
        (block_t*)((uint8_t*)ptr -
        sizeof(block_t));

    block->free = 1;

    block_t* current = heap_head;

    while(current && current->next)
    {
        if(current->free &&
           current->next->free)
        {
            current->size +=
                sizeof(block_t) +
                current->next->size;

            current->next =
                current->next->next;
        }
        else
        {
            current = current->next;
        }
    }
}

void* kcalloc(uint32_t count, uint32_t size)
{
    uint32_t total = count * size;

    void* ptr = kmalloc(total);

    if(ptr)
        memory_set(ptr, 0, total);

    return ptr;
}

void* krealloc(void* ptr, uint32_t size)
{
    if(!ptr)
        return kmalloc(size);

    if(size == 0)
    {
        kfree(ptr);
        return 0;
    }

    block_t* old_block =
        (block_t*)((uint8_t*)ptr -
        sizeof(block_t));

    if(old_block->size >= size)
        return ptr;

    void* new_ptr = kmalloc(size);

    if(!new_ptr)
        return 0;

    memory_copy(
        new_ptr,
        ptr,
        old_block->size
    );

    kfree(ptr);

    return new_ptr;
}
