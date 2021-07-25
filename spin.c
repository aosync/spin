#include "spin.h"

struct spin
spin_new(void *data)
{
	return spin_const_new(data);
}

void *
spin_lock(struct spin *spin)
{
	size_t ticket = spin->ticket++;
	while(ticket != spin->current);
	return spin->data;
}

void
spin_unlock(struct spin *spin)
{
	spin->current++;
}
