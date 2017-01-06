#include <linux/init.h>
#include <linux/module.h>
#include <linux/fs.h>

int 


static int __init char_init (void) {
    
    
    
    return 0;
}

static void __exit char_exit (void) {

    
}

module_init (char_init);
module_init (char_exit);