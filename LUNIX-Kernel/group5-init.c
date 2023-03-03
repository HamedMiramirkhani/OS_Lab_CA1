#include <linux/module.h>
#include <linux/kernel.h>

MODULE_LICENSE("GPL");

static int __init print_group_info(void) {
    printk(KERN_INFO "Group #5 :\n-Hamed Miramirkhani\n-Sina Tabsi\n-Fatemeh Mohammadi\n");
    return 0;
}
static void __exit outro(void) {
    printk(KERN_INFO "Goodbye :)\n");
}
module_init(print_group_info);
module_exit(outro);
