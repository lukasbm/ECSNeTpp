#ifndef CPU_SCHEDULING_ICPUCORESCHEDULER_H_
#define CPU_SCHEDULING_ICPUCORESCHEDULER_H_
#include <omnetpp.h>

using namespace omnetpp;

namespace ecsnetpp
{

    class ICpuCoreScheduler : public cSimpleModule
    {
    protected:
        virtual void initialize(){};

    public:
        virtual long getNextCPUCoreIndex();
    };

} /* namespace ecsnetpp */

#endif /* CPU_SCHEDULING_ICPUCORESCHEDULER_H_ */
