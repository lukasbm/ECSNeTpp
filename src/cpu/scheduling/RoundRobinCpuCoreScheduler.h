#ifndef CPU_SCHEDULING_ROUNDROBINCPUCORESCHEDULER_H_
#define CPU_SCHEDULING_ROUNDROBINCPUCORESCHEDULER_H_

#include <omnetpp.h>
#include "ICpuCoreScheduler.h"

using namespace omnetpp;

namespace ecsnetpp
{

  class RoundRobinCpuCoreScheduler : public ICpuCoreScheduler
  {
  private:
    long cpuCores;
    long lastCPUIndex = 0;

  protected:
    virtual void initialize() override;

  public:
    virtual long getNextCPUCoreIndex() override;
  };

} /* namespace ecsnetpp */

#endif /* CPU_SCHEDULING_ROUNDROBINCPUCORESCHEDULER_H_ */
