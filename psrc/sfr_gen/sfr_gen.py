from dataclasses import dataclass
from enum import Enum
import cog

class SfrType(Enum):
    FLOAT_T = 0
    I32_T = 1
    U32_T = 2
    U64_T = 3
    MC_STATE_T = 4
    GNC_STATE_T = 5
    LIN_VECTOR3F_T = 6
    LIN_VECTOR4F_T = 7

sfr_to_proto = {
    SfrType.FLOAT_T: 'float',
    SfrType.I32_T: 'int32',
    SfrType.U32_T: 'uint32',
    SfrType.U64_T: 'uint64',
    SfrType.MC_STATE_T: 'int32',
    SfrType.GNC_STATE_T: 'int32',
    SfrType.LIN_VECTOR4F_T: 'SFVector4f',
    SfrType.LIN_VECTOR3F_T: 'SFVector3f'
}

sfr_to_header = {
    SfrType.FLOAT_T: 'float',
    SfrType.I32_T: 'int32_t',
    SfrType.U32_T: 'uint32_t',
    SfrType.U64_T: 'uint64_t',
    SfrType.MC_STATE_T: 'MainControl::State',
    SfrType.GNC_STATE_T: 'GncControl::State',
    SfrType.LIN_VECTOR4F_T: 'lin::Vector4f',
    SfrType.LIN_VECTOR3F_T: 'lin::Vector3f'
}

@dataclass
class SfrItem():
    type: SfrType
    name: str
    cpp_downlink_func_bind: str
    disable_telem: bool = False

SINGLE_ITEM_LIST = [
    SfrItem(
        SfrType.FLOAT_T,
        'time_t_average_cycle_time_us',
        None
    ),
    SfrItem(
        SfrType.U32_T,
        'mcl_control_cycle_num',
        None
    ),
    SfrItem(
        SfrType.U32_T,
        'mcl_now_ts_ms',
        None
    ),
    SfrItem(
        SfrType.MC_STATE_T,
        'mc_state',
        None
    ),
    SfrItem(
        SfrType.MC_STATE_T,
        'target_mc_state',
        None
    ),
    SfrItem(
        SfrType.GNC_STATE_T,
        'gnc_state',
        None
    ),
    SfrItem(
        SfrType.GNC_STATE_T,
        'target_gnc_state',
        None
    ),
    SfrItem(
        SfrType.U32_T,
        'packed_imu_state',
        None
    ),
    SfrItem(
        SfrType.I32_T,
        'fin_py_cmd',
        None
    ),
    SfrItem(
        SfrType.I32_T,
        'fin_ny_cmd',
        None
    ),
    SfrItem(
        SfrType.I32_T,
        'fin_px_cmd',
        None
    ),
    SfrItem(
        SfrType.I32_T,
        'fin_nx_cmd',
        None
    )
]
DISABLE_SIM_TELEM = True
VEC_ITEM_LIST = [
    SfrItem(
        SfrType.LIN_VECTOR3F_T,
        'zero_vec',
        'lin_link_downlink_sfr',
    ),
    SfrItem(
        SfrType.LIN_VECTOR3F_T,
        'imu_linear_acc',
        'lin_link_downlink_sfr',
    ),
    SfrItem(
        SfrType.LIN_VECTOR3F_T,
        'imu_acc',
        'lin_link_downlink_sfr',
    ),
    SfrItem(
        SfrType.LIN_VECTOR3F_T,
        'imu_gyr_acc',
        'lin_link_downlink_sfr',
    ),
    SfrItem(
        SfrType.LIN_VECTOR3F_T,
        'imu_euler_vec',
        'lin_link_downlink_sfr',
    ),
    SfrItem(
        SfrType.LIN_VECTOR4F_T,
        'imu_quat',
        'lin_link_downlink_sfr',
    ),
    SfrItem(
        SfrType.LIN_VECTOR4F_T,
        'gnc_orientation_target_quat',
        'lin_link_downlink_sfr',
    ),
    SfrItem(
        SfrType.LIN_VECTOR3F_T,
        'gnc_orientation_error_deg',
        'lin_link_downlink_sfr',
    ),
    SfrItem(
        SfrType.LIN_VECTOR3F_T,
        'gnc_global_target_error',
        'lin_link_downlink_sfr',
        disable_telem=True
    ),
    SfrItem(
        SfrType.LIN_VECTOR3F_T,
        'gnc_global_target_pos',
        'lin_link_downlink_sfr',
        disable_telem=False
    ),
    SfrItem(
        SfrType.LIN_VECTOR3F_T,
        'state_global_pos',
        'lin_link_downlink_sfr'
    ),
    SfrItem(
        SfrType.LIN_VECTOR3F_T,
        'state_global_vel',
        'lin_link_downlink_sfr'
    ),
    SfrItem(
        SfrType.LIN_VECTOR3F_T,
        'state_global_acc',
        'lin_link_downlink_sfr'
    ),
    SfrItem(
        SfrType.LIN_VECTOR3F_T,
        'state_euler_vec',
        'lin_link_downlink_sfr'
    ),
    SfrItem(
        SfrType.LIN_VECTOR3F_T,
        'gnc_target_global_acc',
        'lin_link_downlink_sfr'
    ),
    SfrItem(
        SfrType.LIN_VECTOR4F_T,
        'gnc_global_quat',
        'lin_link_downlink_sfr'
    ),
    SfrItem(
        SfrType.LIN_VECTOR3F_T,
        'gnc_euler_angles',
        'lin_link_downlink_sfr'
    ),
    SfrItem(
        SfrType.LIN_VECTOR3F_T,
        'sim_global_linear_pos',
        'lin_link_downlink_sfr',
        disable_telem=DISABLE_SIM_TELEM
    ),
    SfrItem(
        SfrType.LIN_VECTOR3F_T,
        'sim_global_linear_vel',
        'lin_link_downlink_sfr',
        disable_telem=DISABLE_SIM_TELEM

    ),
    SfrItem(
        SfrType.LIN_VECTOR3F_T,
        'sim_global_linear_acc',
        'lin_link_downlink_sfr',
        disable_telem=DISABLE_SIM_TELEM
    ),
    SfrItem(
        SfrType.LIN_VECTOR4F_T,
        'sim_global_quat',
        'lin_link_downlink_sfr',
        disable_telem=DISABLE_SIM_TELEM
    ),
    SfrItem(
        SfrType.LIN_VECTOR3F_T,
        'sim_euler_angles',
        'lin_link_downlink_sfr',
        disable_telem=DISABLE_SIM_TELEM
    )
]
ITEM_LIST = SINGLE_ITEM_LIST + VEC_ITEM_LIST

def downlink_generate_output(item: SfrItem):
    if item.disable_telem:
        return

    if item.cpp_downlink_func_bind is not None:
        cog.outl(f'{item.cpp_downlink_func_bind}(state_field_registry.{item.name},')
        cog.outl(f'                      state_field_registry.has_{item.name},')
        cog.outl(f'                      &sfr_.{item.name});')
    else:
        cog.outl(f'state_field_registry.{item.name} = sfr_.{item.name};')

def downlink_generate_all_output():
    for item in ITEM_LIST:
        downlink_generate_output(item)

def header_gen(item: SfrItem):
    cog.outl(f'{sfr_to_header[item.type]} {item.name}{{}};')

def header_gen_all():
    for item in ITEM_LIST:
        header_gen(item)

def proto_generate(item: SfrItem, x: int):
    cog.outl(f'{sfr_to_proto[item.type]} {item.name} = {x};')

def proto_generate_all():
    x = 21
    for item in ITEM_LIST:
        proto_generate(item, x)
        x += 1

def py_generate_vec(item: SfrItem):
    if item.type == SfrType.LIN_VECTOR3F_T:
        cog.outl(f'if len(sfr.{item.name}.elements) > 0:')
        cog.outl(f'    points.append(vec_measurement(sfr.{item.name}, \'{item.name}\', time_point))')
    elif item.type == SfrType.LIN_VECTOR4F_T:
        cog.outl(f'if len(sfr.{item.name}.elements) > 0:')
        cog.outl(f'    points.append(quat_measurement(sfr.{item.name}, \'{item.name}\', time_point))')
    else:
        raise RuntimeError("unexpected type!")

def py_generate_all():
    for item in VEC_ITEM_LIST:
        py_generate_vec(item)
    for item in SINGLE_ITEM_LIST:
        cog.outl(f'point.field("{item.name}", sfr.{item.name})')
        