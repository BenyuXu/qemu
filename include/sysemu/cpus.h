#ifndef QEMU_CPUS_H
#define QEMU_CPUS_H

/* cpus.c */
bool qemu_in_vcpu_thread(void);
void qemu_init_cpu_loop(void);
void resume_all_vcpus(void);
int  get_pcpu_num(bool pin_default, int *pcpu_id_array);
void pin_all_vcpus(int smp_cpu_num, const int *pcpu_id_array, Error **errp);
void pause_all_vcpus(void);
void cpu_stop_current(void);
void cpu_ticks_init(void);

void configure_icount(QemuOpts *opts, Error **errp);
extern int use_icount;
extern int icount_align_option;

/* drift information for info jit command */
extern int64_t max_delay;
extern int64_t max_advance;
void dump_drift_info(FILE *f, fprintf_function cpu_fprintf);

/* Unblock cpu */
void qemu_cpu_kick_self(void);

void cpu_synchronize_all_states(void);
void cpu_synchronize_all_post_reset(void);
void cpu_synchronize_all_post_init(void);

void qtest_clock_warp(int64_t dest);

#ifndef CONFIG_USER_ONLY
/* vl.c */
/* *-user doesn't have configurable SMP topology */
extern int smp_cores;
extern int smp_threads;
#endif

void list_cpus(FILE *f, fprintf_function cpu_fprintf, const char *optarg);

#endif
