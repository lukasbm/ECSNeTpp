#include "ISourceEventRateDistribution.h"

namespace ecsnetpp
{

    double ISourceEventRateDistribution::getMessageDelay()
    {
        throw new cRuntimeError("Source event rate distribution function is not implemented.");
    }
} /* namespace ecsnetpp */
