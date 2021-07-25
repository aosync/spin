# spin

A trivial spinlock library.

## documentation

Spinlocks keep a reference to a variable, and they ensure it is being accessed only at one place at a time.

### spinlock creation

You can create a spinlock like this
```c
int myvar = 10;
struct spin sl = spin_new(&myvar);
```
but it is also possible to create spinlock statically, outside functions using the `spin_const_new` macro.

### locking and unlocking.

When the spinlock is locked, it returns a reference to the data pointed by the spinlock:
```c
int *myvarref = spin_lock(&sl);
*myvarref *= 2;
spin_unlock(&sl);
```

There is also a macro to make locking and unlocking scoped, and tidier:
```c
spin(int *myvarref, &sl){
	*myvarref *= 2;
}
```

## safety considerations

A variable should only be referenced by one spinlock.  
Spinlocks should live longer than all threads it is referenced by.  
Do not forcibly terminate threads.

## use the library in projects

Free free to ship `spin.c` and `spin.h` in your projects.  
However, if you are using the meson build system, I recommend using the [wrap dependency system](https://mesonbuild.com/Wrap-dependency-system-manual.html).
