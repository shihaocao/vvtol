from dataclasses import dataclass
from enum import Enum
import cog

class SfrType(Enum):
    # FLOAT_T = 0
    # I32_T = 1
    # U32_T = 2
    # U64_T = 3
    # MC_STATE_T = 4
    # GNC_STATE_T = 5
    LIN_VECTOR3F_T = 6

@dataclass
class SfrItem():
    type: SfrType
    name: str
    cpp_downlink_func_bind: str

ITEM_LIST = [
    SfrItem(
        SfrType.LIN_VECTOR3F_T,
        'global_coords',
        'lin_link_downlink_sfr'
    )
]

def downlink_generate_output(item: SfrItem):
    cog.outl(f'{item.cpp_downlink_func_bind}(state_field_registry.{item.name},')
    cog.outl(f'                      state_field_registry.has_{item.name},')
    cog.outl(f'                      &sfr_.{item.name});')

def downlink_generate_all_output():
    for item in ITEM_LIST:
        downlink_generate_output(item)