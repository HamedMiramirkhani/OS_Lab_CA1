#include <linux/module.h>
#include <linux/kernel.h>

MODULE_LICENSE("GPL");

int init_module(void) {
 printk(KERN_INFO "Group #5 :\n-Hamed Miramirkhani\n-Sina Tabsi\n-Fatemeh Mohammadi\n");
 return 0;
}

void cleanup_module(void) {}
