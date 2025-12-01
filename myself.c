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
static const char device_n[] = "myself";
static const char class_n[] = "myself_cls";
#include "generator/module.c"
