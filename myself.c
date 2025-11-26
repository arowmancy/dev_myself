/*
 *  myself.c
 *
 *  dev_myself - a linux module for myself.
 *
 *      provides a character device driver at /dev/myself.
 *
 *      adapted from https://github.com/tinmarino/dev_one.
 *
 */
static const char device_name[] = "myself";
#include "src/module.c"
