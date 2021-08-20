#include "RoundRobinCpuCoreScheduler.h"

namespace ecsnetpp
{

    Define_Module(RoundRobinCpuCoreScheduler);

    void RoundRobinCpuCoreScheduler::initialize()
    {
        cpuCores = getAncestorPar("cores").longValue();
    }

    long RoundRobinCpuCoreScheduler::getNextCPUCoreIndex()
    {
        lastCPUIndex = ((lastCPUIndex + 1) % cpuCores);
        //    std::cout << "Selecting the core: " << lastCPUIndex << " at : " << getParentModule()->getFullPath() << endl;
        return lastCPUIndex;
    }

} /* namespace ecsnetpp */
