/*
Copyright (c) 2016, prpl Foundation

Permission to use, copy, modify, and/or distribute this software for any purpose with or without 
fee is hereby granted, provided that the above copyright notice and this permission notice appear 
in all copies.

THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES WITH REGARD TO THIS SOFTWARE
INCLUDING ALL IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE 
FOR ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM 
LOSS OF USE, DATA OR PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, 
ARISING OUT OF OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.

This code was written by Carlos Moratelli at Embedded System Group (GSE) at PUCRS/Brazil.

*/

#ifndef _MALLOC_H_
#define _MALLOC_H_

#include <types.h>

typedef int32_t word_align;

union header{	 /* block header */
	struct{
		union header *ptr;	/* mnext block if on free list */
		uint32_t size;	 /* size of this block */
	} s;
	word_align x;	 /* force block alignment */
};

typedef union header mem_header;

void HeapInit(void *heap, uint32_t len);
void *malloc(uint32_t size);
void free(void *ptr);
void *calloc(uint32_t qty, uint32_t type_size);
void *realloc(void *ptr, uint32_t size);
uint32_t init_mem();

#endif
