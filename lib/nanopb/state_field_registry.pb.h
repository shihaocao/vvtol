/* Automatically generated nanopb header */
/* Generated by nanopb-0.4.8 */

#ifndef PB_LIB_NANOPB_STATE_FIELD_REGISTRY_PB_H_INCLUDED
#define PB_LIB_NANOPB_STATE_FIELD_REGISTRY_PB_H_INCLUDED
#include <pb.h>

#if PB_PROTO_HEADER_VERSION != 40
#error Regenerate this file with the current version of nanopb generator.
#endif

/* Struct definitions */
typedef struct _SFVector3f {
    pb_callback_t elements;
} SFVector3f;

typedef struct _SFVector4f {
    pb_callback_t elements;
} SFVector4f;

typedef struct _StateFieldRegistry {
    int32_t time_t_control_cycle_limit_us;
    uint32_t time_t_last_cycle_end_us;
    uint64_t last_transition_ccno;
    bool has_imu_linear_acc_vec_f;
    SFVector3f imu_linear_acc_vec_f;
    bool has_imu_acc_vec_f;
    SFVector3f imu_acc_vec_f; /* Why is there an _f??? */
    bool has_imu_gyr_vec;
    SFVector3f imu_gyr_vec;
    bool has_imu_euler_vec;
    SFVector4f imu_euler_vec;
    bool has_imu_quat;
    SFVector4f imu_quat;
    float fin_py_cmd;
    float fin_ny_cmd;
    float fin_px_cmd;
    float fin_nx_cmd;
    float lower_motor_cmd;
    /* [[[cog
import psrc.sfr_gen.sfr_gen as sfr_gen
sfr_gen.proto_generate_all()
]]] */
    float time_t_average_cycle_time_us;
    uint64_t mcl_control_cycle_num;
    int32_t mc_state;
    int32_t target_mc_state;
    int32_t gnc_state;
    int32_t target_gnc_state;
    bool has_imu_linear_acc;
    SFVector3f imu_linear_acc;
    bool has_imu_acc;
    SFVector3f imu_acc;
    bool has_imu_gyr_acc;
    SFVector3f imu_gyr_acc;
    bool has_gnc_global_target_error_f;
    SFVector3f gnc_global_target_error_f;
    bool has_gnc_global_target_pos_f;
    SFVector3f gnc_global_target_pos_f;
    bool has_gnc_global_linear_pos_f;
    SFVector3f gnc_global_linear_pos_f;
    bool has_gnc_global_linear_vel_f;
    SFVector3f gnc_global_linear_vel_f;
    bool has_gnc_global_linear_acc_f;
    SFVector3f gnc_global_linear_acc_f;
    bool has_gnc_global_quat;
    SFVector3f gnc_global_quat;
    bool has_gnc_euler_angles;
    SFVector3f gnc_euler_angles;
    bool has_sim_global_linear_pos_f;
    SFVector3f sim_global_linear_pos_f;
    bool has_sim_global_linear_vel_f;
    SFVector3f sim_global_linear_vel_f;
    bool has_sim_global_linear_acc_f;
    SFVector3f sim_global_linear_acc_f;
    bool has_sim_global_quat;
    SFVector3f sim_global_quat;
    bool has_sim_euler_angles;
    SFVector3f sim_euler_angles; /* [[[end]]] */
} StateFieldRegistry;


#ifdef __cplusplus
extern "C" {
#endif

/* Initializer values for message structs */
#define SFVector3f_init_default                  {{{NULL}, NULL}}
#define SFVector4f_init_default                  {{{NULL}, NULL}}
#define StateFieldRegistry_init_default          {0, 0, 0, false, SFVector3f_init_default, false, SFVector3f_init_default, false, SFVector3f_init_default, false, SFVector4f_init_default, false, SFVector4f_init_default, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, false, SFVector3f_init_default, false, SFVector3f_init_default, false, SFVector3f_init_default, false, SFVector3f_init_default, false, SFVector3f_init_default, false, SFVector3f_init_default, false, SFVector3f_init_default, false, SFVector3f_init_default, false, SFVector3f_init_default, false, SFVector3f_init_default, false, SFVector3f_init_default, false, SFVector3f_init_default, false, SFVector3f_init_default, false, SFVector3f_init_default, false, SFVector3f_init_default}
#define SFVector3f_init_zero                     {{{NULL}, NULL}}
#define SFVector4f_init_zero                     {{{NULL}, NULL}}
#define StateFieldRegistry_init_zero             {0, 0, 0, false, SFVector3f_init_zero, false, SFVector3f_init_zero, false, SFVector3f_init_zero, false, SFVector4f_init_zero, false, SFVector4f_init_zero, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, false, SFVector3f_init_zero, false, SFVector3f_init_zero, false, SFVector3f_init_zero, false, SFVector3f_init_zero, false, SFVector3f_init_zero, false, SFVector3f_init_zero, false, SFVector3f_init_zero, false, SFVector3f_init_zero, false, SFVector3f_init_zero, false, SFVector3f_init_zero, false, SFVector3f_init_zero, false, SFVector3f_init_zero, false, SFVector3f_init_zero, false, SFVector3f_init_zero, false, SFVector3f_init_zero}

/* Field tags (for use in manual encoding/decoding) */
#define SFVector3f_elements_tag                  1
#define SFVector4f_elements_tag                  1
#define StateFieldRegistry_time_t_control_cycle_limit_us_tag 2
#define StateFieldRegistry_time_t_last_cycle_end_us_tag 3
#define StateFieldRegistry_last_transition_ccno_tag 4
#define StateFieldRegistry_imu_linear_acc_vec_f_tag 10
#define StateFieldRegistry_imu_acc_vec_f_tag     11
#define StateFieldRegistry_imu_gyr_vec_tag       12
#define StateFieldRegistry_imu_euler_vec_tag     13
#define StateFieldRegistry_imu_quat_tag          14
#define StateFieldRegistry_fin_py_cmd_tag        16
#define StateFieldRegistry_fin_ny_cmd_tag        17
#define StateFieldRegistry_fin_px_cmd_tag        18
#define StateFieldRegistry_fin_nx_cmd_tag        19
#define StateFieldRegistry_lower_motor_cmd_tag   20
#define StateFieldRegistry_time_t_average_cycle_time_us_tag 21
#define StateFieldRegistry_mcl_control_cycle_num_tag 22
#define StateFieldRegistry_mc_state_tag          23
#define StateFieldRegistry_target_mc_state_tag   24
#define StateFieldRegistry_gnc_state_tag         25
#define StateFieldRegistry_target_gnc_state_tag  26
#define StateFieldRegistry_imu_linear_acc_tag    27
#define StateFieldRegistry_imu_acc_tag           28
#define StateFieldRegistry_imu_gyr_acc_tag       29
#define StateFieldRegistry_gnc_global_target_error_f_tag 30
#define StateFieldRegistry_gnc_global_target_pos_f_tag 31
#define StateFieldRegistry_gnc_global_linear_pos_f_tag 32
#define StateFieldRegistry_gnc_global_linear_vel_f_tag 33
#define StateFieldRegistry_gnc_global_linear_acc_f_tag 34
#define StateFieldRegistry_gnc_global_quat_tag   35
#define StateFieldRegistry_gnc_euler_angles_tag  36
#define StateFieldRegistry_sim_global_linear_pos_f_tag 37
#define StateFieldRegistry_sim_global_linear_vel_f_tag 38
#define StateFieldRegistry_sim_global_linear_acc_f_tag 39
#define StateFieldRegistry_sim_global_quat_tag   40
#define StateFieldRegistry_sim_euler_angles_tag  41

/* Struct field encoding specification for nanopb */
#define SFVector3f_FIELDLIST(X, a) \
X(a, CALLBACK, REPEATED, FLOAT,    elements,          1)
#define SFVector3f_CALLBACK pb_default_field_callback
#define SFVector3f_DEFAULT NULL

#define SFVector4f_FIELDLIST(X, a) \
X(a, CALLBACK, REPEATED, FLOAT,    elements,          1)
#define SFVector4f_CALLBACK pb_default_field_callback
#define SFVector4f_DEFAULT NULL

#define StateFieldRegistry_FIELDLIST(X, a) \
X(a, STATIC,   SINGULAR, INT32,    time_t_control_cycle_limit_us,   2) \
X(a, STATIC,   SINGULAR, UINT32,   time_t_last_cycle_end_us,   3) \
X(a, STATIC,   SINGULAR, UINT64,   last_transition_ccno,   4) \
X(a, STATIC,   OPTIONAL, MESSAGE,  imu_linear_acc_vec_f,  10) \
X(a, STATIC,   OPTIONAL, MESSAGE,  imu_acc_vec_f,    11) \
X(a, STATIC,   OPTIONAL, MESSAGE,  imu_gyr_vec,      12) \
X(a, STATIC,   OPTIONAL, MESSAGE,  imu_euler_vec,    13) \
X(a, STATIC,   OPTIONAL, MESSAGE,  imu_quat,         14) \
X(a, STATIC,   SINGULAR, FLOAT,    fin_py_cmd,       16) \
X(a, STATIC,   SINGULAR, FLOAT,    fin_ny_cmd,       17) \
X(a, STATIC,   SINGULAR, FLOAT,    fin_px_cmd,       18) \
X(a, STATIC,   SINGULAR, FLOAT,    fin_nx_cmd,       19) \
X(a, STATIC,   SINGULAR, FLOAT,    lower_motor_cmd,  20) \
X(a, STATIC,   SINGULAR, FLOAT,    time_t_average_cycle_time_us,  21) \
X(a, STATIC,   SINGULAR, UINT64,   mcl_control_cycle_num,  22) \
X(a, STATIC,   SINGULAR, INT32,    mc_state,         23) \
X(a, STATIC,   SINGULAR, INT32,    target_mc_state,  24) \
X(a, STATIC,   SINGULAR, INT32,    gnc_state,        25) \
X(a, STATIC,   SINGULAR, INT32,    target_gnc_state,  26) \
X(a, STATIC,   OPTIONAL, MESSAGE,  imu_linear_acc,   27) \
X(a, STATIC,   OPTIONAL, MESSAGE,  imu_acc,          28) \
X(a, STATIC,   OPTIONAL, MESSAGE,  imu_gyr_acc,      29) \
X(a, STATIC,   OPTIONAL, MESSAGE,  gnc_global_target_error_f,  30) \
X(a, STATIC,   OPTIONAL, MESSAGE,  gnc_global_target_pos_f,  31) \
X(a, STATIC,   OPTIONAL, MESSAGE,  gnc_global_linear_pos_f,  32) \
X(a, STATIC,   OPTIONAL, MESSAGE,  gnc_global_linear_vel_f,  33) \
X(a, STATIC,   OPTIONAL, MESSAGE,  gnc_global_linear_acc_f,  34) \
X(a, STATIC,   OPTIONAL, MESSAGE,  gnc_global_quat,  35) \
X(a, STATIC,   OPTIONAL, MESSAGE,  gnc_euler_angles,  36) \
X(a, STATIC,   OPTIONAL, MESSAGE,  sim_global_linear_pos_f,  37) \
X(a, STATIC,   OPTIONAL, MESSAGE,  sim_global_linear_vel_f,  38) \
X(a, STATIC,   OPTIONAL, MESSAGE,  sim_global_linear_acc_f,  39) \
X(a, STATIC,   OPTIONAL, MESSAGE,  sim_global_quat,  40) \
X(a, STATIC,   OPTIONAL, MESSAGE,  sim_euler_angles,  41)
#define StateFieldRegistry_CALLBACK NULL
#define StateFieldRegistry_DEFAULT NULL
#define StateFieldRegistry_imu_linear_acc_vec_f_MSGTYPE SFVector3f
#define StateFieldRegistry_imu_acc_vec_f_MSGTYPE SFVector3f
#define StateFieldRegistry_imu_gyr_vec_MSGTYPE SFVector3f
#define StateFieldRegistry_imu_euler_vec_MSGTYPE SFVector4f
#define StateFieldRegistry_imu_quat_MSGTYPE SFVector4f
#define StateFieldRegistry_imu_linear_acc_MSGTYPE SFVector3f
#define StateFieldRegistry_imu_acc_MSGTYPE SFVector3f
#define StateFieldRegistry_imu_gyr_acc_MSGTYPE SFVector3f
#define StateFieldRegistry_gnc_global_target_error_f_MSGTYPE SFVector3f
#define StateFieldRegistry_gnc_global_target_pos_f_MSGTYPE SFVector3f
#define StateFieldRegistry_gnc_global_linear_pos_f_MSGTYPE SFVector3f
#define StateFieldRegistry_gnc_global_linear_vel_f_MSGTYPE SFVector3f
#define StateFieldRegistry_gnc_global_linear_acc_f_MSGTYPE SFVector3f
#define StateFieldRegistry_gnc_global_quat_MSGTYPE SFVector3f
#define StateFieldRegistry_gnc_euler_angles_MSGTYPE SFVector3f
#define StateFieldRegistry_sim_global_linear_pos_f_MSGTYPE SFVector3f
#define StateFieldRegistry_sim_global_linear_vel_f_MSGTYPE SFVector3f
#define StateFieldRegistry_sim_global_linear_acc_f_MSGTYPE SFVector3f
#define StateFieldRegistry_sim_global_quat_MSGTYPE SFVector3f
#define StateFieldRegistry_sim_euler_angles_MSGTYPE SFVector3f

extern const pb_msgdesc_t SFVector3f_msg;
extern const pb_msgdesc_t SFVector4f_msg;
extern const pb_msgdesc_t StateFieldRegistry_msg;

/* Defines for backwards compatibility with code written before nanopb-0.4.0 */
#define SFVector3f_fields &SFVector3f_msg
#define SFVector4f_fields &SFVector4f_msg
#define StateFieldRegistry_fields &StateFieldRegistry_msg

/* Maximum encoded size of messages (where known) */
/* SFVector3f_size depends on runtime parameters */
/* SFVector4f_size depends on runtime parameters */
/* StateFieldRegistry_size depends on runtime parameters */

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif
