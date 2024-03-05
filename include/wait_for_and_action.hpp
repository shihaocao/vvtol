// copyright shihao cao 2024 hahaha
#pragma once

#define WAIT_FOR_AND_ACTION(condition, action) \
    do { \
        static bool reached_##__LINE__ = false; \
        if (!reached_##__LINE__ && (condition)) { \
            action; \
            reached_##__LINE__ = true; \
        } \
        if (!reached_##__LINE__) return false; \
    } while (0)