#include "ICpuCoreScheduler.h"

namespace ecsnetpp
{

    Define_Module(ICpuCoreScheduler)

        long ICpuCoreScheduler::getNextCPUCoreIndex()
    {
        throw new cRuntimeError("A CPU scheduler is not assigned to get the next CPU core index.");
    }

} /* namespace ecsnetpp */
