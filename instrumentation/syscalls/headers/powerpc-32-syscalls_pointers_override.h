/* SPDX-License-Identifier: (GPL-2.0-only or LGPL-2.1-only) */

#define OVERRIDE_TABLE_32_mmap2

#ifndef CREATE_SYSCALL_TABLE

#define OVERRIDE_32_pipe
SC_LTTNG_TRACEPOINT_EVENT(pipe,
	TP_PROTO(sc_exit(long ret,) int * fildes),
	TP_ARGS(sc_exit(ret,) fildes),
	TP_FIELDS(sc_exit(ctf_integer(long, ret, ret))
		sc_out(ctf_user_array(int, fildes, fildes, 2))
	)
)

#else	/* CREATE_SYSCALL_TABLE */

#define OVERRIDE_TABLE_32_execve
TRACE_SYSCALL_TABLE(execve, execve, 11, 3)
#define OVERRIDE_TABLE_32_clone
TRACE_SYSCALL_TABLE(clone, clone, 120, 5)

#endif /* CREATE_SYSCALL_TABLE */

