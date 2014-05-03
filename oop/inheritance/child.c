/**
 * child.c  2014-05-02 23:11:33
 * anonymouse(anonymouse@email)
 *
 * Copyright (C) 2000-2014 All Right Reserved
 * 
 * THIS CODE AND INFORMATION ARE PROVIDED "AS IS" WITHOUT WARRANTY OF ANY
 * KIND, EITHER EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND/OR FITNESS FOR A
 * PARTICULAR PURPOSE.
 *
 * Auto generate for Design Patterns in C
 */
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <myobj.h>
#include "child.h"

static struct child_ops child_ops = {0
};
/** called by free(): put resources, forward to super. */
static void child_ops__destructor(struct parent *parent)
{
	printf("child::_destructor()\n");
	/** PSEUDOCODE
	... do_something() to put resources ...
	CLASS_SUPER(parent, _destructor);
	*/
}
/** free memory after call destructor(). */
static void child_ops_free(struct parent *parent)
{
	printf("child::free()\n");
	/** PSEUDOCODE
	struct child *l_child = container_of(parent, typeof(*l_child), parent);
	parent__destructor(parent);
	free(l_child);
	*/
}

static void child_ops_pub_v_func1(struct parent *parent)
{
	printf("child::pub_v_func1()\n");
}

static void child_ops_pub_v_func2(struct parent *parent)
{
	printf("child::pub_v_func2()\n");
}

static void child_ops_pri_v_func3(struct parent *parent)
{
	printf("child::pri_v_func3()\n");
}

static void child_ops_pri_v_func4(struct parent *parent)
{
	printf("child::pri_v_func4()\n");
}

static struct parent_ops parent_ops = {
	._destructor = child_ops__destructor,
	.free = child_ops_free,
	.pub_v_func1 = child_ops_pub_v_func1,
	.pub_v_func2 = child_ops_pub_v_func2,
	.pri_v_func3 = child_ops_pri_v_func3,
	.pri_v_func4 = child_ops_pri_v_func4,
};

void child_init(struct child *child)
{
	memset(child, sizeof(*child), 0);
	parent_init(&child->parent);
	CLASS_OPS_INIT_SUPER(child->parent.ops, parent_ops);
	child->ops = &child_ops;
}