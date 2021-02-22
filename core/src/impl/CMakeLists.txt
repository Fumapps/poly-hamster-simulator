include(CMakeListsImpl.cmake)
message("gen-src" ${IMPL_GEN_SRCS})
set(IMPL_SRCS ${IMPL_SRCS}
    "core/src/impl/MpwFrameworkCore.h"
    "core/src/impl/CompositeCommandBase.cpp"
    "core/src/impl/CompositeCommandBase.h"
    "core/src/impl/GameViewPresenterBase.cpp"
    "core/src/impl/GameViewPresenterBase.h"
    ${IMPL_GEN_SRCS}
    PARENT_SCOPE)
    