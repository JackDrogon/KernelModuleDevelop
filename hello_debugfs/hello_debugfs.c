#include <linux/debugfs.h>
#include <linux/kernel.h>
#include <linux/module.h>

static struct dentry *dir = NULL;
static unsigned int hello_debugfs;
static u32 sum = 0;

static int add_write(void *data, u64 value)
{
	sum += value;
	return 0;
}

DEFINE_SIMPLE_ATTRIBUTE(add_ops, NULL, add_write, "%llu\n");

static __init int hello_init(void)
{
	struct dentry *tmp_dir = NULL;

	/* create /sys/kernel/debug/hello_debugfs/ directory */
	dir = debugfs_create_dir("hello_debugfs", NULL);
	if (!dir) {
		printk(KERN_ALERT "debugfs_create_dir failed\n");
		return -1;
	}

	/* create /sys/kernel/debug/hello_debugfs/hello value, mode: rw*/
	tmp_dir = debugfs_create_u32("hello", 00666, dir, &hello_debugfs);
	if (!tmp_dir) {
		printk(KERN_ALERT "debugfs_create_u32 failed\n");
		return -1;
	}

	/* create /sys/kernel/debug/hello_debugfs/add value, mode: w*/
	tmp_dir = debugfs_create_file("add", 0222, dir, NULL, &add_ops);
	if (!tmp_dir) {
		printk(KERN_ALERT "debugfs_create_file failed\n");
		return -1;
	}

	/* create /sys/kernel/debug/hello_debugfs/sum value, mode: r*/
	tmp_dir = debugfs_create_u32("sum", 0444, dir, &sum);
	if (!tmp_dir) {
		printk(KERN_ALERT "debugfs_create_u32 failed\n");
		return -1;
	}

	return 0;
}

static void __exit hello_exit(void)
{
	printk(KERN_INFO "Exit hello_debugfs module\n");
	debugfs_remove_recursive(dir);
	dir = NULL;
}

module_init(hello_init);
module_exit(hello_exit);

MODULE_LICENSE("GPL");
MODULE_DESCRIPTION("Debugfs hello examle");
