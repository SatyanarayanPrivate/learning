#include <linux/init.h>
#include <linux/module.h>
#include <linux/proc_fs.h>
#include <linux/slab.h>
#include <linux/seq_file.h>
#include <linux/seq_file.h>

#define PROC_NAME "slab_proc"
#define SLAB_CACHE_NAME "myslab_cache"

struct myslab_data {
    struct list_head list;
    // by changing buffer size you observe data in /proc/slabinfo
    char info [4096];
};

static struct proc_dir_entry *proc_entry;
static struct kmem_cache *myslab_cache;
static LIST_HEAD (myslab_list);

static void *slab_seq_start (struct seq_file *seq, loff_t *pos) {
    
    loff_t offset = 0x00;
    struct myslab_data *p;
    
    printk ("myslab:: seq_start \n");
    list_for_each_entry (p, &myslab_list, list) {
        if (offset == *pos) {
            printk ("myslab:: seq_start: start\n");
            return p;
        }
    }
    
    printk ("myslab:: seq_start: startover\n");
    
    return NULL;
}

static int slab_seq_show (struct seq_file *seq, void *v) {
    
    struct myslab_data *p = (struct myslab_data *) v;
    
    printk ("myslab:: seq_show\n");
    seq_printf (seq, p ->info);
    return 0;
}


static void * slab_seq_next (struct seq_file *seq, void *v, loff_t *pos) {
    struct list_head *next_list = ((struct myslab_data *)v) ->list.next;
    
    printk ("myslab:: seq_next\n");
    ++*pos;
    
    if (next_list != &myslab_list) {
        return next_list;
    }
    printk ("myslab:: seq_next: stopped\n");
    return NULL;
}

static void slab_seq_stop (struct seq_file *seq, void *v) {
    printk ("myslab:: seq_stop\n");
    return ;
}

static struct seq_operations slab_seq_ops = {
    .start = slab_seq_start,
    .show = slab_seq_show,
    .next = slab_seq_next,
    .stop = slab_seq_stop,
};

static int slab_file_open (struct inode *node, struct file *file) {
    
    return seq_open (file, &slab_seq_ops);
};

struct file_operations slab_file_ops = {
    .owner = THIS_MODULE,
    .open = slab_file_open,
    .llseek = seq_lseek,
    .read = seq_read,
    .release = seq_release,
};

static int __init slab_init (void) {
    
    struct myslab_data *new_obj = NULL;
    int counter = 0x00;
    
    printk ("myslab:: \n");
    printk ("myslab:: init\n");
    proc_entry = proc_create_data (PROC_NAME, S_IRUSR, NULL, &slab_file_ops, NULL);
    if (proc_entry == NULL) {
        printk ("myslab:: init: error in proc_create_data\n");
        return -EINVAL;
    }
    
    myslab_cache = kmem_cache_create (SLAB_CACHE_NAME, sizeof(struct myslab_data), 0, 0, NULL);
    if (myslab_cache == NULL) {
        printk ("myslab:: init: error in kmem_cache_create\n");
        return -ENOMEM;
    }
    
    for (counter = 0x01; counter <= 100 ;counter ++) {
        new_obj = kmem_cache_alloc (myslab_cache, GFP_KERNEL);
        if (new_obj == NULL) {
            printk ("myslab:: init: error in kmem_cache_alloc\n");
            return -ENOMEM;
        }
        sprintf (new_obj ->info, "Object:: %4d\n", counter);
        list_add_tail (&new_obj ->list, &myslab_list);
        printk ("Added:: %s\n", new_obj ->info);
    }    
    
    return 0;
}


static void slab_exit (void) {
    struct myslab_data *p, *n;
    list_for_each_entry_safe (p, n, &myslab_list, list) {
        kmem_cache_free (myslab_cache, p);
    }
    kmem_cache_destroy (myslab_cache);
    remove_proc_entry (PROC_NAME, NULL);
    printk ("myslab:: exit\n");
}


module_init (slab_init);
module_exit (slab_exit);