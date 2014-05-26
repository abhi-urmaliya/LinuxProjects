#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/init.h>
#include <linux/sched.h>
#include <linux/tty.h>
#include <linux/version.h>

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Abhilash 11BCE0098");
MODULE_DESCRIPTION("This module is created as an OS assignment for CSE211 on April 14th 2013. This is a digital version of the famous and entertaining Office Magic 8 Ball which offers predictions/advices/answers to questions posed by user. Note : Creators are not responsible for any action taken on user's part based on magic ball's answers!");

static int myint = 0;
module_param(myint, int, S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
MODULE_PARM_DESC(myint, "An integer");

static void print_string(char *str)
{
	struct tty_struct *my_tty;

#if ( LINUX_VERSION_CODE <= KERNEL_VERSION(2,6,5) )
	my_tty = current->tty;
#else
	my_tty = current->signal->tty;
#endif
	if (my_tty != NULL) {
		((my_tty->driver->ops)->write) (my_tty,
#if ( LINUX_VERSION_CODE <= KERNEL_VERSION(2,6,9) )
					   0,
#endif
					   str,
					   strlen(str));

#if ( LINUX_VERSION_CODE <= KERNEL_VERSION(2,6,9) )
		((my_tty->driver->ops)->write) (my_tty, 0, "\015\012", 2);
#else
		((my_tty->driver->ops)->write) (my_tty, "\015\012", 2);
#endif
	}
}

static int __init print_string_init(void)
{
       printk("Magic 8 Module has been loaded to the kernel successfully!");
       switch(myint)
       {
        case 0 : print_string("It is certain!");
		 break;
        case 1 : print_string("It is decidedly so!");
		 break;
	case 2 : print_string("Without a doubt!");
                 break;
	case 3 : print_string("Yes – definitely!");
                 break;
 	case 4 : print_string("You may rely on it!");
                 break;
	case 5 : print_string("As I see it, yes!");
                 break;
	case 6 : print_string("Most likely!");
                 break;
	case 7 : print_string("Outlook good!");
                 break;
	case 8 : print_string("Yes!");
                 break;
	case 9 : print_string("Signs point to yes!");
                 break;
	case 10 : print_string("Reply hazy, try again!");
                 break;
	case 11 : print_string("Ask again later!");
                 break;
	case 12 : print_string("Better not tell you now!");
                 break;
	case 13 : print_string("Cannot predict now!");
                 break;
	case 14 : print_string("Concentrate and ask again!");
                 break;
	case 15 : print_string("Don't count on it!");
                 break;
	case 16 : print_string("My reply is no!");
                 break;
	case 17 : print_string("My sources say no!");
                 break;
	case 18 : print_string("Outlook not so good!");
                 break;
	case 19 : print_string("Very doubtful!");
                 break;
       };
	return 0;
}

static void __exit print_string_exit(void)
{
	print_string("The Magic 8 Ball has spoken!");
	printk("The module has been unloaded successfully");
}

module_init(print_string_init);
module_exit(print_string_exit);
