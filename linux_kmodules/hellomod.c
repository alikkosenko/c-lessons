#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/init.h>



static int __init hellomod_init(void){
  printk(KERN_INFO "Hello, kernel");
  return 0;
}


static void __exit hellomod_exit(void){
  printk(KERN_INFO "Goodby, kernel");
}

module_init(hellomod_init);
module_exit(hellomod_exit);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Oleksii Kosenko");
MODULE_DESCRIPTION("Simple kernel module");
