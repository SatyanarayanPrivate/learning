#include <linux/init.h>
#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/proc_fs.h>
#include <linux/seq_file.h>
#include <linux/sched.h>
#include <linux/slab.h>

#define MYPROC_NAME "myproc_name"

static struct proc_dir_entry *myproc_entry = NULL ;
static struct task_struct *ctask;

static void * myproc_seq_open (struct seq_file *seq, loff_t *pos) {
    loff_t offset = 0x00;
    
    for_each_process (ctask) {
        if (*pos == offset++) {
            printk ("myproc:: seq_open: start\n");
            return ctask;
        }
    }
    printk ("myproc:: seq_open: start over\n");
    return NULL;
}

static void * myproc_seq_next (struct seq_file *seq, void *data, loff_t *pos){
    
    struct task_struct *ntask = (struct task_struct *) data;
    
    ++*pos;
    printk ("myproc:: seq_next: %d\n", (int )*pos);
    
    ntask = next_task (ntask);
    
    if (ntask != &init_task) {
        return ntask;
    }
    
    return NULL;
}

static int myproc_seq_show (struct seq_file *seq, void *data) {
    int ret_val = 0x00;
    struct task_struct *vtask = (struct task_struct *) data;
    char *buffer = kmalloc (256, GFP_KERNEL);
    
    printk ("myproc:: seq_show\n");
    
    sprintf (buffer, "NAME::%s, PID:: %d, TGID:: %d, STATE:: %ul\n", vtask ->comm, vtask ->pid, vtask ->tgid, (unsigned int ) vtask ->state);
    ret_val = seq_printf (seq, buffer);
    
    kfree (buffer);
    
    return 0;    
}

static void myproc_seq_stop (struct seq_file *seq, void *data) {
    
    printk ("myproc:: seq_stop\n");
}


//seq_file operatinos
static struct seq_operations myproc_sep_ops = {
    .start = myproc_seq_open,
    .show = myproc_seq_show,
    .stop = myproc_seq_stop,
    .next = myproc_seq_next,
};

static int myproc_file_open (struct inode *node, struct file *file) {
    
    return seq_open (file, &myproc_sep_ops);
}

// file operations
static struct file_operations myproc_file_ops = {
    .owner = THIS_MODULE,
    .open = myproc_file_open,
    .read = seq_read,
    .llseek = seq_lseek,
    .release = seq_release,
};

static int __init myproc_init (void) {
    
    printk ("myproc:: init\n");
    
    // create proc entry
    myproc_entry =  proc_create_data (MYPROC_NAME,
                                             S_IRUSR,
                                             NULL,
                                             &myproc_file_ops,
                                             NULL);
    
 
//     if (myproc_parent_entry != NULL) {
//         myproc_entry =  proc_create_data ("myproc_sample",
//                                           S_IRUSR,
//                                           myproc_parent_file_ops,
//                                           &myproc_file_ops,
//                                           NULL);
//         if (myproc_entry == NULL) {
//             remove_proc_entry ("myproc_parent", NULL);
//             return -1;
//         }
//     }
    
    return 0;
}


static void __exit myproc_exit (void) {
    
    printk ("myproc:: exit\n");
    // destroy proc entry
    remove_proc_entry (MYPROC_NAME, NULL);
}


module_init (myproc_init);
module_exit (myproc_exit);

MODULE_LICENSE ("GPL");
MODULE_AUTHOR ("myproc_sample");
MODULE_DESCRIPTION ("sample myproc");
