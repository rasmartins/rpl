#ifndef RPL_BIT_VECTOR_H_INCLUDED_
#define RPL_BIT_VECTOR_H_INCLUDED_

typedef struct rpl_bit_vector* rpl_bit_vector_t;

rpl_bit_vector_t
rpl_bit_vector_new(unsigned length);

void
rpl_bit_vector_free(rpl_bit_vector_t* bit_vector);

rpl_bit_vector_t
rpl_bit_vector_length(const rpl_bit_vector_t bit_vector);

unsigned
rpl_bit_vector_get(const rpl_bit_vector_t bit_vector, unsigned index);

unsigned
rpl_bit_vector_set(rpl_bit_vector_t bit_vector, unsigned index, unsigned value);


#endif
