#include <linux/init.h>
#include <linux/module.h>

// MODULE_DESCRIPTION("Hello, world!" minimal module");
// MODULE_LICENSE()

static int __init hello_printk_init(void)
{
	printk("Hello, HelloPrintk!\n");
	return 0;
}

static void __exit hello_printk_exit(void)
{
	printk("Goodbye, HelloPrintk!\n");
}

module_init(hello_printk_init);
module_exit(hello_printk_exit);

MODULE_VERSION("0.1.2");
MODULE_LICENSE("GPL");
MODULE_AUTHOR("Drogon jack.xsuperman@gmail.com");
