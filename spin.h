#ifndef SPIN_H
#define SPIN_H

#include <stdlib.h>

struct spin{
	void *data;
	_Atomic size_t ticket;
	_Atomic size_t current;
};

struct spin spin_new(void *data);
#define spin_const_new(d) (struct spin) { .data = d, .ticket = 0, .current = 0 }

void *spin_lock(struct spin *spin);
void spin_unlock(struct spin *spin);

#define _concat(a, b) a ## b
#define concat(a, b) _concat(a, b)
#define macro_var(name) concat(a, __LINE__)
#define spin(def, sp) int macro_var(_mi_) = 0; for (def = spin_lock(sp); !macro_var(_mi_); (macro_var(_mi_) += 1, spin_unlock(sp)))

#endif
