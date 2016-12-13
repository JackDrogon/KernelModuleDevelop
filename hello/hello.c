#include <linux/init.h>
#include <linux/module.h>


static int __init hello_init(void)
{
	int num = 0;
	printk(KERN_INFO "Hello LKM at address 0x%p on stack 0x%p\n", hello_init, &num);
	return 0;
}

static void __exit hello_exit(void)
{
	printk("Exiting from 0x%p... Goodbye, Hello LKM!\n", hello_exit);
}

module_init(hello_init);
module_exit(hello_exit);

MODULE_AUTHOR("Drogon jack.xsuperman@gmail.com");
MODULE_DESCRIPTION("LKM minimal module");
MODULE_VERSION("0.1.2");
MODULE_LICENSE("GPL");
