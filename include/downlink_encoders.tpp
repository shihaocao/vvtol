#pragma once

template <class LinType>
bool encode_lin_float_array(pb_ostream_t *stream, const pb_field_t *field, void *const *arg)
{
    // Retrieve the array passed as 'arg'
    const LinType *array_p = static_cast<LinType *>(*arg);
    const LinType &array = *array_p;
    // Write each float element to the stream
    for (int i = 0; i < 3; i++)
    {
        const float element = array[i];
        if (!pb_encode_tag_for_field(stream, field))
        {
            return false; // Encoding failure: unable to write the tag
        }

        if (!pb_encode_fixed32(stream, &element))
        {
            return false; // Encoding failure: unable to write the float value
        }
    }

    return true; // Encoding successful
}

template <class SfType, class LinType>
static void lin_link_downlink_sfr(SfType &field, bool &has_field, LinType *sfr_field_addr)
{
    field.elements.arg = sfr_field_addr;
    field.elements.funcs.encode = encode_lin_float_array<LinType>;
    has_field = true;
}
